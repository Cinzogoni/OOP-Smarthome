#include "Light.h"

int main(){
    Light *den_phong_ngu = new Light(10,"Den phong ngu", 85);
    den_phong_ngu->toggle();
    den_phong_ngu->getStatus();
    delete den_phong_ngu;

    Light *den_phong_khach = new Light(11,"Den phong khach", 90);
    den_phong_khach->toggle();
    den_phong_khach->setBrightness(65);
    den_phong_khach->getStatus();
    delete den_phong_khach;


    return 0;
}