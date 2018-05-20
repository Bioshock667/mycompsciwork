#ifndef SDISK_H
#define SDISK_H
#include <string>

class Sdisk
{
public :
Sdisk(std::string Diskname, int Numberofblocks, int Blocksize);
int getblock(int blocknumber, std::string& buffer);
int putblock(int blocknumber, std::string buffer);
private :
std::string diskname;        // file name of pseudo-disk
int numberofblocks;     // number of blocks on disk
int blocksize;          // block size in bytes
};
#endif
