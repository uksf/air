// Route 2 in-place patches: A2A munitions that lack ACE missile guidance entirely
// (no ace_missile_* duplicate exists). Inject ace_missileguidance + ace_frag_* directly
// onto the base class so existing platforms get prox/frag without rewiring magazines.

// CUP Stinger MANPADS / static AA (separate inheritance line from M_Titan_AA).
class CUP_M_Stinger_AA : MissileBase {
    indirectHit = 50;
    indirectHitRange = 3;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 1000;
    ace_frag_metal = 2000;
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_manpad) };
    class ace_missileguidance : ace_missileguidance_type_Stinger { enabled = 1; };
};

// AIM-9L Sidewinder (CUP F-15/F-16/A-10): 9.4kg WDU-17 annular blast-frag.
class CUP_M_AIM_9L_Sidewinder_AA : MissileBase {
    indirectHit = 85;
    indirectHitRange = 4;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 1700;
    ace_frag_metal = 3600;
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_sr) };
    class ace_missileguidance : ace_missileguidance_type_Sidewinder { enabled = 1; };
};

// RIM-7 Sea Sparrow (CUP frigate naval AA): WDU-27 ~39.5kg continuous-rod warhead.
class CUP_M_RIM7_Frigate : MissileBase {
    indirectHit = 240;
    indirectHitRange = 8;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 10000;
    ace_frag_metal = 28000;
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_naval_mr) };
    class ace_missileguidance : ace_missileguidance_type_ESSM { enabled = 1; };
};

// 3CB BAF Phalanx CIWS RIM-116 RAM. Inherits from M_Air_AA (Sidewinder-class) by default;
// override warhead values with RAM chemistry and switch guidance to RAM type.
class M_RIM_116 : M_Air_AA {
    indirectHit = 110;
    indirectHitRange = 5;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 3600;
    ace_frag_metal = 5500;
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_naval_ciws) };
    class ace_missileguidance : ace_missileguidance_type_RAM { enabled = 1; };
};

// HAFM naval ESSM. Inherits from M_Zephyr (AMRAAM-A class) by default; override with
// ESSM-class warhead values and switch guidance to type_ESSM.
class HAFM_RIM162_ESSM : M_Zephyr {
    indirectHit = 240;
    indirectHitRange = 8;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 10000;
    ace_frag_metal = 28000;
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_naval_mr) };
    class ace_missileguidance : ace_missileguidance_type_ESSM { enabled = 1; };
};

// 9M311 Tunguska SAM (CUP). ~9kg HE-frag warhead with rod fragments + tracker. Bigger
// than Stinger inherited from M_Titan_AA but smaller than naval CIWS - own profile.
class CUP_M_9M311_Tunguska_AA : M_Titan_AA {
    indirectHit = 100;
    indirectHitRange = 5;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 2700;
    ace_frag_metal = 6300;
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_naval_ciws) };
};
