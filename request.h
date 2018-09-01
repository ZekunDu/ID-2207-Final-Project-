#ifndef REQUEST_H
#define REQUEST_H
#include <string>
#include <iostream>
#define f_request_size 10
#define event_request_number 10
#define hr_request_number 10
using namespace std;

class freq{
private:
    string reqDate;
    string department;
    string projReference;
    long reqAmount;
    string reason;
    string status = "unsolved";
    string feedback = "";
public:
    freq(){}
    freq(string date, string depart, string projref, long amount, string rsn){
        reqDate = date;
        department = depart;
        projReference = projref;
        reqAmount = amount;
        reason = rsn;
    }
    void view(){
        cout << "\n>>Reqest Date: " << reqDate << endl;
        cout << ">>Request Department: " << department << endl;
        cout << ">>Project Reference: " << projReference << endl;
        cout << ">>Requested Amount: " << reqAmount << "kr" << endl;
        cout << ">>Reason: " << reason << endl;
        cout << ">>Status: " << status << endl;
        cout << ">>Feedback From Financial Manager: " << feedback << endl;
    }
    void changeDate(string date){
        reqDate = date;
    }
    void changeDepartment(string dep){
        department = dep;
    }
    void changeReference(string refe){
        projReference = refe;
    }
    string getRef(){
        return projReference;
    }
    string getDepartment(){
        return department;
    }
    string getDate(){
        return reqDate;
    }
    long getAmount(){
        return reqAmount;
    }
    string getReason(){
        return reason;
    }
    void changeAmount(long am){
        reqAmount = am;
    }
    void addReason(string rsn){
        reason += "\n";
        reason += rsn;
    }
    void changeStatus(){
        status = "Solved";
    }
    void addFeedback(string fb){
        feedback += " ";
        feedback += fb;
    }
};

extern freq *financialRequestList[f_request_size];

void addFinancialRequest(freq **fr, freq *newFR);

class ftask{
private:
    string reqDate;
    string department;
    string projReference;
    long reqAmount;
    string reason;
    string comments;
public:
    ftask(){}
    ftask(string date, string depart, string projref, long amount, string rsn){
        reqDate = date;
        department = depart;
        projReference = projref;
        reqAmount = amount;
        reason = rsn;
    }
    void view(){
        cout << "\n>>Reqest Date: " << reqDate << endl;
        cout << ">>Request Department: " << department << endl;
        cout << ">>Project Reference: " << projReference << endl;
        cout << ">>Requested Amount: " << reqAmount << "kr" << endl;
        cout << ">>Reason: " << reason << endl;
        cout << ">>Comments From Financial Manager: " << comments << endl;
    }
    void addComments(string cmt){
        comments += cmt;
    }
};

extern ftask *financialTaskList[f_request_size];

void addFinancialTask(ftask **ft, ftask *newFT);

freq *getFinancialRequest(string projref);

class event_request{
    string name;
    string date;
    string project_reference;
    string created_by; //name of cs
    string scs_decision;
    string am_decision;
    string fm_feedback;
    string detail;
public:
    event_request(){
        am_decision = "unsettled";
        scs_decision = "unsettled";
        fm_feedback = "";
        add_to_event_request_list();
    }
    event_request(string n, string d, string pr, string c, string det){
        name = n;
        date = d;
        project_reference = pr;
        created_by = c;
        detail = det;
        am_decision = "unsettled";
        scs_decision = "unsettled";
        fm_feedback = "";
        add_to_event_request_list();
    }
    void add_to_event_request_list();
    void change_name(string n){name = n;}
    string get_name(){return name;}
    void change_date(string d){date = d;}
    string get_date(){return date;}
    void change_project_reference(string pr){project_reference = pr;}
    string get_project_reference(){return project_reference;}
    void change_created_by(string c){created_by = c;}
    string get_created_by(){return created_by;}
    void add_scs_decision(string d){scs_decision = d;}
    string get_scs_decision(){return scs_decision;}
    void add_am_decision(string d){am_decision = d;}
    string get_am_decision(){return am_decision;}
    void add_fm_feedback(string fb){fm_feedback = fb;}
    string get_fm_feedback(){return fm_feedback;}
    void view_event_request(){
        cout << "\n>>Event request name: " << get_name() << endl;
        cout << ">>Project reference: " << get_project_reference() << endl;
        cout << ">>Date: " << get_date() << endl;
        cout << ">>Created by: " << get_created_by() << endl;
        cout << ">>Detail: " << detail << endl;
        cout << ">>SCS decision: " << get_scs_decision() << endl;
        cout << ">>FM feedback: " << get_fm_feedback() << endl;
        cout << ">>AM decision: " << get_am_decision() << endl;
    }
    void scs_approve(){
        add_scs_decision("Approve");
    }
    void scs_reject(){
        add_scs_decision("Reject");
    }
    void am_approve(){
        add_am_decision("Approve");
    }
    void am_reject(){
        add_am_decision("Reject");
    }
};

extern event_request * event_request_list[event_request_number];

event_request * get_event_request(string project_reference);
// return event request pointer by project reference

void view_all_event_request_cs(string cs);
// this is used only by cs
// cs can only see the event request that is himself

void view_all_unsettled_event_request_scs();
// this is used only by scs
// scs want to view all unsettled request
// by scs, scs can decide APPROVE or REJECT

void view_all_event_request_fm();
// this is used only by fm
// fm can see which is 1. approved by scs
// 2. fm_feedback is "" & 3. unsettled by am

void view_all_unsettled_event_request_am();
// this is used only by am
// am want to view all unsettled request
// by am, am can decide APPROVE or REJECT

void view_all_approved_event_request_scs();
// this is used only by scs
// scs want to view all approved request
// by AM finally

class hr_request{
    string date;
    string department;
    string project_reference;
    int req_number;
    string recruitment_requirement;
    string send_to_hr;
    string status;
public:
    string hire_list[10];
    hr_request(){
        req_number = 0;
        status = "unsettled";
    }
    hr_request(string dat, string depart, string pr, int n, string req){
        date = dat;
        department = depart;
        project_reference = pr;
        req_number = n;
        recruitment_requirement = req;
        status = "unsettled";
        send_to_hr = "";
    }
    void change_date(string d){date = d;}
    string get_date(){return date;}
    void change_department(string d){department = d;}
    string get_department(){return department;}
    void change_number(int n){req_number = n;}
    int get_number(){return req_number;}
    void change_project_reference(string pr){project_reference = pr;}
    string get_project_reference(){return project_reference;}
    void change_recruitment_requirement(string s){recruitment_requirement = s;}
    string get_recruitment_requirement(){return recruitment_requirement;}
    void change_status(string s){status = s;}
    string get_status(){return status;}
    void change_send_to_hr(string h){send_to_hr = h;}
    string get_send_to_hr(){return send_to_hr;}
    void add_hire(string name){
        int i = 0;
        while (hire_list[i] != "") {
            if (i >= 10){
                cout << "full! "<< endl;
                return;
            }
            i++;
        }
        hire_list[i] = name;
        if (i == req_number - 1) change_status("settled");
    }
    void view_hr_request(){
        cout << "\n>>Date: " << get_date() << endl;
        cout << ">>Department: " << get_department() << endl;
        cout << ">>Project reference: " << get_project_reference() << endl;
        cout << ">>Required recruitment number: " << get_number() << endl;
        cout << ">>Recruitment requirements: " << get_recruitment_requirement() << endl;
        cout << ">>Status: " << get_status() << endl;
        cout << ">>Send to (hr): " << get_send_to_hr() << endl;
        cout << ">>Hire: ";
        for (int i = 0; hire_list[i] != ""; i++){
            cout << hire_list[i] << " ";
        }
        cout << endl;
    }
};

extern hr_request * hr_request_list[hr_request_number];

hr_request * get_hr_request(string pr, string depart);

void view_hr_request(string pr, string depart);

void add_to_hr_request_list(hr_request * hr);

void view_hr_request_hr(string st);
// this is used only by HR not HRM

extern string resume_list[10];

void init_resume();

#endif // REQUEST_H
