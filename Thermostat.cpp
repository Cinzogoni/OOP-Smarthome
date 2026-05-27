#include "Thermostat.h"

Thermostat::Thermostat(int id, string name, float init, float target)
: Device(id, name), currentTemp(init), targetTemp(target), heaterOn(false), coolerOn(false) {}

void Thermostat::toggle(){
    if (isError) {
        cout << "[!]" << name << " loi khong the mo" << endl;
        return;
    }

    isOn = !isOn;
    if(!isOn){
        heaterOn = false;
        coolerOn = false;
    }

    cout << "[NHIET] " << name << (isOn ? " mo" : " tat") << endl;
}

void Thermostat::getStatus(){
    cout << "[NHIET] " << name << " id " << id << " - " << (isOn ? "mo" : "tat") 
         << "Hien tai " << currentTemp << "°C" 
         << "Muc tieu " << targetTemp << "°C" 
         << (isError ? "[TRUC TRAC]" : "[BINH THUONG]") << endl;

}

void Thermostat::setTargetTemp(float t){
    targetTemp = t;
    cout << "[NHIET] " << name << " da dat muc tieu " << targetTemp << endl;
  
}

void Thermostat::updateEnvironment(){
    
}