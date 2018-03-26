# ram-calculator

Building and running:
1. Run 'make clean' to remove any precompiled packages
2. Run 'make check-ram' to compile and run the program ram_calc.c

Alternatively,
Run 'make ram_calc' to build executable and then run './ram_calc' to run it.

In the above cases, a file 'memory_calculation' is generated. The last line of the file is the total RAM of the system. In case, the OOM killer kills the program, the aforementioned file can be referred to see the calculation result.
