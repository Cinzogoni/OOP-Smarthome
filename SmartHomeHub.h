#ifndef SMART_HOME_HUB_H
#define SMART_HOME_HUB_H

#include "Device.h"
#include "MacroSystem.h"

using namespace std;

    class SmartHomeHub {
        private:
            vector<Device*> devices;
            MacroSystem     macroSystem;
            string          hubName;

        public:
            SmartHomeHub(const string& name); 

            void addDevice(Device* device);
            void toggleDevice(int id);
            void malfunctionDevice(int id);
            void allStatus();

            MacroSystem& getMacroSystem() { return macroSystem; }
};

#endif