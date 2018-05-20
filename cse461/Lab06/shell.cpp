///////////////////////////////////
//Name: Seth Lemanek
//Class: CSE461
//Date: Nov 16, 2015
//////////////////////////////////
#include "shell.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Shell::Shell(string filename, int blocksize, int numberofblocks):Filesys(filename, blocksize, numberofblocks)
{}


int Shell::dir()
{ 
    vector<string> flist = ls();
    if(flist.size() == 0)
    {
	cout << "File system is empty!\n";
	return 0;
    }
    for (int i=0; i<flist.size(); i++)
      {
        cout << flist[i] << endl;
      }
    return 1;
}

int Shell::add(string file)
{
    if(getfirstblock(file) >= 0 )
    {
	cout << "File: " << file << " already exists!\n";
	return 0;
    }
    newfile(file);
    char x = cin.get();
    string buffer;
    while( x != '^')
    {
	buffer += x;
	x = cin.get();
    }
    vector<string> content = block(buffer, getblocksize());
    for(int i = 0; i < content.size(); i++)
    {
	addblock(file, content[i]);
    }
    return 1;
}

int Shell::del(string file)
{
    int fblock = getfirstblock(file);
   if(fblock < 0)
     {
	cout << "File: " << file << " does not exist!\n";
	return 0;
    }
   if(fblock==0)
    {
	rmfile(file);
	return 1;
    }
    else
    {
	delblock(file, fblock);
	del(file);
    }
}

int Shell::type(string file)
{
    int nblock = getfirstblock(file);
    if(nblock < 0)
    {
	cout << "File: " << file << " does not exist!\n";
	return 0;
    }
    else if(nblock == 0)
    {
	cout << "File: " << file << " is empty!\n";
	return 0;
    }
    string buffer;
    readblock(file, nblock, buffer);
    cout << buffer;
    while(nextblock(file, nblock) != 0)
    {
	nblock = nextblock(file, nblock);
	readblock(file, nblock, buffer);
	cout << buffer;
    }
    cout << endl;
}

int Shell::copy(string file1, string file2)
{
    if(getfirstblock(file2) >= 0)
    {
	cout << "File: " << file2 << " already exists!\n";
	return 0;
    }
    int nblock = getfirstblock(file1);
    string buffer;
    newfile(file2);
    while(nblock != 0)
    {
	readblock(file1, nblock, buffer);
	addblock(file2, buffer); 
	nblock = nextblock(file1, nblock);
    }
}
