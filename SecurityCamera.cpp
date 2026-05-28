#include <iostream>
#include "SecurityCamera.h"
#include "SmartHomeExceptions.h"

using namespace std;

SecurityCamera::SecurityCamera(int id, const string& name, const string& loc)
    : Device(id, name), isAuthenticated(false), isRecording(false), location(loc) {}

void SecurityCamera::authenticate(const string& password) {
    if (password == "admin321") {
        isAuthenticated = true;
        cout << "[CAM] " << "Xac thuc thanh cong!" << endl;
    }else{
        isAuthenticated = false;
        cout << "[CAM] " << "Xac thuc that bai!" << endl;
    }

}

void SecurityCamera::toggle() {
    if (isError) {
        cout << "[!]" << name << " loi khong the mo" << endl;
        return;
    }

   if (!isAuthenticated) {
            throw UnauthorizedAccessException(name + " tai " + location);
    }
    isRecording = !isRecording;
    isOn = isRecording;
    cout << "[CAM] " << name << " - " << location << " - "
         << (isRecording ? "BAT GHI HINH" : "DUNG GHI HINH") << endl;
}

void SecurityCamera::startRecording() {
        if (!isAuthenticated)
            throw UnauthorizedAccessException(name + " tai " + location);
        isRecording = true;
        isOn = true;
        cout << "  [CAM] '" << name << "' bat dau ghi hinh." << endl;
    }

void SecurityCamera::getStatus(){
    cout << "[CAM] " << "Id: " << id << ", Ten: " << name
         << ", Vi tri: " << location 
         << ", Xac thuc: "<<(isAuthenticated ? "Roi": "Chua")
         << ", Trang thai: " << (isRecording ? "Dang ghi hinh, " : "Khong ghi hinh, ")
         << (isError ? "[TRUC TRAC]" : "[ON DINH]") << endl;  
}