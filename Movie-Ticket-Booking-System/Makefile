CXX ?= g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude
TARGET = movie_booking
SOURCES = $(wildcard src/*.cpp)

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe
