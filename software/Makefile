# Project Name
PROJECT = FanPacer

# MCU and Programmer settings
MCU = attiny85
PROGRAMMER = tigard

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Wall -Os -DF_CPU=1000000UL
LDFLAGS = -mmcu=$(MCU)
OBJ2HEX = avr-objcopy
AVRDUDE = avrdude
FUSEFLAGS = -U lfuse:w:0x62:m

# Files
SRC = main.c
OBJ = $(PROJECT).o
ELF = $(PROJECT).elf
HEX = $(PROJECT).hex

# Default target
all: $(HEX)

# Compile C code
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -o $(OBJ) $(SRC)

# Link object file to create ELF file
$(ELF): $(OBJ)
	$(CC) $(LDFLAGS) -o $(ELF) $(OBJ)

# Create hex file from ELF file
$(HEX): $(ELF)
	$(OBJ2HEX) -O ihex -R .eeprom $(ELF) $(HEX)

# Upload the hex file to the MCU and set the fuse bits
upload: $(HEX)
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -U flash:w:$(HEX):i $(FUSEFLAGS)

# Clean up build files
clean:
	rm -f $(OBJ) $(ELF) $(HEX)

.PHONY: all upload clean
