#MakeFile for My Operating Systems Project phase3
#Written by Seth Lemanek 6/14/18

run: os_run
	./os_run

Assembler.o: Assembler.cpp Assembler.h
	g++ -c Assembler.cpp

entry.o: entry.cpp entry.h
	g++ -c entry.cpp

VirualMachine.o: VirtualMachine.cpp VirtualMachine.h entry.o
	g++ -c VirtualMachine.cpp entry.o

PCB.o: PCB.cpp PCB.h
	g++ -c PCB.cpp

os.o: os.cpp os.h VirtualMachine.o PCB.o
	g++ -c os.cpp VirtualMachine.o PCB.o

os_run: main.cpp os.o
	g++ -o os_run main.cpp os.o
clean: rm -f os.o VirtualMachine.o entry.o PCB.o
