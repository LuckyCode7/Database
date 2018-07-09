CXX=g++
STD= -std=c++11
CXXFLAGS=-Wall -Wextra -Wpedantic 
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

%.o: %.cpp %.hpp
	$(CXX) $(STD) $(CXXFLAGS) -c -o $@ $<

students:$(OBJ)
	$(CXX) $(STD) $(CXXFLAGS) -o $@ $^

clean:
	rm students $(OBJ)
