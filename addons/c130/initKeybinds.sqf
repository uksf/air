#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Paradrop internal cargo (Only works with C-130)
["UKSF Air C-130", QGVAR(dropCargoSingle), "Drop Cargo (Single)", {false}, {[0] call FUNC(paradropCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air C-130", QGVAR(dropCargoAll), "Drop Cargo (All)", {false}, {[1] call FUNC(paradropCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
