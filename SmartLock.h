#ifndef SMART_LOCK_H
#define SMART_LOCK_H

#include "Device.h"

class SmartLock : public Device{
    private:
        bool isLocked;

    public:
        SmartLock(int id, string name, bool lockedStatus = false);

        void toggle() override;
        void getStatus() override;

        void locked();
        void unlocked();

};

#endif