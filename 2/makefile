# Makefile for Ex2

# Define the compiler
CC = g++

# Define flags for compilation
CFLAGS = -Wall -O2 -std=c++17

# Define source files
SRC_EX2 = Ex2.cpp

# Define executable files
EXEC_EX2 = Ex2

# Target to build Ex2 executable (explicit rule)
$(EXEC_EX2): $(SRC_EX2)
	$(CC) $(CFLAGS) $< -o $@

# Target to clean up object files and other generated files
clean:
	rm -f $(EXEC_EX2)

# Phony targets
.PHONY: clean
