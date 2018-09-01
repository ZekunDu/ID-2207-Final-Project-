#ifndef SERVICE_PRODUCTION_H
#define SERVICE_PRODUCTION_H
#include <string>
#include <iostream>
#define subteam_task_number 20
#define subteam_task_plan_number 20

using namespace std;


class subteam_task{
private:
    string Date;
    string department;
    string projReference;
    string detail;
    string send_to; //name
public:
    subteam_task(){}
    subteam_task(string date, string depart, string pref,
                 string det, string to){
        Date = date;
        department = depart;
        projReference = pref;
        detail = det;
        send_to = to;
    }
    void view(){
        cout << "\n>>Task Send Date: " << Date << endl;
        cout << ">>Department: " << department << endl;
        cout << ">>Project Reference: " << projReference << endl;
        cout << ">>Detail: " << detail << endl;
        cout << ">>Task Send to: " << send_to << endl;
    }
    void change_date(string d){Date = d;}
    string get_date(){return Date;}
    void change_department(string d){department = d;}
    string get_department(){return department;}
    void change_project_ref(string r){projReference = r;}
    string get_project_ref(){return projReference;}
    void add_detail(string d){detail += (d + " ");}
    string get_detail(){return detail;}
    void change_send_to(string st){send_to = st;}
    string get_send_to(){return send_to;}

};

extern subteam_task * subteam_task_list[subteam_task_number];

void add_subteam_task_list(subteam_task **list_pointer, subteam_task * new_sub_task);

subteam_task * get_subteam_task(string project_ref);

class subteam_task_plan{
private:
    string creater_name;
    string Date;
    string department;
    string projReference;
    string detail;
    string feedback;
    //string send_to; //name
    long budget;
public:
    subteam_task_plan(){}
    subteam_task_plan(string name, string date, string depart, string pref,
                 string det, long bud){
        creater_name = name;
        Date = date;
        department = depart;
        projReference = pref;
        detail = det;
        budget = bud;
    }
    void view(){
        cout << "\n>>Creater name: " << creater_name << endl;
        cout << ">>Task Send Date: " << Date << endl;
        cout << ">>Department: " << department << endl;
        cout << ">>Project Reference: " << projReference << endl;
        cout << ">>Detail: " << detail << endl;
        cout << ">>Extra_budget: " << budget << endl;
        cout << ">>Feedback: " << feedback << endl;
    }
    void change_date(string d){Date = d;}
    string get_date(){return Date;}
    void change_department(string d){department = d;}
    string get_department(){return department;}
    void change_project_ref(string r){projReference = r;}
    string get_project_ref(){return projReference;}
    void add_detail(string d){detail += (d + " ");}
    string get_detail(){return detail;}
    void change_budget(long bud){budget = bud;}
    long get_budget(){return budget;}
    string get_creater_name(){return creater_name;}
    void add_feedback(string fb){
        feedback += (" " + fb);
    }
};

extern subteam_task_plan * subteam_task_plan_list[subteam_task_plan_number];

void add_subteam_task_plan_list(subteam_task_plan **list_pointer, subteam_task_plan * new_sub_task_plam);

subteam_task_plan * get_subteam_task_plan(string project_ref, string name);

#endif // SERVICE_PRODUCTION_H
