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
    cout << "TRANG THAI HE THONG: " << hubName << endl;
    for (Device* device : devices) {
        device->getStatus(); 
    }
}