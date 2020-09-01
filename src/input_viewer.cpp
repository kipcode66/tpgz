#include <stdio.h>
#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/system.h"
#include "libtpw_c/include/flag.h"
#include "controller.h"
#include "font.h"
#include "input_viewer.h"

bool iv_visible;
extern bool g_drop_shadows;

namespace InputViewer {
    void render(Font& font) {
        using namespace Controller;

        if (button_is_down(A)) {
            font.gz_renderChars("A", 150.0f, 440.0f, 0x00CC00FF, g_drop_shadows);
        }

        if (button_is_down(B)) {
            font.gz_renderChars("B", 165.f, 440.0f, 0xDC143CFF, g_drop_shadows);
        }

        if (button_is_down(ONE)) {
            font.gz_renderChars("1", 180.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(TWO)) {
            font.gz_renderChars("2", 195.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(Z)) {
            font.gz_renderChars("Z", 210.f, 440.0f, 0x8A2BE2FF, g_drop_shadows);
        }

        if (button_is_down(C)) {
            font.gz_renderChars("C", 325.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(PLUS)) {
            font.gz_renderChars("+", 240.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(MINUS)) {
            font.gz_renderChars("-", 255.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(DPAD_LEFT)) {
            font.gz_renderChars("DL", 280.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(DPAD_DOWN)) {
            font.gz_renderChars("DD", 305.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(DPAD_RIGHT)) {
            font.gz_renderChars("DR", 330.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(DPAD_UP)) {
            font.gz_renderChars("DU", 355.f, 440.0f, 0xFFFFFFFF, g_drop_shadows);
        }

        if (button_is_down(HOME)) {
            font.gz_renderChars("H", 380.f, 440.0f, 0x8A2BE2FF, g_drop_shadows);
        }
    }
}  // namespace InputViewer