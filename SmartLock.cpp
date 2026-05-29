#include "SmartLock.h"
#include <iostream>

using namespace std;


SmartLock::SmartLock(int id, string name, bool lockedStatus)
: Device(id, name), isLocked(lockedStatus){}

void SmartLock::toggle(){
    if(isError){
        cout << "[!]" << name << " loi khong the mo" << endl;
        return;
    }

    isLocked = !isLocked;
    cout << "[KHOA] " << name << (isLocked ? " mo" : " tat") << endl;
}

void SmartLock::locked(){
    isLocked = true;
}

void SmartLock::unlocked(){
    isLocked = false;
}

void SmartLock::getStatus(){
    cout << "[KHOA] " << name 
                     << " id " << id << " - " 
                     << (isLocked ? "mo" : "tat") << endl;
}

