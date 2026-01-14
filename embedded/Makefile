# ==========================
# Toolchain
# ==========================
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy


# ==========================
# Output files
# ==========================
TARGET_ELF = firmware.elf
TARGET_BIN = firmware.bin


# ==========================
# MCU configuration
# ==========================
MCU   = cortex-m4
FPU   = fpv4-sp-d16
FLOAT = hard


# ==========================
# Compiler flags
# ==========================
CFLAGS = \
	-mcpu=$(MCU) \
	-mthumb \
	-mfpu=$(FPU) \
	-mfloat-abi=$(FLOAT) \
	-Wall \
	-O0 \
	-g \
	-ffunction-sections \
	-fdata-sections


# ==========================
# Linker flags
# ==========================
LDFLAGS = \
	-T embedded/linker/STM32F446RE_FLASH.ld \
	-Wl,--gc-sections


# ==========================
# Include paths
# ==========================
INCLUDES = \
	-Iembedded/board/stm32f446 \
	-Iembedded/hal/CMSIS/Core/Include \
	-Iembedded/hal/CMSIS/Device/ST/STM32F4xx/Include


# ==========================
# Source files
# ==========================
SRC_C = \
	embedded/app/main.c \
	embedded/board/stm32f446/board.c \
	embedded/hal/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c

SRC_S = \
	embedded/arch/arm/cortex-m4/startup_stm32f446xx.s


# ==========================
# Object files
# ==========================
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.s=.o)
OBJS  = $(OBJ_C) $(OBJ_S)


# ==========================
# Build rules
# ==========================
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
