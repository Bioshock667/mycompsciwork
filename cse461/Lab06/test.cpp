#include <iostream>
#include <string>
#include "shell.h"

using namespace std;

int main()
{
    Shell shell("shell.test", 128, 64);
    shell.add("file1");
    shell.type("file1");
}
