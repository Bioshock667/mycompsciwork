////////////////////////////////////////////////
//Programmer: Seth Lemanek
//Date: November 30, 2015
//CSE 461
//Prof. Owen Murphy
//Homework 4
///////////////////////////////////////////////
#include "dbase.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Table::Table(string diskname, int blocksize, int numberofblocks, string flatfile, string indexfile):Filesys(diskname, numberofblocks, blocksize)
{
    this->flatfile = flatfile;
    this->indexfile = indexfile;
    newfile(flatfile);
    newfile(indexfile);
    numberofrecords = 0;
}

int Table::Build_Table(string input_file)
{
    string testblock;
    int code = readblock(flatfile, getfirstblock(flatfile), testblock);
    if( code == 0)
     {
    	ifstream input;
    	input.open(input_file.c_str());
    	string r, pkey, buffer;
    	getline(input, r);
    	ostringstream indexbuffer;
    	while(r != "")
    	{
	pkey = r.substr(0, 5);
	vector <string> b = block(r, getblocksize());
	int code = addblock(flatfile, b[0]);
	numberofrecords ++;
	indexbuffer << pkey << " " << code << " ";
	getline(input, r);
    	}
	indexbuffer << "XXXXX 0 ";
    	buffer = indexbuffer.str();
    	vector <string> blocks = block(buffer, getblocksize());
    	for(int i = 0; i < blocks.size(); i++)
	    int code = addblock(indexfile, blocks[i]);
    }
      else
	cout << "Table already exists!\n";
}

int Table::Search(string value)
{
    int block = IndexSearch(value);
    string buffer;
    int code = readblock(flatfile, block, buffer);
    if(code > 0)
    {
	cout << buffer << endl;
	return 1;
    }
    else
    {
	cout << "Error: Entry not found!\n";
	return 0;
    }
}

int Table::IndexSearch(string value)
{
    string buffer1;
    int block = getfirstblock(indexfile);
    while(block != 0)
    {
	string b;
	int code = readblock(indexfile, block, b);
	buffer1 += b;
	block = nextblock(indexfile, block);
    }
    istringstream buffer2;
    buffer2.str(buffer1);
    string k;
    int b;
    buffer2 >> k >> b;
    while(b != 0)
    {
	if(k == value)
	    return b;
	buffer2 >> k >> b;
    }
    return -1;
}
