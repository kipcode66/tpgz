#pragma once

#include <stdint.h>

extern bool a_held;
extern uint16_t current_input;

namespace Controller {
    enum Button {
        DPAD_LEFT = 0,
        DPAD_RIGHT = 1,
        DPAD_DOWN = 2,
        DPAD_UP = 3,
        PLUS = 4,
        TWO = 5,
        ONE = 6,
        B = 7,
        A = 8,
        MINUS = 9,
        Z = 10,
        C = 11,
        HOME = 12,
    };
    bool button_is_pressed(int idx);
    bool button_is_down(int idx);
    bool button_is_held(int idx);
    uint16_t get_current_inputs();
}  // namespace Controller