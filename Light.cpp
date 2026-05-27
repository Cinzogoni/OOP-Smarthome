#include "Light.h"

Light::Light(int id, string name, int brightness)
    : Device(id, name), brightness(brightness) {}

void Light::toggle() {
    if (isError) {
        cout << "[!]" << name << " loi khong the mo" << endl;
        return;
    }

    isOn = !isOn;
    cout << name << (isOn ? " mo" : " tat") 
         << ", do sang " << brightness << "%" << endl;
}

void Light::getStatus() {
    cout << name << " id " << id << " - " << (isOn ? "mo" : "tat") 
         << ", do sang " << brightness << "%" << endl;
}

void Light::setBrightness(int b) {
    brightness = max(0, min(100, b));
    cout << name << " do sang la " << brightness << "%" << endl;
}

void Light::turnOff() {
    if (isOn) {
        toggle();
    }
}