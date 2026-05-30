#include "SmartHomeHub.h"
#include <iostream>

SmartHomeHub::SmartHomeHub(const string& name) {
    hubName = name;
}

void SmartHomeHub::addDevice(Device* device) {
    devices.push_back(device);
    cout << "[HUB] " << device->getName() << " da duoc them vao." << endl;
}

void SmartHomeHub::toggleDevice(int id) {
    for (Device* device : devices) {
        if (device->getId() == id) {
            device->toggle();
            return;
        }
    }
    cout << "[HUB] Khong tim thay thiet bi co id " << id << endl;
}

void SmartHomeHub::malfunctionDevice(int id) {
    for (Device* device : devices) {
        if (device->getId() == id) {
            !(*device);
            return;
        }
    }
    cout << "[HUB] Khong tim thay thiet bi co id " << id << endl;
}

void SmartHomeHub::allStatus() {
    cout << string(50, '=') << endl;
    cout << "TRANG THAI HE THONG: " << hubName << endl;
    for (Device* device : devices) {
        device->getStatus(); 
    }
}

void SmartHomeHub::triggerDeviceFault(Device* device) {
   cout << "[HUB] Dang quet va kiem tra phan cung cho: " 
        << device->getName() << endl;
    
    !(*device); 

   
    if (device->getIsError()) { 
        cout << "[HUB] Cảnh báo: " 
             << device->getName() << " dang dính su co!" << endl;
        
        cout << "[HUB] He thong tu dong kich hoat lenh RESET de khac phuc..." << endl;
        !(*device); 

        cout << "[HUB] Hoan thanh quet! He thong trung tam da on dinh." << endl;
    }
}