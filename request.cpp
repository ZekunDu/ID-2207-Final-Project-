#include "request.h"

using namespace std;

freq *financialRequestList[f_request_size];

void addFinancialRequest(freq **fr, freq *newFR){
    for (int i = 0; i < f_request_size; i++){
        if (fr[i] == NULL){
            fr[i] = newFR;
            return;
        }
    }
    cout << "Financial Task is full!" << endl;
    return;
}

freq *getFinancialRequest(string projref){
    for (int i = 0; i < f_request_size; i++){
        if (financialRequestList[i] == NULL){
            cout << "Not Exist" << endl;
            return NULL;
        }
        if (financialRequestList[i]->getRef() == projref)
            return financialRequestList[i];
    }
    cout << "Not Exist" << endl;
    return NULL;
}

ftask *financialTaskList[f_request_size];

void addFinancialTask(ftask **ft, ftask *newFT){
    for (int i = 0; i < f_request_size; i++){
        if (ft[i] == NULL){
            ft[i] = newFT;
            return;
        }
    }
    cout << "Financial Task is full!" << endl;
    return;
}

event_request * event_request_list[event_request_number];

void event_request::add_to_event_request_list(){
    int i = 0;
    while (event_request_list[i] != NULL) i++;
    if (i >= event_request_number){
        cout << "event request list full!" << endl;
        return;
    }
    event_request_list[i] = this;
}


void view_all_event_request_cs(string cs){
    for (int i = 0; event_request_list[i] != NULL; i++){
        if (event_request_list[i]->get_created_by() == cs)
            event_request_list[i]->view_event_request();
    }
}

void view_all_unsettled_event_request_scs(){
    for (int i = 0; event_request_list[i] != NULL; i++){
            if (event_request_list[i] == NULL) return;
            event_request_list[i]->view_event_request();
    }
}

event_request * get_event_request(string pr){
    for (int i = 0; event_request_list[i] != NULL; i++){
        if (event_request_list[i] == NULL) NULL;
        if (event_request_list[i]->get_project_reference() == pr)
            return event_request_list[i];
    }
}

void view_all_event_request_fm(){
    for (int i = 0; event_request_list[i] != NULL; i++){
        if (event_request_list[i] == NULL) return;
        if (event_request_list[i]->get_scs_decision() == "Approve"
            && event_request_list[i]->get_am_decision() == "unsettled")
            event_request_list[i]->view_event_request();
    }
}

void view_all_unsettled_event_request_am(){
    for (int i = 0; event_request_list[i] != NULL; i++){
        if (event_request_list[i] == NULL) return;
        if (event_request_list[i]->get_scs_decision() == "Approve"
            && event_request_list[i]->get_am_decision() == "unsettled")
            event_request_list[i]->view_event_request();
    }
}

void view_all_approved_event_request_scs(){
    for (int i = 0; event_request_list[i] != NULL; i++){
        if (event_request_list[i]->get_scs_decision() == "Approve"
            && event_request_list[i]->get_fm_feedback() != ""
            && event_request_list[i]->get_am_decision() == "Approve")
            event_request_list[i]->view_event_request();
    }
}

hr_request * hr_request_list[hr_request_number];

hr_request * get_hr_request(string pr, string depart){
    for (int i = 0; hr_request_list[i] != NULL; i++){
        if (hr_request_list[i]->get_project_reference() == pr
            && hr_request_list[i]->get_department() == depart)
            return hr_request_list[i];
    }
    return NULL;
}

void view_hr_request(string pr, string depart){
    hr_request * hr_req;
    bool flag = false;
    for (int i = 0; hr_request_list[i] != NULL; i++){
        flag = true;
        hr_req = hr_request_list[i];
        if (pr != "all"){
            if (hr_req->get_project_reference() != pr){
                flag = false;
            }
        }
        if (depart != "all"){
            if (hr_req->get_department() != depart){
                flag = false;
            }
        }
        if (flag == true){
            hr_req->view_hr_request();
        }
    }
}

void add_to_hr_request_list(hr_request * hr){
    int i = 0;
    while (hr_request_list[i] != NULL) i++;
    if (i >= hr_request_number){
        cout << "HR request full!" << endl;
        return;
    }
    hr_request_list[i] = hr;
    return;
}

void view_hr_request_hr(string st){
    hr_request * hr_req;
    bool flag = false;
    for (int i = 0; hr_request_list[i] != NULL; i++){
        flag = true;
        hr_req = hr_request_list[i];
        if (hr_req->get_send_to_hr() != st)
            flag = false;
        if (flag == true){
            hr_req->view_hr_request();
        }
    }
}

string resume_list[10];

void init_resume(){
    resume_list[0] = "\nlucy green\nAAA University BCs\n/---details---/\n";
    resume_list[1] = "vivian black\nBBB University BCs\n/---details---/\n";
    resume_list[2] = "swan wu\nCCC University BCs\n/---details---/\n";
    resume_list[4] = "alan stone\nDDD University BCs\n/---details---/\n";
}
