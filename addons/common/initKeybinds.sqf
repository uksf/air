#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Open Ramp
["UKSF Air", QGVAR(ramp), "Open/Close Ramp", {false}, {call FUNC(ramp); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
