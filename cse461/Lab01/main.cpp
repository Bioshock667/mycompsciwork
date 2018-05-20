#include "pFile.h"

int main()
{
 PasswordFile passfile("password.txt");
 passfile.addpw("dbotting","123qwe");
 passfile.addpw("egomez","qwerty");
 passfile.addpw("tongyu","liberty");
 // write some lines to see if passwords match users
}
