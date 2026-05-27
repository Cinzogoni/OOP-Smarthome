#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"
using namespace std;

class Thermostat : public Device {
    private:
        float currentTemp, targetTemp;
        bool heaterOn, coolerOn;

    public:
        Thermostat(int id, string name, float currentTemp, float targetTemp);

        void toggle() override;
        void getStatus() override;
        void setTargetTemp(float t);
        void updateEnvironment();
};

#endif