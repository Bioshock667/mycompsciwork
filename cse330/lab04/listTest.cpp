#include"list.h"
#include<iostream>

using namespace std;

int main()
{
    List<char> alpha;
    alpha.push_front('a');
    alpha.push_front('b');
    alpha.push_front('c');
    cout << alpha.front() << alpha.back() << endl;
}
