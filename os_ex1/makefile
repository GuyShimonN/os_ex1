CXX = g++
CXXFLAGS = -g -std=c++17

all: Division_by_Zero Overflow Uninitialized_Memory

Division_by_Zero: Division_by_Zero.o
	$(CXX) $(CXXFLAGS) -o Division_by_Zero Division_by_Zero.o

Division_by_Zero.o: Division_by_Zero.cpp
	$(CXX) $(CXXFLAGS) -c Division_by_Zero.cpp

Overflow: overflow.o
	$(CXX) $(CXXFLAGS) -o Overflow overflow.o

overflow.o: overflow.cpp
	$(CXX) $(CXXFLAGS) -c overflow.cpp

Uninitialized_Memory: Uninitialized_Memory.o
	$(CXX) $(CXXFLAGS) -o Uninitialized_Memory Uninitialized_Memory.o

Uninitialized_Memory.o: Uninitialized_Memory.cpp
	$(CXX) $(CXXFLAGS) -c Uninitialized_Memory.cpp

clean:
	rm -f *.o Division_by_Zero Overflow Uninitialized_Memory