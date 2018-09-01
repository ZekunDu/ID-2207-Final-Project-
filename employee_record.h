#ifndef EMPLOYEE_RECORD_H
#define EMPLOYEE_RECORD_H
#include <string>
#include <iostream>

using namespace std;

string employee_list[login_size];



class employee_record{
    string name;
    string position;
    string project_reference[10];
    string roll[10];
public:
    employee_record(){}
    employee_record(string n, string pos){
        name = n;
        position = pos;
    }
    string get_name(){return name;}
    void add_employee_record(string proj_ref, string rol){

        int i = 0;
        while (project_reference[i] != "")
            i++;
        if (i > 9) {
            cout << "Employee_record full!" << endl;
            return;
        }
        project_reference[i] = proj_ref;
        roll[i] = rol;
    }
    void show_employee_record(){
        cout << "\n/- " << name << ", " << position << " -/\n";
        for (int i = 0; i < 10; i++){
            if (project_reference[i] == "")
                return;
            cout << "Project reference: " << project_reference[i]
             << "; Roll: " << roll[i]  <<endl;
        }
    }
    string get_position(){
        return position;
    }
};

employee_record * employee_record_list[login_size];

employee_record * get_employee_record(string name){
    for (int i = 0; i < login_size; i++){
        if (employee_list[i] == name) return employee_record_list[i];
    }
    return NULL;
}

void show_employees(){ // just for test
    for (int i = 0; i < login_size; i++){
        cout << employee_list[i] << " ";
        if (employee_record_list[i]!=NULL){
            cout << employee_record_list[i]->get_name()
            << employee_record_list[i]->get_position();
            cout << "Not Null "<<endl;
        }
        else    cout <<"NULL" <<endl;
    }
    cout << endl;
}

#endif // EMPLOYEE_RECORD_H
