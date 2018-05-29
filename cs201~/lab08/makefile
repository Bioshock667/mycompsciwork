run: graph
	./graph

plot.o: plot.h plot.cpp
	g++ -c plot.cpp

graph: plot.o graph.cpp
	g++ -o graph graph.cpp plot.o

clean:
	rm *.o
