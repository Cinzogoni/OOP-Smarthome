#include "Light.h"

Light::Light(int id, string name, int brightness)
    : Device(id, name), brightness(brightness) {}

void Light::toggle() {
    if (isError) {
        cout << "[!] " << name << " loi khong the mo" << endl;
        return;
    }

    isOn = !isOn;
    cout << "[DEN] " << name << (isOn ? " MO" : " TAT") 
         << ", do sang " << brightness << "%" << endl;
}

void Light::getStatus() {
    cout << "[DEN] " << name << " id " << id << " - " << (isOn ? "MO" : "TAT") 
         << ", do sang " << brightness << "%" << endl;
}

void Light::setBrightness(int b) {
    brightness = max(0, min(100, b));
    cout << "[DEN] " << name << " do sang la " << brightness << "%" << endl;
}

void Light::turnOff() {
    if (isOn) {
        toggle();
    }
}