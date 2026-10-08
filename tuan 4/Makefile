TARGET = stm32_freertos

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
STFLASH = st-flash

CFLAGS = -mcpu=cortex-m3 \
         -mthumb \
         -O0 \
         -g \
         -Wall \
         -ffreestanding \
         -mfloat-abi=soft \
         -DSTM32F10X_MD \
         -I. \
         -Ifreertos/include

LDFLAGS = -T stm32f103c8.ld \
          -nostartfiles \
          -Wl,--gc-sections

SOURCES = main.c \
          startup.c \
          freertos/src/tasks.c \
          freertos/src/queue.c \
          freertos/src/list.c \
          freertos/src/port.c \
          freertos/src/heap_4.c

OBJECTS = $(SOURCES:%.c=build/%.o)

all: build/$(TARGET).bin

build/$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

build/$(TARGET).bin: build/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

flash: build/$(TARGET).bin
	$(STFLASH) --reset write $< 0x08000000

clean:
	rm -rf build

.PHONY: all flash clean
