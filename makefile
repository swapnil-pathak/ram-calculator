CC=gcc
CFLAGS=-g -O3 -fPIC -fno-builtin

all: check

default: check

clean:
        rm -rf *.o ram_calc

ram_calc: ram_calc.o
        $(CC) $(CFLAGS) $< -o $@

gdb_ram: ram_calc
        gdb ./ram_calc

%.o: %.c
        $(CC) $(CFLAGS) $< -c -o $@

check-ram: clean ram_calc
        ./ram_calc

check: clean ram_calc
        ./ram_calc
