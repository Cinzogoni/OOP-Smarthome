#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
using namespace std;

class Device{
    protected:
        int id;
        string name;
        bool isOn;
        bool isError;

    public:
        Device();                    
        Device(int id, string name);       
        virtual ~Device();                 

        virtual void toggle() = 0;
        virtual void getStatus() = 0;

        void operator!();                  

        string getName() const { return name; }
        int getId() const { return id; }
        bool getIsOn() const { return isOn; }
        bool getIsError() const;
};

#endif