# Makefile for Ex3

# Define the compiler
CC = g++

# Define flags for compilation
CFLAGS = -Wall -O2 -std=c++17

# Define library and include directories
LIBDIR = ./
INCDIR = ./

# Define source files
SRC_MAIN = Ex3.main.cpp
SRC_LIBIMP = Ex3libimp.cpp

# Define executable files
EXEC_MAIN = Ex3.main

# Define dynamic library and object file
LIBEX3 = libEx3.so
LIBIMP_OBJ = Ex3libimp.o

# Target to build Ex3.main executable (using the dynamic library)
$(EXEC_MAIN): $(SRC_MAIN) $(LIBEX3)
	$(CC) $(CFLAGS) -I$(INCDIR) $< -L$(LIBDIR) -lEx3 -o $@

# Target to build dynamic library for Ex3
$(LIBEX3): $(LIBIMP_OBJ)
	$(CC) $(CFLAGS) -shared -o $@ $<

# Target to build the object file for the dynamic library
$(LIBIMP_OBJ): $(SRC_LIBIMP)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Target to clean up object files and other generated files
clean:
	rm -f $(EXEC_MAIN) $(LIBEX3) $(LIBIMP_OBJ)

# Phony targets
.PHONY: clean
