#ifndef FSYSTEM_H
#define FSTSTEM_H

#include "sdisk.h"
#include <string>
#include <vector>

using namespace std;

class Filesys: public Sdisk
{
    public :
	Filesys(string disk, int numberofblocks, int blocksize);
	int fsclose();
	int newfile(string file);
	int rmfile(string file);
	int getfirstblock(string file);
	int addblock(string file, string buffer);
	int delblock(string file, int blocknumber);
	int readblock(string file, int blocknumber, string& buffer);
	int writeblock(string file, int blocknumber, string buffer);
	int nextblock(string file, int blocknumber);
    private :
	int rootsize;           // maximum number of entries in ROOT
	int fatsize;            // number of blocks occupied by FAT
	int fssynch();
	vector<string> block(string buffer, int b);
	vector<string> filename;   // filenames in ROOT
	vector<int> firstblock; // firstblocks in ROOT
	vector<int> fat;             // FAT
};
#endif