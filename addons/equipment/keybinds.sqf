#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// {
//     _x params ["_keybindName", "_displayName", "_animations"];

//     ["UKSF Air Marshalling", format [QGVAR(marshallActions_%1), _keybindName], _displayName, {false}, {
//         if !([ACE_player, objNull, []] call ace_common_fnc_canInteractWith) exitWith {false};

//         if (hmd ACE_player != QGVAR(marshallSticks)) exitWith {false};

//         systemChat str _animations;
//         [ACE_player, _animations] call FUNC(marshallCommand);
//         true
//     }, [0, [false, false, false]]] call CBA_fnc_addKeybind;
// } forEach [
//     ["enginesOff", "Engines Off", ["Acts_JetsMarshallingEnginesOff_in", QGVAR(takeMarshallSticks)]],
//     ["enginesOn", "Engines On", ["Acts_JetsMarshallingEnginesOn_in", QGVAR(takeMarshallSticks)]],
//     ["straight", "Straight", ["Acts_JetsMarshallingStraight_in", QGVAR(takeMarshallSticks)]],
//     ["slow", "Slow", ["Acts_JetsMarshallingSlow_in", QGVAR(takeMarshallSticks)]],
//     ["right", "Right", ["Acts_JetsMarshallingRight_in", QGVAR(takeMarshallSticks)]],
//     ["left", "Left", ["Acts_JetsMarshallingLeft_in", QGVAR(takeMarshallSticks)]],
//     ["stop", "Stop", ["Acts_JetsMarshallingStop_in", QGVAR(takeMarshallSticks)]],
//     ["emergencyStop", "Emergency Stop", ["Acts_JetsMarshallingEmergencyStop_in", QGVAR(takeMarshallSticks)]],
//     ["cancel", "Cancel", ["", "default"]]
// ];

["UKSF Air Marshalling", QGVAR(marshallActions_enginesOff), "Engines Off", {true}, {["Acts_JetsMarshallingEnginesOff_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_enginesOn), "Engines On", {true}, {["Acts_JetsMarshallingEnginesOn_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_straight), "Straight", {true}, {["Acts_JetsMarshallingStraight_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_slow), "Slow", {true}, {["Acts_JetsMarshallingSlow_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_right), "Right", {true}, {["Acts_JetsMarshallingRight_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_left), "Left", {true}, {["Acts_JetsMarshallingLeft_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_stop), "Stop", {true}, {["Acts_JetsMarshallingStop_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_emergencyStop), "Emergency Stop", {true}, {["Acts_JetsMarshallingEmergencyStop_in", QGVAR(takeMarshallSticks)] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF Air Marshalling", QGVAR(marshallActions_cancel), "Cancel", {true}, {["", "default"] call FUNC(marshallActionKeybind)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
