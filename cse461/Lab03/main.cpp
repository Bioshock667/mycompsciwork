#include "fsystem.h"
#include <string>
using namespace std;
int main() {
    string filename("dis.txt");
    Filesys file(filename, 10, 12);
    return 0;
}