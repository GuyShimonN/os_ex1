# Makefile for Ex4

# Define the compiler
CC = g++

# Define flags for compilation
CFLAGS = -Wall -O2 -std=c++17
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# Define source files
SRC_EX4 = Ex4.cpp

# Define executable files
EXEC_EX4 = Ex4

# Target to build Ex4 executable
$(EXEC_EX4): $(SRC_EX4)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $< -o $@

# Target to generate coverage report for Ex4
report: $(EXEC_EX4)
	./$(EXEC_EX4)
	gcov $(SRC_EX4)

# Target to clean up object files and other generated files
clean:
	rm -f $(EXEC_EX4) *.gcda *.gcno *.gcov

# Phony targets
.PHONY: clean report
