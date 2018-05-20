#ifndef PFILE_H
#define PFILE_H
#include <vector>
#include <string>

class PasswordFile
{
    public:
	PasswordFile(std::string filename);
	void addpw(std::string newuser, std::string newpassword);
	bool checkpw(std::string oUser, std::string oPassword);
    private:
	std::string filename;
	std::vector<std::string> user;
	std::vector<std::string> password;
	void synch();
	static int salt;
	void newSalt(int ns);
	std::string encrypt(std::string s);
};
#endif
