#ifndef MACRO_SYSTEM_H
#define MACRO_SYSTEM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class MacroSystem {
    map<string, vector<function<void()>>> macros;

    public:
        // NẠP HÀNH ĐỘNG
        void addMacro(const string& name, vector<function<void()>> actions) {
        macros[name] = actions;
        }

        // THỰC THI HÀNH ĐỘNG
        void execute(const string& name){
            auto it = macros.find(name);
            if(it == macros.end()){
                cout << "[MACRO]" << "Khong tim thay macro " << name << endl;
                return;
            }

            for(size_t i = 0; i < it->second.size(); i++){
                cout << "Buoc " << (i+1) << ": " << endl;
                it->second[i]();
            }
        }

        //DANH SÁCH HÀNH ĐỘNG
        void listMacro(){
            cout << "List macros: " << endl;
            for(auto &macro: macros){
                cout << macro.first << " - " << macro.second.size() << " buoc" << endl;
            
            }
        }
};

#endif