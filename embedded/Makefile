# -------- Toolchain --------
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# -------- Target --------
TARGET  = firmware

# -------- MCU --------
MCU     = cortex-m4
FPU     = fpv4-sp-d16
FLOAT   = hard

CFLAGS  = -mcpu=$(MCU) -mthumb -mfpu=$(FPU) -mfloat-abi=$(FLOAT)
CFLAGS += -Wall -O0 -g
CFLAGS += -ffunction-sections -fdata-sections

LDFLAGS = -T embedded/linker/STM32F446RE_FLASH.ld
LDFLAGS += -Wl,--gc-sections

# -------- Includes --------
INCLUDES  = -Iembedded/board/stm32f446
INCLUDES += -Iembedded/hal/CMSIS/Core/Include
INCLUDES += -Iembedded/hal/CMSIS/Device/ST/STM32F4xx/Include

# -------- Sources --------
SRCS  = embedded/app/main.c
SRCS += embedded/board/stm32f446/board.c
SRCS += embedded/hal/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c
SRCS += embedded/arch/arm/cortex-m4/startup_stm32f446xx.s

# -------- Objects --------
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.s=.o)

# -------- Rules --------
all: $(TARGET).elf $(TARGET).bin

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin

