#include "login.h"

string loginDatabase[login_size];

bool loginStatus[login_size];

void initLogin(string * log){
    for (int i = 0; i < login_size; i++){
        loginStatus[i] = false;
    }
    log[0] = "alice";   //fm
    log[1] = "fredrik"; //fa
    log[2] = "sophia";  //fa
    log[3] = "jack";    //pm
    log[4] = "natalie"; //sm
    log[5] = "tobias";  // pt
    log[6] = "julia";   // pt
    log[7] = "kate";    // st
    log[8] = "helen";   // st
    log[9] = "mike";    // am
    log[10] = "sarah";  // cs
    log[11] = "sam";    // cs
    log[12] = "janet";  // scs
    log[13] = "maria";  //hr
    log[14] = "simon";  //hrm
}

void do_not_need_login(){
    // assume already logged in
    for (int i = 0; i < login_size; i++){
        loginStatus[i] = true;
    }
}

bool checkLogin(string name){
    if (name == "") return false;
    else for (int i = 0; i < login_size; i++){
        if (loginDatabase[i] == name) return loginStatus[i];
    }
    return false;
}


void login(){
    string username, password;
    int index = -1;
    cout << "Please enter your username:" << endl;
    cin >> username;
    for (int i = 0; i < login_size; i++){
        if (loginDatabase[i] == username) index = i;
    }
    if (index == -1){
        cout << "Not valid username!" << endl;
        return;
    }
    cout << "Please enter your password:" << endl;
    cin >> password;
    if (username + "123" == password){
        loginStatus[index] = true;
        cout << "Login success!" << endl;
    }
    else {
        cout << "Wrong password!" << endl;
    }
    return;
}

