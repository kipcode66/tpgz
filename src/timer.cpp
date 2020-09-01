#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/system.h"
#include "font.h"
#include "timer.h"

bool timer_visible;
extern bool g_drop_shadows;

namespace Timer {
    static int timer_frame = 0;
    static int current_frame = 0;
    static int previous_frame = 0;
    static char timer[5];

    void render(Font& font) {
        current_frame = TP::get_frame_count();
        if (timer_started) {
            timer_frame += current_frame - previous_frame;
        }

        if (reset_timer) {
            timer_frame = 0;
            reset_timer = false;
            timer_started = false;
        }
        sprintf(timer, "%d", timer_frame);
        previous_frame = current_frame;
        font.gz_renderChars(timer, 525.0f, 420.0f, 0XFFFFFFFF, g_drop_shadows);

    }  // namespace Timer
}  // namespace Timer