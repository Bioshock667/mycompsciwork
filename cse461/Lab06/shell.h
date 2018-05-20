#ifndef SHELL_H
#define SHELL_H

#include "fsystem.h"
#include <string>

//using namespace std;

class Shell: public Filesys
{
    public :
	Shell(std::string filename, int blocksize, int numberofblocks);
	int dir();// lists all files
	int add(std::string file);// add a new file using input from the keyboard
	int del(std::string file);// deletes the file
	int type(std::string file);//lists the contents of file
	int copy(std::string file1, std::string file2);//copies file1 to file2
};
#endif
