#include <state_machine.h>

State_t state = safe_locked;

void state_machine(Event_t event)
// Zustände überprüfen
{
    switch (state)
    {
    case safe_locked:
        if (input1_accepted == event)
        {
            state = level1_unlocked;
        }

        break;
    case level1_unlocked:
        if (input2_accepted == event)
        {
            state = level2_unlocked;
        }
        else if (input_refused == event)
        {
            state = safe_locked;
        }
        break;
    case level2_unlocked:
        if (input3_accepted == event)
        {
            state = level3_unlocked;
        }
        else if (input_refused == event)
        {
            state = safe_locked;
        }
        break;
        // Zustand in dem ich mich befinde
    case level3_unlocked:
        // Wie ich in einen anderen Zustand komme
        if (open_door == event)
        {
            // in welchen Zustand ich kommen will
            state = safe_open;
        }
        break;
    case safe_open:
        if (close_door == event)
        {
            state = safe_locked;
        }
        break;
    }
}