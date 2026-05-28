#include "Light.h"
#include "Thermostat.h"
#include "MacroSystem.h"

int main(){
MacroSystem phongNgu;
    Light den(1, "Den Phong Ngu", 15);
    Thermostat dieuHoa(2, "Dieu Hoa Phong Ngu", 28.0f, 24.0f);

    phongNgu.addMacro("Chuc Ngu Ngon", {
        [&]() { den.toggle(); },
        [&]() { dieuHoa.setTargetTemp(22.0f); },
        [&]() { dieuHoa.toggle(); }
    });

    phongNgu.listMacro();
    phongNgu.execute("Chuc Ngu Ngon");

    return 0;
}