CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

TARGET_ELF = firmware.elf
TARGET_BIN = firmware.bin

MCU   = cortex-m4
FPU   = fpv4-sp-d16
FLOAT = hard

CFLAGS = \
	-mcpu=$(MCU) \
	-mthumb \
	-mfpu=$(FPU) \
	-mfloat-abi=$(FLOAT) \
	-Wall \
	-O0 \
	-g \
	-ffunction-sections \
	-fdata-sections \
	-DSTM32F446xx \
	-DUSE_HAL_DRIVER

LDFLAGS = \
	-T linker/STM32F446XX_FLASH.ld \
	-Wl,--gc-sections

INCLUDES = \
	-ICore/Inc \
	-Iinclude \
	-Iboard \
	-Iboard/stm32f446 \
	-Idrivers \
	-Iconfig \
	-Ihal/CMSIS/Core/Include \
	-Ihal/CMSIS/Device/ST/STM32F4xx/Include \
	-Ihal/STM32F4xx_HAL_Driver/Inc

SRC_APP = \
	app/main.c

SRC_BOARD = \
	board/stm32f446/board.c

SRC_CUBEMX = \
	Core/Src/system_stm32f4xx.c \
	Core/Src/stm32f4xx_it.c

SRC_HAL = \
	hal/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
	hal/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
	hal/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
	hal/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c

SRC_ARCH = \
	arch/arm/cortex-m4/startup_stm32f446xx.s

SRC_C = $(SRC_APP) $(SRC_BOARD) $(SRC_CUBEMX) $(SRC_HAL)
SRC_S = $(SRC_ARCH)

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.s=.o)
OBJS  = $(OBJ_C) $(OBJ_S)

all: $(TARGET_ELF) $(TARGET_BIN)

$(TARGET_ELF): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $< $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET_ELF) $(TARGET_BIN)
