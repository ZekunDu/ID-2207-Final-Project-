#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "request.h"
#include "login.h"
#include "employee_record.h"
#include "service_production.h"
using namespace std;

class employee{   //financial manager
    // this is a general type of employees
protected:
    string name;
    string id;
    string position;
    employee_record *record;
public:
    employee(){
        record = new employee_record;
    }
    employee(string Name, string Id, string Position){
        name = Name;
        id = Id;
        position = Position;
        add_to_list();
    }
    void add_to_list();
    void add_employee_record(string proj_ref, string roll);
    void show_employee_record(){
        cout << "Employee record for " << name << ", " << position << ": " << endl;
        record->show_employee_record();
    }
    void changeName(string Name){
        name = Name;
    }
    void changeID(string ID){
        id = ID;
    }
    void changePosition(string Position){
        position = Position;
    }
    string getName(){
        return name;
    }
    string getPosition(){
        return position;
    }
    string getID(){
        return id;
    }
};

extern string employee_list[login_size];
extern employee_record * employee_record_list[login_size];

void add_employee_list(string name, string pos);
    // add a x*2 array. save name and record(new class).
void employee::add_to_list(){
    add_employee_list(this->getName(), this->getPosition());
}
/*
void employee :: add_employee_record(string proj_ref, string roll){
    employee_record * er = get_employee_record(this->getName());
    er->add_employee_record(proj_ref, roll);
}
*/

void add_employee_list(string name, string pos){
    int i = 0;
    while (employee_list[i] != "")
        i++;
    if (i >= login_size){
        cout << "Too many people!" << endl;
        return;
    }
    employee_list[i] = name;
    employee_record * erp = new employee_record(name, pos);
    employee_record_list[i] = erp;
}

class fm : public employee{
public:
    fm();
    fm(string Name, string Id, string Position){
        name = Name;
        id = Id;
        position = Position;
        add_to_list();
    }
    void createFinancialTask(string date, string depart,
                             string projref, long amount, string rsn, string cmt){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        employee_record * er1;
        employee_record * er2;
        ftask *newFTpointer = new ftask(date, depart, projref, amount, rsn);
        newFTpointer->addComments(cmt);
        addFinancialTask(financialTaskList, newFTpointer);
        er1 = get_employee_record(getName());
        er1->add_employee_record(projref, "Financial Task Sender"); // add record to profile
        for (int i = 0; i < login_size; i++){
            // add record to task receivers
            if (employee_record_list[i] == NULL) break;
            er2 = employee_record_list[i];
            if (er2->get_position() == "Accountant"){
                er2->add_employee_record(projref, "Financial Task Receiver");
            }
        }
        return;
    }
    void viewFinancialRequestStatus(){
        //list all request with status
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Financial manager " << name <<
            " views financial requests statuses." << endl;
        for (int i = 0; i < 10; i++){
            if (financialRequestList[i] == NULL) return;
            else{
                freq *freq_pointer = financialRequestList[i];
                freq_pointer->view();
            }
        }
    }
    void solve(freq *f_request){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        f_request->changeStatus();
    }
    void addFeedback(freq *f_request, string feedback){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        f_request->addFeedback(feedback);
    }
    void view_event_request(){
        view_all_event_request_fm();
    }
    void add_event_request_feedback(string proj_ref, string feedback){
        if (!get_event_request(proj_ref)) cout << "A" << endl;
        get_event_request(proj_ref)->add_fm_feedback(feedback);
    }

    /*test record*/
    /*
    bool isRecordExist(){
        if (record == NULL)
            return false;
        else return true;
    }
    */

};

class fa : public employee{   //financial accountant
    // this is a general type of employees
public:
    fa(){}
    fa(string Name, string Id, string Position){
        name = Name;
        id = Id;
        position = Position;
        add_to_list();
    }
    void viewFinancialTask(){
        //list all f-task details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Financial accountant " << name <<
            " views financial tasks." << endl;
        for (int i = 0; i < 10; i++){
            if (financialTaskList[i] == NULL) return;
            else{
                ftask *ftask_pointer = financialTaskList[i];
                ftask_pointer->view();
            }
        }
    }

};

class pm : public employee{
    //production manager
public:
    pm();
    pm(string Name, string Id, string Position){
        name = Name;
        id = Id;
        position = Position;
        add_to_list();
    }
    void create_hr_request(string dat, string depart, string pr,
                           int n, string req){
        hr_request * hr = new hr_request(dat, depart, pr, n, req);
        add_to_hr_request_list(hr);
    }
    void view_hr_req(string pr){
        view_hr_request(pr, "Production");
    }
    void view_all_hr_req(){
        view_hr_request("all", "Production");
    }
    void createFinancialRequest(string date, string depart,
                           string projref, long amount, string rsn){
        //new a f-request and add it to global list.
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        employee_record *er1;
        employee_record *er2;
        freq *newFReqPointer = new freq(date, depart, projref, amount, rsn);
        addFinancialRequest(financialRequestList, newFReqPointer);
        er1 = get_employee_record(getName());
        er1->add_employee_record(projref, "Financial Request Sender"); // add record to profile
        for (int i = 0; i < login_size; i++){
            // add record to task receivers
            er2 = employee_record_list[i];
            if (er2==NULL) break;
            if (er2->get_position() == "Financial Manager"){
                er2->add_employee_record(projref, "Financial Request Receiver");
            }
        }
        return;
    }
    void viewFinancialRequestStatus(){
        // list all "production" financial request details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production manager " << name
            << " views financial requests status" << endl;
        if (financialRequestList[0] == NULL){
            cout << "No request in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < 10; i++){
            if (financialRequestList[i] != NULL){
                if (financialRequestList[i]->getDepartment() == "Production"){
                    financialRequestList[i]->view();
                }
            }
            else return;
        }
    }
    void createProductionTask(string date, string depart, string pref,
                 string det, string to){
        employee_record *er1;
        employee_record *er2;
        string pos;
        subteam_task * new_production_task = new subteam_task(date, depart,
                                                              pref, det, to);
        add_subteam_task_list(subteam_task_list, new_production_task);
        er1 = get_employee_record(getName());
        er1->add_employee_record(pref, "Subteam Task Sender"); // add record to profile

        for (int i = 0; i < login_size; i++){
            // add record to task receivers
            er2 = employee_record_list[i];
            if (er2==NULL) break;
            if (er2->get_position() == "Production Team"
                && er2->get_name() == to){
                er2->add_employee_record(pref, "Subteam Task Receiver");
            }
        }
    }
    void view_subteam_task(){
        // list all "production" subteam task details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production manager " << name
            << " views subteam tasks" << endl;
        if (subteam_task_list[0] == NULL){
            cout << "No task in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < 10; i++){
            if (subteam_task_list[i] != NULL){
                if (subteam_task_list[i]->get_department() == "Production"){
                    subteam_task_list[i]->view();
                }
            }
            else return;
        }
    }
    void viewProductionTaskPlan(){
        // list all "production" subteam task PLAN details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production manager " << name
            << " views subteam task PLANs" << endl;
        if (subteam_task_plan_list[0] == NULL){
            cout << "No task in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < 10; i++){
            if (subteam_task_plan_list[i] != NULL){
                if (subteam_task_plan_list[i]->get_department() == "Production"){
                    subteam_task_plan_list[i]->view();
                }
            }
            else return;
        }
    }
    void approveProductionTaskPlan(/*subteam_task_plan_list **list_pointer,*/
        subteam_task_plan * stp, string feedback){
        stp->add_feedback("Approved! " + feedback);
        // add feedback to plan
    }
    void rejectProductionTaskPlan(subteam_task_plan * stp, string feedback){
        stp->add_feedback("Rejected! " + feedback);
    }
};

class pt : public employee{
    //production team
public:
    pt();
    pt(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void view_subteam_task(){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production subteam member " << name
            << " views subteam tasks" << endl;
        if (subteam_task_list[0] == NULL){
            cout << "No request in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < subteam_task_number; i++){
            if (subteam_task_list[i] != NULL){
                if (subteam_task_list[i]->get_send_to() == name){
                    subteam_task_list[i]->view();
                }
            }
            else return;
        }
    }
    void create_production_plan(string date, string depart, string pref,
                 string det, long budget){
        // new a production team task and add it to global list
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        subteam_task_plan * new_production_task_plan = new subteam_task_plan(this->getName(), date, depart, pref, det, budget);
        add_subteam_task_plan_list(subteam_task_plan_list, new_production_task_plan);
    }
    void view_subteam_task_plan(){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production subteam member " << name
            << " views subteam tasks" << endl;
        if (subteam_task_plan_list[0] == NULL){
            cout << "No plan in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < subteam_task_plan_number; i++){
            if (subteam_task_plan_list[i] != NULL){
                if (subteam_task_plan_list[i]->get_creater_name() == name){
                    subteam_task_plan_list[i]->view();
                }
            }
            else return;
        }
    }
};

class sm : public employee{
    //service manager
public:
    sm();
    sm(string Name, string Id, string Position){
        name = Name;
        id = Id;
        position = Position;
        add_to_list();
    }
    void create_hr_request(string dat, string depart, string pr,
                           int n, string req){
        hr_request * hr = new hr_request(dat, depart, pr, n, req);
        add_to_hr_request_list(hr);
    }
    void view_hr_req(string pr){
        view_hr_request(pr, "Service");
    }
    void view_all_hr_req(){
        view_hr_request("all", "Service");
    }
    void createFinancialRequest(string date, string depart,
                           string projref, long amount, string rsn){
        //new a f-request and add it to global list.
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        employee_record *er1;
        employee_record *er2;
        freq *newFReqPointer = new freq(date, depart, projref, amount, rsn);
        addFinancialRequest(financialRequestList, newFReqPointer);
        er1 = get_employee_record(getName());
        er1->add_employee_record(projref, "Financial Request Sender"); // add record to profile
        for (int i = 0; i < login_size; i++){
            // add record to task receivers
            if (employee_record_list[i] == NULL) break;
            er2 = employee_record_list[i];
            if (er2->get_position() == "Financial Manager"){
                er2->add_employee_record(projref, "Financial Request Receiver");
            }
        }
    }
    void viewFinancialRequestStatus(){
        // list all "service" financial request details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Service manager " << name
            << " views financial requests status" << endl;
        if (financialRequestList[0] == NULL){
            cout << "No request in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < 10; i++){
            if (financialRequestList[i] != NULL){
                if (financialRequestList[i]->getDepartment() == "Service"){
                    financialRequestList[i]->view();
                }
            }
            else return;
        }
    }
    createServiceTask(string date, string depart, string pref,
                 string det, string to){
        employee_record *er1;
        employee_record *er2;
        string pos;
        subteam_task * new_service_task = new subteam_task(date, depart,
                                                              pref, det, to);
        add_subteam_task_list(subteam_task_list, new_service_task);
        er1 = get_employee_record(getName());
        er1->add_employee_record(pref, "Subteam Task Sender"); // add record to profile

        for (int i = 0; i < login_size; i++){
            // add record to task receivers
            er2 = employee_record_list[i];
            if (er2==NULL) break;
            if (er2->get_position() == "Service Team"
                && er2->get_name() == to){
                er2->add_employee_record(pref, "Subteam Task Receiver");
            }
        }
    }
    void view_subteam_task(){
        // list all "production" subteam task details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Service manager " << name
            << " views subteam tasks" << endl;
        if (subteam_task_list[0] == NULL){
            cout << "No task in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < 10; i++){
            if (subteam_task_list[i] != NULL){
                if (subteam_task_list[i]->get_department() == "Service"){
                    subteam_task_list[i]->view();
                }
            }
            else return;
        }
    }
    void viewServiceTaskPlan(){
        // list all "production" subteam task PLAN details
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Service manager " << name
            << " views subteam task PLANs" << endl;
        if (subteam_task_plan_list[0] == NULL){
            cout << "No task in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < 10; i++){
            if (subteam_task_plan_list[i] != NULL){
                if (subteam_task_plan_list[i]->get_department() == "Service"){
                    subteam_task_plan_list[i]->view();
                }
            }
            else return;
        }
    }
    void approveServiceTaskPlan(/*subteam_task_plan_list **list_pointer,*/
        subteam_task_plan * stp, string feedback){
        stp->add_feedback("Approved! " + feedback);
        // add feedback to plan
    }
    void rejectServiceTaskPlan(subteam_task_plan * stp, string feedback){
        stp->add_feedback("Rejected! " + feedback);
    }
};


class st : public employee{
    //production team
public:
    st();
    st(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void view_subteam_task(){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production subteam member " << name
            << " views subteam tasks" << endl;
        if (subteam_task_list[0] == NULL){
            cout << "No request in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < subteam_task_number; i++){
            if (subteam_task_list[i] != NULL){
                if (subteam_task_list[i]->get_send_to() == name){
                    subteam_task_list[i]->view();
                }
            }
            else return;
        }
    }
    void create_service_plan(string date, string depart, string pref,
                 string det, long budget){
        // new a production team task and add it to global list
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        subteam_task_plan * new_service_task_plan = new subteam_task_plan(this->getName(), date, depart, pref, det, budget);
        add_subteam_task_plan_list(subteam_task_plan_list, new_service_task_plan);
    }
    void view_subteam_task_plan(){
        if (!checkLogin(name)){
            cout << name << " has not logged in yet." << endl;
            return;
        }
        cout << endl << "//Production subteam member " << name
            << " views subteam tasks" << endl;
        if (subteam_task_plan_list[0] == NULL){
            cout << "No plan in the list yet!" << endl;
            return;
        }
        for (int i = 0; i < subteam_task_plan_number; i++){
            if (subteam_task_plan_list[i] != NULL){
                if (subteam_task_plan_list[i]->get_creater_name() == name){
                    subteam_task_plan_list[i]->view();
                }
            }
            else return;
        }
    }
};

class cs : employee{
public:
    cs();
    cs(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void create_event_request(string n, string d, string pr, string c, string detail){
        event_request * new_event_request = new event_request(n, d, pr, c, detail);
    }
    void view_event_request(){
        view_all_event_request_cs(getName());
    }
};

class scs : employee{
public:
    scs(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void view_unsettled_event_request(){
        view_all_unsettled_event_request_scs();
    }
    void event_request_approve(string project_reference){
        if (get_event_request(project_reference) == NULL){
            cout << "Wrong reference!" << endl;
            return;
        }
        get_event_request(project_reference)->scs_approve();
    }
    void event_request_reject(string project_reference){
        if (get_event_request(project_reference) == NULL){
            cout << "Wrong reference!" << endl;
            return;
        }
        get_event_request(project_reference)->scs_reject();
    }
    void view_finally_approved_event_request(){
        view_all_approved_event_request_scs();
    }
};

class am : employee{
public:
    am(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void view_unsettled_event_request(){
        view_all_unsettled_event_request_am();
    }
    void event_request_approve(string project_reference){
        if (get_event_request(project_reference) == NULL){
            cout << "Wrong reference!" << endl;
            return;
        }
        get_event_request(project_reference)->am_approve();
    }
    void event_request_reject(string project_reference){
        if (get_event_request(project_reference) == NULL){
            cout << "Wrong reference!" << endl;
            return;
        }
        get_event_request(project_reference)->am_reject();
    }
};

class hrm : employee{
public:
    hrm();
    hrm(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void view_hr_req(){
        view_hr_request("all", "all");
    }
    void order_task(string pr, string depart, string st){
        hr_request * p;
        if (p = get_hr_request(pr, depart))
            p->change_send_to_hr(st);
    }
};

class hr : employee{
public:
    hr();
    hr(string n, string ID, string p){
        name = n;
        position = p;
        id = ID;
        add_to_list();
    }
    void view_hr_req(){
        view_hr_request_hr(getName());
    }
    void hire(string pr, string depart, string name){
        int i = 0;
        hr_request * hr_r = get_hr_request(pr, depart);
        if (hr_r == NULL) return;
        while (hr_r->hire_list[i] != "") i++;
        if (i < hr_r->get_number())
            hr_r->add_hire(name);
        if (hr_r->get_number() == i)
            hr_r->change_status("settled");
    }
    void view_resume(){
        for (int i = 0; resume_list[i] != ""; i++)
            cout << resume_list[i] << endl;
    }
};
#endif
