//
// Created by More on 13/11/2022.
//
#include<bits/stdc++.h>
using namespace std;
#ifndef PROBLEM4_PROCESS_H
#define PROBLEM4_PROCESS_H


class Process {
protected:
    string  processname;
    int processId;
    string memory;


public:

    Process(string name , int id , string _memory)
    {   processname = name;
        processId = id;
        this->memory = _memory;
    }

    string get_processname()
    {
        return processname;
    }
    int get_processid()
    {
        return processId;
    }
    string get_Meomry()
    {
        return memory;
    }

};


#endif //PROBLEM4_PROCESS_H
