//
// Created by More on 13/11/2022.
//
#include "Process.h"
#ifndef PROBLEM4_TASK_MANAGER_H
#define PROBLEM4_TASK_MANAGER_H


class Task_Manager {
protected:
    vector<Process> Plist;

public:
    void addProcess(Process p)
    {
        Plist.push_back(p);
    }

    void print(){

        cout << "-----------------Program----------------\n";
        for (auto p:Plist)
        {
            cout << left << setw(30) << p.get_processname();
            cout << right << setw(10) << p.get_processid();
            cout << right << setw(10) << p.get_Meomry() << endl;
        }
    }
    void Sort_By_name(){
        sort(Plist.begin(),Plist.end(),[](Process& p1,Process& p2){
            return p1.get_processname() < p2.get_processname();
        });
    }
    void Sort_By_ID(){

        sort(Plist.begin(),Plist.end(),[](Process& p1,Process& p2){
            return p1.get_processid() < p2.get_processid();
        });
    }
    void Sort_By_memory(){

        sort(Plist.begin(),Plist.end(),[](Process& p1,Process& p2){
            return p1.get_Meomry() < p2.get_Meomry();
        });
    }
};


#endif //PROBLEM4_TASK_MANAGER_H
