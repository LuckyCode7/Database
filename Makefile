CXX = g++
STD = -std=c++11
CXXFLAGS = -Wall -Wpedantic -Wextra 
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = output

.PHONY: all
all: $(TARGET)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@   

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

.PHONY: clean
clean:
	rm $(TARGET) *.o
