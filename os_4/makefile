# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++17 -Wall -fprofile-arcs -ftest-coverage

# Target executable name
TARGET = dijkstra
TEST_TARGET = test_dijkstra

# Source files
SOURCES = Dijkstra.cpp
TEST_SOURCES = test_dijkstra.cpp Dijkstra.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

$(TEST_TARGET): $(TEST_SOURCES)
	$(CC) $(CFLAGS) -DTEST_DIJKSTRA -o $(TEST_TARGET) $(TEST_SOURCES)

gcov:
	gcov $(SOURCES)

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.gcda *.gcno *.gcov

.PHONY: all gcov clean