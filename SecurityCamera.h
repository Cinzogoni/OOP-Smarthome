#ifndef SECURITY_CAMERA_H
#define SECURITY_CAMERA_H

#include "Device.h"

class SecurityCamera : public Device{
    private:
        bool isAuthenticated;
        bool isRecording;
        string location;

    public:
        SecurityCamera(int id, const string& name, const string& loc);
        void authenticate(const string& password);
        void toggle() override;
        void startRecording();
        void getStatus() override;
};

#endif