#ifndef DBASE_H
#define DBASE_H
#include "fsystem.h"
#include <string>
class Table : public Filesys
{
    public :
	Table(std::string diskname,int blocksize,int numberofblocks, std::string flatfile, std::string indexfile);
	int Build_Table(std::string input_file);
	int Search(std::string value);
    private :
	std::string flatfile;
	std::string indexfile;
	int numberofrecords;
	int IndexSearch(std::string value);
};

#endif
