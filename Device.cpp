#include "Device.h"

Device::Device(){}

Device::Device(int id, string name)
:id(id), name(name), isOn(false), isError(false){}

Device::~Device(){}

bool Device::getIsError() const {
    return isError;
}

void Device::operator!() {
    isError = !isError;
    if (isError) {
        isOn = false;
        cout << "[!] " << name << " SU CO LOI - khoi dong lai" << endl;    
    } else {
        cout << "[OK] " << name << " Da khoi dong lai thanh cong" << endl;
    }
}