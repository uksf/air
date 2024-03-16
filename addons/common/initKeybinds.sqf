#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Open Ramp
["UKSF Air", QGVAR(ramp), "Open/Close Ramp", {false}, {call FUNC(ramp); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// Paradrop internal cargo
["UKSF Air", QGVAR(dropCargoSingle), "Drop Cargo (Single)", {false}, {[0] call FUNC(paradropCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(dropCargoAll), "Drop Cargo (All)", {false}, {[1] call FUNC(paradropCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
