/*

Adc and writing sound file into dma buffer. 
Using ADC1, (DMA2 stream0 channel0).

*/

#pragma once

#include "board.h" 

/* Change this based on needs!!  */
#define SAMPLING_RATE 44100

/* Audio buffers. */
/*
    Using double buffer dma because its for avoid wasting time 
    while reading analog input.

    These two start of memory addresses are given in the linker btw. 
*/
#define BUF_LENGTH_COUNT_16BIT ( (uint32_t)((&_audio_dma_end - &_audio_dma_start) / 2) )
extern uint8_t _audio_dma_start;
extern uint8_t _audio_dma_end;
extern uint16_t *audio_bufA, *audio_bufB;

/* Handles. */
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim2;

/* Funcs */
void Enable_ADC1_DMA2_TIM2_Clock(void);
void DMA_Init(uint8_t *audio_dma_start, uint16_t *audio_bufA, uint16_t *audio_bufB, DMA_HandleTypeDef *hdma_adcx, ADC_HandleTypeDef *hadcx);
void ADC1_DMA_Init(ADC_HandleTypeDef *hadcx); 
void TIM2_Sampling_Config(uint32_t sampling_rate, TIM_HandleTypeDef *htimx);
void Start_Data_Transmit(void); 
