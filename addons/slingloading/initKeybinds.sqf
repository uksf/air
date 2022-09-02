#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Operate cargo ropes
["UKSF Air", QGVAR(operateRopesAll), ["Operate Ropes (All)", "Operate ropes based on current action context for all ropes. Operating without an action selected will release cargo"], {false}, {["All"] call FUNC(operateRopes); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(operateRopesFront), ["Operate Ropes (Front)", "Operate ropes based on current action context for front rope. Operating without an action selected will release cargo"], {false}, {["Front"] call FUNC(operateRopes); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(operateRopesCenter), ["Operate Ropes (Center)", "Operate ropes based on current action context for center rope. Operating without an action selected will release cargo"], {false}, {["Center"] call FUNC(operateRopes); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air", QGVAR(operateRopesRear), ["Operate Ropes (Rear)", "Operate ropes based on current action context for rear rope. Operating without an action selected will release cargo"], {false}, {["Rear"] call FUNC(operateRopes); true}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
