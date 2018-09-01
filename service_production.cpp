#include "service_production.h"

using namespace std;

subteam_task * subteam_task_list[subteam_task_number];

void add_subteam_task_list(subteam_task **list_pointer, subteam_task * new_sub_task){
    int i = 0;
    while(list_pointer[i] != NULL)
        i++;
    if (i >= subteam_task_number){
        cout << "Subteam task full!" << endl;
        return;
    }
    list_pointer[i] = new_sub_task;
    return;
}

subteam_task * get_subteam_task(string project_ref){
    for (int i = 0; i < subteam_task_number; i++){
        if (subteam_task_list[i] == NULL){
            cout << "Not exist!" << endl;
            return NULL;
        }
        if (subteam_task_list[i]->get_project_ref() == project_ref)
            return subteam_task_list[i];
    }
    cout << "Not exist!" << endl;
    return NULL;
}

subteam_task_plan * subteam_task_plan_list[subteam_task_plan_number];

void add_subteam_task_plan_list(subteam_task_plan **list_pointer, subteam_task_plan * new_sub_task_plan){
    int i = 0;
    while(list_pointer[i] != NULL)
        i++;
    if (i >= subteam_task_plan_number){
        cout << "Subteam task plan full!" << endl;
        return;
    }
    list_pointer[i] = new_sub_task_plan;
    return;
}

subteam_task_plan * get_subteam_task_plan(string project_ref, string name){
    //return a pointer to a task plan according to project reference and teammember name
    for (int i = 0; i < subteam_task_number; i++){
        if (subteam_task_plan_list[i] == NULL){
            cout << "Not exist!" << endl;
            return NULL;
        }
        if (subteam_task_plan_list[i]->get_project_ref() == project_ref &&
             name == subteam_task_plan_list[i]->get_creater_name())
            return subteam_task_plan_list[i];
    }
    cout << "Not exist!" << endl;
    return NULL;
}
