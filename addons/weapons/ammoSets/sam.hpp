// Route 2 in-place patches: A2A munitions that lack ACE missile guidance entirely
// (no ace_missile_* duplicate exists). Inject ace_missileguidance + ace_frag_* directly
// onto the base class so existing platforms get prox/frag without rewiring magazines.

// CUP Stinger MANPADS / static AA (separate inheritance line from M_Titan_AA).
class CUP_M_Stinger_AA : MissileBase {
    indirectHit = 50;
    indirectHitRange = 3;
    A2A_FRAG(1000,2000,manpad);
    ACE_GUIDANCE(Stinger);
};

// 9K32 Strela-2 (SA-7): early-gen IR MANPADS, ~1.17kg HE-frag warhead — significantly
// smaller than Stinger. Leaf-override M_Titan_AA so we don't over-spec the warhead.
class CUP_M_9K32_Strela_2_AA : M_Titan_AA {
    indirectHit = 35;
    indirectHitRange = 2;
    A2A_FRAG(1170,2400,manpad);
    ACE_GUIDANCE(Stinger);
};

// 9K38 Igla (SA-18): improved IR MANPADS, ~1.27kg HE-frag warhead — between Strela-2
// and Stinger. Leaf-override for accurate per-missile warhead spec.
class CUP_M_9K38_Igla_AA : M_Titan_AA {
    indirectHit = 40;
    indirectHitRange = 2;
    A2A_FRAG(1270,2700,manpad);
    ACE_GUIDANCE(Stinger);
};

// RHS Strela-2 (SA-7) — same warhead as CUP variant.
class rhs_ammo_9k32 : M_Titan_AA {
    indirectHit = 35;
    indirectHitRange = 2;
    A2A_FRAG(1170,2400,manpad);
    ACE_GUIDANCE(Stinger);
};

// AIM-9L Sidewinder (CUP F-15/F-16/A-10): 9.4kg WDU-17 annular blast-frag.
class CUP_M_AIM_9L_Sidewinder_AA : MissileBase {
    indirectHit = 85;
    indirectHitRange = 4;
    A2A_FRAG(1700,3600,sr);
    ACE_GUIDANCE(Sidewinder);
};

// RIM-7 Sea Sparrow (CUP frigate naval AA): WDU-27 ~39.5kg continuous-rod warhead.
class CUP_M_RIM7_Frigate : MissileBase {
    indirectHit = 240;
    indirectHitRange = 8;
    A2A_FRAG(10000,28000,naval_mr);
    ACE_GUIDANCE(ESSM);
};

// 3CB BAF Phalanx CIWS RIM-116 RAM. Inherits from M_Air_AA (Sidewinder-class) by default;
// override warhead values with RAM chemistry and switch guidance to RAM type.
class M_RIM_116 : M_Air_AA {
    indirectHit = 110;
    indirectHitRange = 5;
    A2A_FRAG(3600,5500,naval_ciws);
    ACE_GUIDANCE(RAM);
};

// HAFM naval ESSM. Inherits from M_Zephyr (AMRAAM-A class) by default; override with
// ESSM-class warhead values and switch guidance to type_ESSM.
class HAFM_RIM162_ESSM : M_Zephyr {
    indirectHit = 240;
    indirectHitRange = 8;
    A2A_FRAG(10000,28000,naval_mr);
    ACE_GUIDANCE(ESSM);
};

// 9M311 Tunguska SAM (CUP). ~9kg HE-frag warhead with rod fragments. Real-life is
// radio-command + radar tracking - no exact ACE type. type_RAM is the closest behavioural
// match (similar warhead chemistry, agile flap rates, 7m prox). The 9M311M variant
// inherits this override.
class CUP_M_9M311_Tunguska_AA : M_Titan_AA {
    indirectHit = 100;
    indirectHitRange = 5;
    A2A_FRAG(2700,6300,naval_ciws);
    ACE_GUIDANCE(RAM);
};
