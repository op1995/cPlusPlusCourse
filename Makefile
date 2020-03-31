#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=PhoneticFinder.hpp
OBJECTS=PhoneticFinder.o

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

test2: TestCounter.o test2.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test2

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
