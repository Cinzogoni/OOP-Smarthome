#include "Thermostat.h"
#include "SmartHomeExceptions.h"
#include <cmath>
#include <iostream>

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

void Thermostat::updateEnvironment(){
    if(!isOn){
        coolerOn = false;
        heaterOn = false;
        if(currentTemp < 30.0f) currentTemp += 0.5f;
        if(currentTemp > 30.0f) currentTemp -= 0.5f;
        return;
    }

    if(currentTemp > targetTemp + 0.5f){
        coolerOn = true;
        heaterOn = false;
        currentTemp -= 0.5f;
    }else if(currentTemp < targetTemp - 0.5f){
        coolerOn = false;
        heaterOn = true;
        currentTemp += 0.5f;
    }else{
        coolerOn = false;
        heaterOn = false;
    } 
}

void Thermostat::getStatus(){
    if(heaterOn){
        cout << "Dang suoi am" << endl;
    }else if(coolerOn){
        cout << "Dang lam mat" << endl;
    }else{
        cout << "Dang on dinh" << endl;
    }

    cout << "[NHIET] " << name << " hien tai " << currentTemp << " do C" << endl;
    cout << "[NHIET] " << name << " muc tieu " << targetTemp << " do C" << endl;
}

void Thermostat::setTargetTemp(float t){
    targetTemp = t;
    cout << "[NHIET] " << name << " da dat muc tieu " << targetTemp << " do C" << endl;
  
}

void Thermostat::forceFeedbackLoop(){
    cout << "MO TA VONG LAP PHAN HOI" << endl;
    cout << "Nhiet do hien tai: " << currentTemp
         << ", Muc tieu: " << targetTemp << endl;

    srand(time(0));
    isOn = true; 
    int feedbackCount = 0;

    while (feedbackCount < MAX_FEEDBACK) {
        feedbackCount++;
        cout << "Chu ky " << feedbackCount << endl;

        //LẠNH ĐỘT NGỘT -> BẬT MÁY SƯỞI
        if (feedbackCount % 2 != 0) {
            currentTemp = 10.0f + (rand() % 11);
            cout << "Nhiet do GIAM dot ngot: " << currentTemp << " do C" << endl;
            updateEnvironment(); 
            
            if (heaterOn) cout << "heater ON!" << endl;
        }
        //NÓNG ĐỘT NGỘT -> BẬT MÁY LẠNH
        else {
            currentTemp = 32.0f + (rand() % 11);
            cout << "Nhiet do TANG dot ngot: " << currentTemp << " do C" << endl;
            updateEnvironment(); 
            
            if (coolerOn) cout << "cooler ON!" << endl;
        }

        if (feedbackCount == MAX_FEEDBACK) {
            throw FeedbackLoopException();
        }
    }
}
