test: prodtest
	./prodtest
prodtest: prodtest.cpp product.o
	g++ -o prodtest prodtest.cpp product.o
product.o: product.cpp product.h
	g++ -c product.cpp

clean: 
	rm *.o prodtest
