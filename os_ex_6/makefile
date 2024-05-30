# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET1 = add2PB
TARGET2 = findphone
SOURCES1 = add2PB.cpp
SOURCES2 = findphone.cpp

# Default target
all: $(TARGET1) $(TARGET2)

# Linking
$(TARGET1): $(SOURCES1)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET2): $(SOURCES2)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Cleaning
clean:
	rm -f $(TARGET1) $(TARGET2)