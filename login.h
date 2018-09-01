#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <iostream>
#define login_size 20

using namespace std;

extern string loginDatabase[login_size];

extern bool loginStatus[login_size];

void initLogin(string * log);

bool checkLogin(string name);

void login();

void do_not_need_login();


#endif // LOGIN_H
