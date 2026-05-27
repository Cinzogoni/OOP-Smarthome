#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"
#include <algorithm>

class Light : public Device {
private:
    int brightness;

public:
    Light(int id, string name, int brightness);

    void toggle() override;
    void getStatus() override;
    void setBrightness(int b);
    void turnOff();
};

#endif