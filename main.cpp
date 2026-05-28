#include <iostream>
#include "Light.h"
#include "Thermostat.h"
#include "MacroSystem.h"
#include "SmartHomeHub.h"

int main(){
    SmartHomeHub myHub("TONG DAI DAY!");

    Light *den_phong_khach = new Light(1, "Den Phong Khach", 90);
    Thermostat *dieu_hoa_phong_khach = new Thermostat(2, "Dieu Hoa Phong Khach", 30.0f, 28.5f);

    Light *den_phong_ngu = new Light(3, "Den Phong Ngu", 70);
    Thermostat *dieu_hoa_phong_ngu = new Thermostat(4, "Dieu Hoa Phong Ngu", 25.0f, 22.0f);

    myHub.addDevice(den_phong_khach);
    myHub.addDevice(dieu_hoa_phong_khach);
    myHub.addDevice(den_phong_ngu);
    myHub.addDevice(dieu_hoa_phong_ngu);

myHub.getMacroSystem().addMacro("Chuc Ngu Ngon", {
        [=]() { den_phong_khach->setBrightness(0); },
        [=]() { den_phong_ngu->setBrightness(5); },
        [=]() { dieu_hoa_phong_khach->setTargetTemp(26.0f); },
        [=]() { dieu_hoa_phong_khach->toggle(); }
    });

    myHub.allStatus();

    return 0;
}