#include <iostream>
#include "SmartHomeHub.h"
#include "MacroSystem.h"
#include "Light.h"
#include "Thermostat.h"
#include "SecurityCamera.h"
#include "SmartLock.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    SmartHomeHub myHub("TONG DAI DAY!");

    Light *den_phong_khach = new Light(1, "Den Phong Khach", 90);
    Thermostat *dieu_hoa_phong_khach = new Thermostat(2, "Dieu Hoa Phong Khach", 30.0f, 28.5f);
    SecurityCamera *cam_phong_khach = new SecurityCamera(5, "Cam Phong Khach", "Phong Khach");
    SmartLock *khoa_cua_chinh = new SmartLock(7, "Cua Chinh", false);


    Light *den_phong_ngu = new Light(3, "Den Phong Ngu", 70);
    Thermostat *dieu_hoa_phong_ngu = new Thermostat(4, "Dieu Hoa Phong Ngu", 25.0f, 22.0f);
    SecurityCamera *cam_phong_ngu = new SecurityCamera(6, "Cam Phong Ngu", "Phong Ngu");


    myHub.addDevice(den_phong_khach);
    myHub.addDevice(dieu_hoa_phong_khach);
    myHub.addDevice(cam_phong_khach);
    myHub.addDevice(khoa_cua_chinh);

    myHub.addDevice(den_phong_ngu);
    myHub.addDevice(dieu_hoa_phong_ngu);
    myHub.addDevice(cam_phong_ngu);

    myHub.getMacroSystem().addMacro("Chuc Ngu Ngon", vector<function<void()>>{
        [=]() { den_phong_khach->setBrightness(0);},
        [=]() { den_phong_ngu->setBrightness(5);},
        [=]() { cam_phong_khach->authenticate("admin321");},
        [=]() { dieu_hoa_phong_khach->setTargetTemp(26.0f);},
        [=]() { dieu_hoa_phong_khach->toggle();},
        [=]() { cam_phong_ngu->authenticate("admin300");},
        [=]() { khoa_cua_chinh->unlocked();} 
    });

    myHub.getMacroSystem().execute("Chuc Ngu Ngon");
    myHub.allStatus();
    cout << string(50, '=') << endl;

    cout << "-----[CAMERA ERROR] TRUY CAP TRAI PHEP VAO THIET BI CAMERA-----" << endl;
    try{
        SecurityCamera* cam_trom = new SecurityCamera(99, "Cam An Danh", "Phong Ngu");
        cam_trom->authenticate("bac123");
        cam_trom->toggle();

    }catch(const exception& e){
        cout << "Ket qua: " << e.what() << endl;
    }

    cout << "-----[THERMOSTAT ERROR] VONG LAP PHAN HOI-----" << endl;
    try{
        dieu_hoa_phong_khach->forceFeedbackLoop();
    }catch(const exception& e){
        cout << "Ket qua: " << e.what() << endl;
    }

    return 0;
}