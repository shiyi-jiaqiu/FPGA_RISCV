
BIN = test
CROSS = riscv-none-embed-

SRCS = \
  main.c \
  p_printf.c \
  spi.c	\
  timer.c\
  st7735.c
HDRS =\
  soc.h  \
  spi.h \
  timer.h\
  st7735.h 
CFLAGS += -W -Wall --std=gnu11 -Os
CFLAGS += -mabi=ilp32 -march=rv32imc
CFLAGS += -fdata-sections -ffunction-sections
CFLAGS += -funsigned-char -funsigned-bitfields
CFLAGS += -fno-diagnostics-show-caret
CFLAGS += -static -ffreestanding -nostartfiles
CFLAGS += -Wl,--script=linker.ld
CFLAGS += -flto

CFLAGS += \
  -DF_CPU=50000000

all: $(BIN).elf $(BIN).bin  size

$(BIN).elf: $(SRCS) $(HDRS)
	@echo CC
	@$(CROSS)gcc $(CFLAGS) $^ -o $@

$(BIN).bin: $(BIN).elf
	@echo OBJCOPY
	@$(CROSS)objcopy -O binary $^ $@



dump: $(BIN).elf
	@$(CROSS)objdump -Mnumeric -Mno-aliases -z -d $^

size: $(BIN).elf
	@echo size:
	@$(CROSS)size -t $^

clean:
	-rm $(BIN).elf $(BIN).bin 

