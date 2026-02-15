#define IS_ATTACHED_TO_CATAPULT				(player getVariable ["carrierCatapultAttached",false])
#define ATTACHED_TO_CATAPULT(state)			(player setVariable ["carrierCatapultAttached",state])

#define LAUNCH_CANCELLED					-1
#define LAUNCH_STARTED						0
#define LAUNCH_COMPLETED					25

#define SET_CATAPULT_STATE(id)				(player setVariable ["carrierCatapultState",id])
#define GET_CATAPULT_STATE					(player getVariable ["carrierCatapultState",LAUNCH_CANCELLED])

#define CATAPULT_NONE						-1

#define SET_CATAPULT_ID(id)					(player setVariable ["carrierCatapultID",id])
#define SET_CATAPULT_LAST_ID(id)			(player setVariable ["carrierCatapultLastID",id])
#define GET_CATAPULT_ID						(player getVariable ["carrierCatapultID",CATAPULT_NONE])
#define GET_CATAPULT_LAST_ID				(player getVariable ["carrierCatapultLastID",CATAPULT_NONE])

#define SET_CATAPULTS_DATA(trigger,data)	(trigger setVariable ["bis_carrierCatapultsData",data])
#define GET_CATAPULTS_DATA(trigger)			(trigger getVariable ["bis_carrierCatapultsData",[]])

#define SET_TRIGGER(trigger)				(player setVariable ["bis_carrierDeckTrigger",trigger])
#define GET_TRIGGER							(player getVariable ["bis_carrierDeckTrigger",objNull])

#define GET_CATAPULT_ID						([] call bis_fnc_carrier01CatapultID)
#define GET_CATAPULT_DATA					(GET_CATAPULTS_DATA(GET_TRIGGER) param [GET_CATAPULT_ID,[]])

#define GET_ACTION_ID(object)				(object getVariable ["bis_carrierCatapultActionID",-1])
#define SET_ACTION_ID(object,id)			(object setVariable ["bis_carrierCatapultActionID",id])

#define SET_AIRPLANE(trigger,object)		(trigger setVariable ["bis_carrierCatapultPlane",_target])
#define GET_AIRPLANE(trigger)				(trigger getVariable ["bis_carrierCatapultPlane",objNull])

#define ATTACH_MAX_SPEED					50

#define ANIMATE_UP							10
#define ANIMATE_DOWN						0

#define ANIMATE_DEFLECTOR(part,anim,state)	([part,anim,state] call BIS_fnc_Carrier01AnimateDeflectors)