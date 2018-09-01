#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "request.h"
#include "employee.h"
#include "login.h"
#include "service_production.h"

#define need_login 1
using namespace std;

int main(){
    fm alice("alice", "f0001", "Financial Manager");
    fa fredrik("fredrik", "f0002", "Accountant");
    fa sophia("sophia", "f0003", "Accountant");
    pm jack("jack", "p0001", "Production Manager");
    sm natalie("natalie", "s0001", "Service Manager");
    pt tobias("tobias", "p0002", "Production Team");
    pt julia("julia", "p0003", "Production Team");
    st helen("helen", "s0002", "Service Team");
    st kate("kate", "s0003", "Service Team");
    am mike("mike", "a0001", "Administration Manager");
    cs sarah("sarah", "a0005", "Customer Service");
    cs sam("sam", "a0006", "Customer Service");
    scs janet("janet", "a0002", "Senior Customer Service");
    hrm simon("simon", "a0003", "HR Manager");
    hr maria("maria", "a0004", "HR");
    init_resume();

    initLogin(loginDatabase);
    if (need_login == 0)
            do_not_need_login();

    while(1){
        // input : name
        // Exception: "exit" will break the loop.
        string in1;
        cout << "\nChoose an actor: <Name>" << endl;
        cin >> in1;
        if (in1 == "alice"){
        //alice
            if (!checkLogin(in1)){
                login();
            }
            cout << "alice wants to...<action>" << endl;
            string in2;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\nview-f: view financial request\n"
                    << "view-e: view event request\n"
                    << "create-t: create financial task\n"
                    << "add-e: add event request feedback\n"
                    << "add-f: add financial request feedback\n"
                    << "solve-f: solve financial request\n" <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "view-f"){
                alice.viewFinancialRequestStatus();
            }
            else if (in2 == "view-e"){
                alice.view_event_request();
            }
            else if (in2 == "add-e"){
                string pr, fb;
                cout << "Project reference: ";
                cin >> pr;
                cin.ignore();
                cout << "Feedback: " << endl;
                getline(cin, fb);
                alice.add_event_request_feedback(pr, fb);
            }
            else if (in2 == "create-t"){
                string date, depart, projref, rsn, cmt;
                long amount;
                cout << "Project reference: ";
                cin >> projref;
                cin.ignore();
                date = getFinancialRequest(projref)->getDate();
                depart = getFinancialRequest(projref)->getDepartment();
                rsn = getFinancialRequest(projref)->getReason();
                amount = getFinancialRequest(projref)->getAmount();
                alice.createFinancialTask(date, depart, projref, amount, rsn, cmt);
            }
            else if (in2 == "add-f"){
                string pref, feedback;
                cout << "Enter project reference: " << endl;
                cin >> pref;
                cin.ignore();
                cout << "Feedback: " << endl;
                getline(cin, feedback);
                cout << "feed back: "<< feedback << endl;
                alice.addFeedback(getFinancialRequest(pref), feedback);
            }
            else if (in2 == "solve-f"){
                string pref;
                cout << "Enter project reference: " ;
                cin >> pref;
                cin.ignore();
                alice.solve(getFinancialRequest(pref));
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "simon"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "simon wants to...<action>" << endl;
            string in2;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\nview: view all hr request"
                    << "\norder: order a hr request to an hr assistant"
                    <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "view"){
                simon.view_hr_req();
            }
            else if (in2 == "order"){
                string pr, depart, st;
                cout << "Project reference: " << endl;
                getline(cin, pr);
                cout << "Department: " << endl;
                getline(cin, depart);
                cout << "Send to: " << endl;
                getline(cin, st);
                simon.order_task(pr,depart, st);
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "maria"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "maria wants to...<action>" << endl;
            string in2;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\nview-all: view all hr requests sent to her"
                    << "\nview-r: view all resumes"
                    << "\nhire: recruit a person"
                    <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "view-all"){
                maria.view_hr_req();
            }
            else if (in2 == "hire"){
                string pr, depart, n;
                cout << "Project reference: " << endl;
                getline(cin, pr);
                cout << "Department: " << endl;
                getline(cin, depart);
                cout << "Hire: " << endl;
                getline(cin, n);
                maria.hire(pr, depart, n);
            }
            else if (in2 == "view-r"){
                maria.view_resume();
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
            cin.ignore();
            while (in2 == "ls"){
                cout << "\nview: view financial task\n"
                    <<  endl;
                cin >> in2;
                cin.ignore();
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
            cin.ignore();
            while (in2 == "ls"){
                cout << "\nview: view financial task\n"
                    <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "view"){
                sophia.viewFinancialTask();
            }
            else {
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "mike"){
            if (!checkLogin(in1)){
                login();
            }
            cout << "mike wants to...<action>" << endl;
            string in2;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\nview: view all unsettled event request\n"
                    << "appr: approve an event request\n"
                    << "rej: reject an event request\n"
                    <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "view"){
                mike.view_unsettled_event_request();
            }
            else if (in2 == "appr"){
                string pr;
                cout << "Project reference: " << endl;
                getline(cin, pr);
                mike.event_request_approve(pr);
            }
            else if (in2 == "rej"){
                string pr;
                cout << "Project reference: " << endl;
                getline(cin, pr);
                mike.event_request_reject(pr);
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
            cin.ignore();
            while (in2 == "ls"){
                cout << "\ncreate-f: create a new financial request\n"
                    << "view-f: view financial request status\n"
                    << "create-hr: create an hr request\n"
                    << "view-hr: view all hr request created by jack\n"
                    << "view-one: view one specific hr request by project reference\n"
                    << "create-t: create a new subteam task\n"
                    << "view-t: view production tasks\n"
                    << "view-p: view production subteam task plans\n"
                    << "appr: approve a task plan and give feedback\n"
                    << "rej: reject a task plan and give feedback\n"
                    <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create-f"){
                string date, depart, projref, rsn;
                long amount;
                cout << "Date: ";
                getline(cin, date);
                depart = "Production";
                cout << "Project reference: ";
                cin >> projref;
                cout << "Amount: ";
                cin >> amount;
                cout << "Reason: ";
                cin.ignore();
                getline(cin, rsn);
                jack.createFinancialRequest(date,  depart, projref, amount, rsn);
            }
            else if (in2 == "create-hr"){
                string dat, pr, requirement;
                int n;
                cout << "Date: " << endl;
                getline(cin, dat);
                cout << "Project reference: " << endl;
                getline(cin, pr);
                cout << "Recruitment number: " << endl;
                cin >> n;
                cin.ignore();
                cout << "Recruitment requirement: " << endl;
                getline(cin, requirement);
                jack.create_hr_request(dat, "Production", pr, n, requirement);
            }
            else if (in2 == "view-one"){
                string proj_f;
                cout << "Project reference: " << endl;
                getline(cin, proj_f);
                jack.view_hr_req(proj_f);
            }
            else if (in2 == "view-hr"){
                jack.view_all_hr_req();
            }
            else if (in2 == "create-t"){
                string date, depart, projref, send_to, detail;
                cout << "Date: ";
                getline(cin, date);
                depart = "Production";
                cout << "Project reference: ";
                cin >> projref;
                cout << "Send to: <name> ";
                cin >> send_to;
                cout << "Task details: ";
                cin.ignore();
                getline(cin, detail);
                jack.createProductionTask(date, depart, projref, detail, send_to);
            }
            else if (in2 == "view-f"){
                jack.viewFinancialRequestStatus();
            }
            else if (in2 == "view-t"){
                jack.view_subteam_task();
            }
            else if (in2 == "view-p"){
                jack.viewProductionTaskPlan();
            }
            else if (in2 == "appr"){
                string in3, in4;
                cout << "Please enter project reference: ";
                cin >> in3;
                cout << "Please enter creator name: ";
                cin >> in4;
                cin.ignore();
                subteam_task_plan *stp;
                if (stp = get_subteam_task_plan(in3, in4)){
                    cout << "Please enter feedback: ";
                    getline(cin, in3);
                    jack.approveProductionTaskPlan(stp, in3);
                }
                else{
                    cout << "Wrong project_reference or creator_name!" << endl;
                }
            }
            else if (in2 == "rej"){
                string in3, in4;
                cout << "Please enter project reference: ";
                cin.ignore();
                cin >> in3;
                cout << "Please enter creator name: ";
                cin >> in4;
                cin.ignore();
                subteam_task_plan *stp;
                if (stp = get_subteam_task_plan(in3, in4)){
                    cout << "Please enter feedback: ";
                    getline(cin, in3);
                    jack.rejectProductionTaskPlan(stp, in3);
                }
                else{
                    cout << "Wrong project_reference or creator_name!" << endl;
                }
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
            cin.ignore();
            while (in2 == "ls"){
                cout << "\ncreate-f: create a new financial request\n"
                    << "view-f: view financial request status\n"
                    << "create-hr: create an hr request\n"
                    << "view-hr: view all hr request created by jack\n"
                    << "view-one: view one specific hr request by project reference\n"
                    << "create-t: create a new subteam task\n"
                    << "view-t: view production tasks\n"
                    << "view-p: view production subteam task plans\n"
                    << "appr: approve a task plan and give feedback\n"
                    << "rej: reject a task plan and give feedback\n"
                    <<  endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create-f"){
                string date, depart, projref, rsn;
                long amount;
                cout << "Date: ";
                getline(cin, date);
                depart = "Service";
                cout << "Project reference: ";
                cin >> projref;
                cout << "Amount: ";
                cin >> amount;
                cout << "Reason: ";
                cin.ignore();
                getline(cin, rsn);
                natalie.createFinancialRequest(date,  depart, projref, amount, rsn);
            }
            else if (in2 == "create-t"){
                string date, depart, projref, send_to, detail;
                cout << "Date: ";
                getline(cin, date);
                depart = "Service";
                cout << "Project reference: ";
                cin >> projref;
                cout << "Send to: <name> ";
                cin >> send_to;
                cout << "Task details: ";
                cin.ignore();
                getline(cin, detail);
                natalie.createServiceTask(date, depart, projref, detail, send_to);
            }
            else if (in2 == "create-hr"){
                string dat, pr, requirement;
                int n;
                cout << "Date: " << endl;
                getline(cin, dat);
                cout << "Project reference: " << endl;
                getline(cin, pr);
                cout << "Recruitment number: " << endl;
                cin >> n;
                cin.ignore();
                cout << "Recruitment requirement: " << endl;
                getline(cin, requirement);
                natalie.create_hr_request(dat, "Service", pr, n, requirement);
            }
            else if (in2 == "view-one"){
                string proj_f;
                cout << "Project reference: " << endl;
                getline(cin, proj_f);
                natalie.view_hr_req(proj_f);
            }
            else if (in2 == "view-hr"){
                natalie.view_all_hr_req();
            }
            else if (in2 == "view-f"){
                natalie.viewFinancialRequestStatus();
            }
            else if (in2 == "view-t"){
                natalie.view_subteam_task();
            }
            else if (in2 == "view-p"){
                natalie.viewServiceTaskPlan();
            }
            else if (in2 == "appr"){
                string in3, in4;
                cout << "Please enter project reference: ";
                cin >> in3;
                cout << "Please enter creator name: ";
                cin >> in4;
                cin.ignore();
                subteam_task_plan *stp;
                if (stp = get_subteam_task_plan(in3, in4)){
                    cout << "Please enter feedback: ";
                    getline(cin, in3);
                    natalie.approveServiceTaskPlan(stp, in3);
                }
                else{
                    cout << "Wrong project_reference or creator_name!" << endl;
                }
            }
            else if (in2 == "rej"){
                string in3, in4;
                cout << "Please enter project reference: ";
                cin.ignore();
                cin >> in3;
                cout << "Please enter creator name: ";
                cin >> in4;
                cin.ignore();
                subteam_task_plan *stp;
                if (stp = get_subteam_task_plan(in3, in4)){
                    cout << "Please enter feedback: ";
                    getline(cin, in3);
                    jack.rejectProductionTaskPlan(stp, in3);
                }
                else{
                    cout << "Wrong project_reference or creator_name!" << endl;
                }
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "tobias"){
            if (!checkLogin(in1)){
                login();
            }
            string in2;
            cout << "tobias wants to...<action>" << endl;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\n>>create: create a new task plan\n";
                cout << ">>view-t: view task\n";
                cout << ">>view-p: view task plan (including feedback)\n" << endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create"){
                string date, depart, pref, det;
                long budget;
                cout << "Date: " << endl;
                getline(cin, date);
                cout << "Department: " << endl;
                cin >> depart;
                cout << "Project reference: " << endl;
                cin >> pref;
                cout << "Task plan detail: " << endl;
                cin.ignore();
                getline(cin, det);
                cout << "Extra budget: " << endl;
                cin >> budget;
                tobias.create_production_plan(date, depart, pref, det, budget);
            }
            else if (in2 == "view-t"){
                tobias.view_subteam_task();
            }
            else if (in2 == "view-p"){
                tobias.view_subteam_task_plan();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "julia"){
            if (!checkLogin(in1)){
                login();
            }
            string in2;
            cout << "julia wants to...<action>" << endl;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\n>>create: create a new task plan\n";
                cout << ">>view-t: view task\n";
                cout << ">>view-p: view task plan (including feedback)\n" << endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create"){
                string date, depart, pref, det;
                long budget;
                cout << "Date: " << endl;
                getline(cin, date);
                cout << "Department: " << endl;
                cin >> depart;
                cout << "Project reference: " << endl;
                cin >> pref;
                cout << "Task plan detail: " << endl;
                cin.ignore();
                getline(cin, det);
                cout << "Extra budget: " << endl;
                cin >> budget;
                julia.create_production_plan(date, depart, pref, det, budget);
            }
            else if (in2 == "view-t"){
                julia.view_subteam_task();
            }
            else if (in2 == "view-p"){
                julia.view_subteam_task_plan();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "helen"){
            if (!checkLogin(in1)){
                login();
            }
            string in2;
            cout << "helen wants to...<action>" << endl;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\n>>create: create a new task plan\n";
                cout << ">>view-t: view task\n";
                cout << ">>view-p: view task plan (including feedback)\n" << endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create"){
                string date, depart, pref, det;
                long budget;
                cout << "Date: " << endl;
                getline(cin, date);
                cout << "Department: " << endl;
                cin >> depart;
                cout << "Project reference: " << endl;
                cin >> pref;
                cout << "Task plan detail: " << endl;
                cin.ignore();
                getline(cin, det);
                cout << "Extra budget: " << endl;
                cin >> budget;
                helen.create_service_plan(date, depart, pref, det, budget);
            }
            else if (in2 == "view-t"){
                helen.view_subteam_task();
            }
            else if (in2 == "view-p"){
                helen.view_subteam_task_plan();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "kate"){
            if (!checkLogin(in1)){
                login();
            }
            string in2;
            cout << "kate wants to...<action>" << endl;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\n>>create: create a new task plan\n";
                cout << ">>view-t: view task\n";
                cout << ">>view-p: view task plan (including feedback)\n" << endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create"){
                string date, depart, pref, det;
                long budget;
                cout << "Date: " << endl;
                getline(cin, date);
                cout << "Department: " << endl;
                cin >> depart;
                cout << "Project reference: " << endl;
                cin >> pref;
                cout << "Task plan detail: " << endl;
                cin.ignore();
                getline(cin, det);
                cout << "Extra budget: " << endl;
                cin >> budget;
                kate.create_service_plan(date, depart, pref, det, budget);
            }
            else if (in2 == "view-t"){
                kate.view_subteam_task();
            }
            else if (in2 == "view-p"){
                kate.view_subteam_task_plan();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "sarah" || in1 == "sam"){
            if (!checkLogin(in1)){
                login();
            }
            string in2;
            if (in1 == "sarah") cout << "sarah wants to...<action>" << endl;
            else cout << "sam wants to...<action>" << endl;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\n>>create: create a event request\n";
                cout << ">>view: view all related event request status\n" << endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "create"){
                string n, d, pr, c, detail;
                cout << "Event request name: " << endl;
                getline(cin, n);
                cout << "Date: " << endl;
                getline(cin, d);
                cout << "Project reference: " << endl;
                getline(cin, pr);
                cout << "Details: " << endl;
                getline(cin, detail);
                if (in1 == "sarah"){
                    sarah.create_event_request(n, d, pr, "sarah", detail);
                }
                else sam.create_event_request(n, d, pr, "sam", detail);
            }
            else if (in2 == "view"){
                if (in1 == "sarah") sarah.view_event_request();
                else sam.view_event_request();
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "janet"){
            if (!checkLogin(in1)){
                login();
            }
            string in2;
            cout << "janet wants to...<action>" << endl;
            cin >> in2;
            cin.ignore();
            while (in2 == "ls"){
                cout << "\n>>view-1: view all event requests that SCS never made decision on\n"
                     << ">>view-2: view all event requests that are approved by AM\n"
                     << ">>appr: approve an event request (project reference needed)\n"
                     << ">>rej: reject an event request (project reference needed)" << endl;
                cin >> in2;
                cin.ignore();
            }
            if (in2 == "view-1"){
                janet.view_unsettled_event_request();
            }
            else if (in2 == "view-2"){
                janet.view_finally_approved_event_request();
            }
            else if (in2 == "appr"){
                string pr;
                cout << "Project reference: ";
                cin >> pr;
                cin.ignore();
                cout << endl;
                janet.event_request_approve(pr);
            }
            else if (in2 == "rej"){
                string pr;
                cout << "Project reference: ";
                cin >> pr;
                cin.ignore();
                cout << endl;
                janet.event_request_reject(pr);
            }
            else{
                cout << "Wrong enter!" << endl;
            }
        }
        else if (in1 == "exit"){
            return 0;
        }
        else if (in1 == "record"){
            // this should be deleted when top manager class is done
            for (int i = 0; i < login_size; i++){
                if (employee_record_list[i] == NULL) break;
                employee_record_list[i]->show_employee_record();
            }
        }
        else {
            cout << "Wrong name or operation" << endl;
        }
    }
    return 0;
}
