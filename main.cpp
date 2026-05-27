#include "Light.h"
#include "Thermostat.h"

int main(){
    // Light *den_phong_ngu = new Light(10,"Den phong ngu", 85);
    // den_phong_ngu->toggle();
    // den_phong_ngu->getStatus();
    // delete den_phong_ngu;

    // Light *den_phong_khach = new Light(11,"Den phong khach", 90);
    // den_phong_khach->toggle();
    // den_phong_khach->setBrightness(65);
    // den_phong_khach->getStatus();
    // delete den_phong_khach;

    Thermostat *nhiet_do_phong_ngu = new Thermostat(1,"May dieu hoa phong ngu",30.0f, 24.5f);
    nhiet_do_phong_ngu->toggle();
    nhiet_do_phong_ngu->getStatus();
    nhiet_do_phong_ngu->setTargetTemp(26.5f);
    nhiet_do_phong_ngu->updateEnvironment();
    nhiet_do_phong_ngu->getStatus();
    delete nhiet_do_phong_ngu;

    return 0;
}