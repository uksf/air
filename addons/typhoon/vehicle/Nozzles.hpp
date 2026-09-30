// Nozzle segments and petals. EAWS takes 0.9-1.2 s to open them, but the reheat flame appears at
// once, so the flame showed through a closed nozzle. Redefined in full so no parent declaration is needed.
#define NOZZLE_SOURCE(NAME) class NAME { \
    source = "user"; \
    animPeriod = 0.3; \
    initPhase = 0; \
}
#define NOZZLE_SIDE(SIDE) \
    NOZZLE_SOURCE(engine_nozzle_##SIDE##_1); NOZZLE_SOURCE(engine_nozzle_##SIDE##_2); \
    NOZZLE_SOURCE(engine_nozzle_##SIDE##_3); NOZZLE_SOURCE(engine_nozzle_##SIDE##_4); \
    NOZZLE_SOURCE(engine_nozzle_##SIDE##_5); NOZZLE_SOURCE(engine_nozzle_##SIDE##_6); \
    NOZZLE_SOURCE(engine_nozzle_##SIDE##_7); NOZZLE_SOURCE(engine_nozzle_##SIDE##_8)
#define NOZZLE_RING(RING) \
    NOZZLE_SOURCE(nozzle_##RING##_1); NOZZLE_SOURCE(nozzle_##RING##_2); NOZZLE_SOURCE(nozzle_##RING##_3); \
    NOZZLE_SOURCE(nozzle_##RING##_4); NOZZLE_SOURCE(nozzle_##RING##_5); NOZZLE_SOURCE(nozzle_##RING##_6); \
    NOZZLE_SOURCE(nozzle_##RING##_7); NOZZLE_SOURCE(nozzle_##RING##_8); NOZZLE_SOURCE(nozzle_##RING##_9); \
    NOZZLE_SOURCE(nozzle_##RING##_10); NOZZLE_SOURCE(nozzle_##RING##_11); NOZZLE_SOURCE(nozzle_##RING##_12)

NOZZLE_SIDE(l);
NOZZLE_SIDE(r);
NOZZLE_RING(1);
NOZZLE_RING(2);
NOZZLE_SOURCE(nozzle_1_13);
NOZZLE_SOURCE(nozzle_1_14);
