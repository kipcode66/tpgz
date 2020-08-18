#include <stdio.h>
#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/system.h"
#include "libtpw_c/include/flag.h"
#include "controller.h"
#include "font.h"
#include "input_viewer.h"

bool iv_visible;

namespace InputViewer {
    void render(Font& font) {
        using namespace Controller;

        if (button_is_down(A)) {
            font.renderChars("A", 150.0f, 440.0f, 0x00CC00FF);
        }

        if (button_is_down(B)) {
            font.renderChars("B", 165.f, 440.0f, 0xDC143CFF);
        }

        if (button_is_down(ONE)) {
            font.renderChars("1", 180.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(TWO)) {
            font.renderChars("2", 195.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(Z)) {
            font.renderChars("Z", 210.f, 440.0f, 0x8A2BE2FF);
        }

        if (button_is_down(C)) {
            font.renderChars("C", 325.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(PLUS)) {
            font.renderChars("+", 240.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(MINUS)) {
            font.renderChars("-", 255.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(DPAD_LEFT)) {
            font.renderChars("DL", 280.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(DPAD_DOWN)) {
            font.renderChars("DD", 305.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(DPAD_RIGHT)) {
            font.renderChars("DR", 330.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(DPAD_UP)) {
            font.renderChars("DU", 355.f, 440.0f, 0xFFFFFFFF);
        }

        if (button_is_down(HOME)) {
            font.renderChars("H", 380.f, 440.0f, 0x8A2BE2FF);
        }
    }
}  // namespace InputViewer