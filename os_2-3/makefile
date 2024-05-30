CXX=g++

# Compiler flags, -g for debugging, -Wall for maximum warning, -lm for linking math library
CFLAGS=-g -Wall -lm

# Target executable names
TARGET1=Ex_1
TARGET2=main

all: $(TARGET1) $(TARGET2)

$(TARGET1): ex_1.cpp poisson.cpp
	$(CXX) $(CFLAGS) -o $(TARGET1) ex_1.cpp poisson.cpp
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

$(TARGET2): main.cpp libpoisson.so
	$(CXX) $(CFLAGS) -o $(TARGET2) main.cpp -L. -lpoisson

libpoisson.so: poisson.cpp Poisson.h
	$(CXX) -fPIC -shared -o libpoisson.so poisson.cpp

run: $(TARGET2)
	LD_LIBRARY_PATH=. ./$(TARGET2)

clean:
	rm -f *.so $(TARGET1) $(TARGET2)