#include<bits/stdc++.h>
using namespace std;
#include "Task_Manager.h"
int main() {

    Task_Manager taskManager;
    taskManager.addProcess(Process ("Chrome" , 5 , "10000"));
    taskManager.addProcess(Process("photoshop" , 3 , "1200"));
    taskManager.Sort_By_ID();
    taskManager.print();
    taskManager.Sort_By_name();
    taskManager.print();
    taskManager.Sort_By_memory();
    taskManager.print();
}