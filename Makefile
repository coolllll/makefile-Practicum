MCU=atmega168
F_CPU=16000000
CFLAG=-mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJS=peri.o

.SECONDARY:

%.flash: %.hex
	avrdude -p $(MCU) -c usbasp -U flash:w:$<

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

%.elf: %.o $(OBJS)
	avr-gcc $(CFLAG) -o $@ $^
%.o: %.c
	avr-gcc $(CFLAG) -c -o $@ $<
