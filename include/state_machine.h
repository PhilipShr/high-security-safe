#ifndef STATE_MACHINE
#define STATE_MACHINE

// States definieren
typedef enum
{
    safe_locked,
    level1_unlocked,
    level2_unlocked,
    level3_unlocked,
    safe_open
} State_t;
// transition events definieren können öfter verwendet werden
typedef enum
{
    input1_accepted,
    input2_accepted,
    input3_accepted,
    open_door,
    close_door,
    input_refused
} Event_t;

void state_machine(Event_t event);

extern State_t state;

#endif STATE_MACHINE