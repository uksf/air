#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Release slung cargo
["UKSF Air", QGVAR(releaseCargoAll), "Release Cargo (All)", {false}, {["All"] call FUNC(releaseCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(releaseCargoFront), "Release Cargo (Front)", {false}, {["Front"] call FUNC(releaseCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(releaseCargoCenter), "Release Cargo (Center)", {false}, {["Center"] call FUNC(releaseCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(releaseCargoRear), "Release Cargo (Rear)", {false}, {["Rear"] call FUNC(releaseCargo); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// Open Ramp
["UKSF Air", QGVAR(ramp), "Open/Close Ramp", {false}, {call FUNC(ramp); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
