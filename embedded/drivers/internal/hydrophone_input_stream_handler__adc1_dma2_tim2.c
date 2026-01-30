#include "hydrophone_input_stream_handler__adc1_dma2_tim2.h"

uint16_t *audio_bufA = NULL;
uint16_t *audio_bufB = NULL;

/* Handles */
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
TIM_HandleTypeDef htim2;

/* Main function */
/* Handles can be changed here */
void Start_Data_Transmit(void) {
    Enable_ADC1_DMA2_TIM2_Clock();
    DMA_Init(&_audio_dma_start, audio_bufA, audio_bufB, &hdma_adc1, &hadc1);
    ADC1_DMA_Init(&hadc1);
    TIM2_Sampling_Config(SAMPLING_RATE, &htim2);

    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&_audio_dma_start, BUF_LENGTH_COUNT_16BIT);

    HAL_TIM_Base_Start(&htim2);
}

/* Enable all the clocks */
/* Clocks should be changed based on the handles  */
void Enable_ADC1_DMA2_TIM2_Clock(void) {
    __HAL_RCC_DMA2_CLK_ENABLE();
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_ADC1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

/* Giving the reserved space that we specified in the linker.  */
void DMA_Init(uint8_t *audio_dma_start, uint16_t *audio_bufA, uint16_t *audio_bufB, DMA_HandleTypeDef *hdma_adcx, ADC_HandleTypeDef *hadcx) {
    audio_bufA = (uint16_t*)&_audio_dma_start;
    /* Using unsigned char instead of uint8_t is common usage for memory adresses. */
    /* Unsigned char can be aliased to every type of object so using unsigned char is better.  */
    audio_bufB = (uint16_t*)((unsigned char*)audio_dma_start + AUDIO_BUF_SIZE);
    
    /* DMA config DMA2, Stream0, Channel0 */
    hdma_adcx->Instance = DMA2_Stream0;
    hdma_adcx->Init.Channel = DMA_CHANNEL_0;
    hdma_adcx->Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_adcx->Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_adcx->Init.MemInc = DMA_MINC_ENABLE;
    hdma_adcx->Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_adcx->Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_adcx->Init.Mode = DMA_CIRCULAR; // Ping-pong
    hdma_adcx->Init.Priority = DMA_PRIORITY_VERY_HIGH;
    hdma_adcx->Init.FIFOMode = DMA_FIFOMODE_DISABLE;

    HAL_DMA_Init(hdma_adcx);
    
    __HAL_LINKDMA(hadcx, DMA_Handle, *hdma_adcx);

    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, ADC__DMA2_Preempt, ADC__DMA2_Sub);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

/* IRQ Callback  */
void DMA2_Stream0_IRQHandler(void) {
    HAL_DMA_IRQHandler(&hdma_adc1);
}

/* audio_bufB complete.  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
    if(hadc->Instance == ADC1) {
        /* SDIO  */
    }    
}

/* audio_bufA complete.  */
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc) {
    if(hadc->Instance == ADC1) {
        /* SDIO  */
    }
}

/* Configuring adc for good quality sound data.  */
void ADC1_DMA_Init(ADC_HandleTypeDef *hadcx) {
    ADC_ChannelConfTypeDef sConfig = {0};
    
    /* ADC config ADC1  */
    hadcx->Instance = ADC1;
    hadcx->Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
    hadcx->Init.Resolution = ADC_RESOLUTION_12B;
    hadcx->Init.ScanConvMode = DISABLE;
    hadcx->Init.ContinuousConvMode = DISABLE;
    hadcx->Init.DiscontinuousConvMode = DISABLE;
    hadcx->Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
    hadcx->Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T2_TRGO; // TIM2 TRGO
    hadcx->Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadcx->Init.NbrOfConversion = 1;
    hadcx->Init.DMAContinuousRequests = ENABLE;           
    hadcx->Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    HAL_ADC_Init(hadcx);

    /* (PA0 - Hydrophone input) */
    sConfig.Channel = ADC_CHANNEL__ADC1;;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;     
    HAL_ADC_ConfigChannel(hadcx, &sConfig);
}

void TIM2_Sampling_Config(uint32_t sampling_rate, TIM_HandleTypeDef *htimx) {
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    /* F446RE APB1 Timer Clock 90MHz or 180MHz (depends on the setup). */
    /* Usually SystemClock is 180MHz and APB1 Timer is 90MHz.*/
    uint32_t timer_clock = 90000000; 

    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 0;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = (timer_clock / sampling_rate) - 1; 
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    HAL_TIM_Base_Init(&htim2);

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);
}
