#include "Device.h"

Device::Device(){}

Device::Device(int id, string name)
:id(id), name(name), isOn(false), isError(false){}

Device::~Device(){}

void Device::operator!() {
    isError = !isError;
    if (isError) {
        isOn = false;
        cout << "[!]" << name << " Su co - khoi dong lai" << endl;    
    } else {
        cout << "[OK]" << name << " Da khoi dong lai thanh cong" << endl;
    }
}