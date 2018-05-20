test: multiply
	./multiply
multiply:
	g++ -o multiply main.cpp multiply.o print.o
multiply.o:
	g++ -c multiply.cpp multiply.h
print.o:
	g++ -c print.cpp print.h
clean:
	rm *.o  *.gch
