#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "request.h"
#include "employee.h"
#include "login.h"

using namespace std;

int main(){
    fm alice("alice", "f0001", "Financial Manager");
    fa fredrik("fredrik", "f0002", "Accountant");
    fa sophia("sophia", "f0003", "Accountant");
    pm jack("jack", "p0001", "Production Manager");
    sm natalie("natalie", "s0001", "Service Manager");
    pt tobias("tobias", "p0002", "Production Team");
    pt julia("julia", "p0003", "Production Team");
    initLogin(loginDatabase);
    if (alice.isRecordExist())
        cout << "record exist"<< endl;
    while(1){
        // input : name
        // Exception: "exit" will break the loop.
        string in1;
        cout << "\nChoose an actor: <Name>" << endl;
        cin >> in1;
        if (in1 == "alice"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "alice wants to...<action>" << endl;
            string in2;
            cin >> in2;
            while (in2 == "ls"){
                cout << "\nview: view financial request\n"
                    << "create: create financial task\n"
                    << "add: add feedback\n"
                    << "solve\n" <<  endl;
                cin >> in2;
            }
            if (in2 == "view"){
                alice.viewFinancialRequestStatus();
            }
            else if (in2 == "create"){
                string date, depart, projref, rsn, cmt;
                long amount;
                cout << "Project reference: ";
                cin >> projref;
                date = getFinancialRequest(projref)->getDate();
                depart = getFinancialRequest(projref)->getDepartment();
                rsn = getFinancialRequest(projref)->getReason();
                amount = getFinancialRequest(projref)->getAmount();
                alice.createFinancialTask(date, depart, projref, amount, rsn, cmt);
            }
            else if (in2 == "add"){
                string pref, feedback;
                cout << "Enter project reference: " << endl;
                cin >> pref;
                cin.ignore();
                cout << "Feedback: " << endl;
                getline(cin, feedback);
                cout << "feed back: "<< feedback << endl;
                alice.addFeedback(getFinancialRequest(pref), feedback);
            }
            else if (in2 == "solve"){
                string pref;
                cout << "Enter project reference: " ;
                cin >> pref;
                alice.solve(getFinancialRequest(pref));
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "fredrik"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "fredrik wants to...<action>" << endl;
            string in2;
            cin >> in2;
            while (in2 == "ls"){
                cout << "\nview: view financial task\n"
                    <<  endl;
                cin >> in2;
            }
            if (in2 == "view"){
                fredrik.viewFinancialTask();
            }
            else {
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "sophia"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "sophia wants to...<action>" << endl;
            string in2;
            cin >> in2;
            while (in2 == "ls"){
                cout << "\nview: view financial task\n"
                    <<  endl;
                cin >> in2;
            }
            if (in2 == "view"){
                sophia.viewFinancialTask();
            }
            else {
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "jack"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "jack wants to...<action>" << endl;
            string in2;
            cin >> in2;
            while (in2 == "ls"){
                cout << "\ncreate: create a new financial request\n"
                    << "view: view financial request status\n"
                    <<  endl;
                cin >> in2;
            }
            if (in2 == "create"){
                string date, depart, projref, rsn;
                long amount;
                cout << "Date: ";
                cin.ignore();
                getline(cin, date);
                depart = "Production";
                cout << "Project reference: ";
                cin >> projref;
                cout << "Amount: ";
                cin >> amount;
                cout << "Reason: ";
                cin >> rsn;
                jack.createFinancialRequest(date,  depart, projref, amount, rsn);
            }
            else if (in2 == "view"){
                jack.viewFinancialRequestStatus();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "natalie"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "natalie wants to...<action>" << endl;
            string in2;
            cin >> in2;
            while (in2 == "ls"){
                cout << "\ncreate: create a new financial request\n"
                    << "view: view financial request status\n"
                    <<  endl;
                cin >> in2;
            }
            if (in2 == "create"){
                string date, depart, projref, rsn;
                long amount;
                cout << "Date: ";
                cin.ignore();
                getline(cin, date);
                depart = "Service";
                cout << "Project reference: ";
                cin >> projref;
                cout << "Amount: ";
                cin >> amount;
                cout << "Reason: ";
                cin >> rsn;
                natalie.createFinancialRequest(date,  depart, projref, amount, rsn);
            }
            else if (in2 == "view"){
                natalie.viewFinancialRequestStatus();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "tobias"){

        }
        else if (in1 == "exit"){
            return 0;
        }
        else {
            cout << "Wrong name or operation" << endl;
        }
    }
    return 0;
}
