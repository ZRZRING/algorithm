#include "usr.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string name1,name2,name3;
	int a,b,c;
	cin >> name1 >> a >> name2 >> b >> name3 >> c ;
    User *u1 = new User(name1,a);
    User *u2 = new User(name2,b);
    User::GetState();
    delete u1;
    u1 = new User(name3,c);
    User::GetState();
    delete u2;
	User::GetState();
    delete u1;
    User::GetState();
}