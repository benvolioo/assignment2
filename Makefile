CXX = g++
CXXFLAGS = -Wall
main: main.o digraph.o wdigraph.o
	$(CXX) main.o digraph.o wdigraph.o -o main
digraph.o: digraph.cpp digraph.h
	$(CXX) digraph.cpp -c 
wdigraph.o: wdigraph.cpp wdigraph.h
	$(CXX) wdigraph.cpp -c
main.o: main.cpp 
	$(CXX) main.cpp -c 






clean:
	rm -rf main main.o digraph digraph.o  a.out wdigraph.o