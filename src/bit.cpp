#include <stdio.h>
#include "bit.h"
#include <string.h>
#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/system.h"
#include "libtpw_c/include/controller.h"
#include "fifo_queue.h"
#include "controller.h"
#include "log.h"
#include "utils.h"
#include "fs.h"
#include "font.h"

#define VOID_HEIGHT -2098.58f
#define NORMAL_ACC -3.4f
#define NORMAL_TERM_VEL -200.0f
#define BOOTS_ACC -7.65f
#define BOOTS_TERM_VEL -300.0f
#define TARGET_FRAME 62

bool inject_bit_flag = false;
extern Font font;

namespace BiTIndicator {
    using namespace Controller;

    static char buf[30];

    void set_camera_angle_position() {
        tp_zelAudio.link_debug_ptr->position = {466.622467f, 319.770752f, -11651.3867f};
        tp_zelAudio.link_debug_ptr->facing = 32000;
        tp_matrixInfo.matrix_info->camera0 = 465.674622f;
        tp_matrixInfo.matrix_info->camera1 = 421.052704f;
        tp_matrixInfo.matrix_info->camera2 = -11651.0684f;
        tp_matrixInfo.matrix_info->camera3 = 735.525391f;
        tp_matrixInfo.matrix_info->camera4 = 524.418701f;
        tp_matrixInfo.matrix_info->camera5 = -11576.4746f;
        tp_matrixInfo.matrix_info->camera6 = 1.36201766f;
        tp_matrixInfo.matrix_info->camera7 = 280.0f;
    }

    void run() {
        Log log;

        float dt = 0.0f;

        if (tp_zelAudio.link_debug_ptr != NULL && tp_gameInfo.momentum_ptr != NULL) {
            const bool has_boots = (tp_zelAudio.link_debug_ptr->current_boots & 0x02) != 0;
            const float term_vel = has_boots ? BOOTS_TERM_VEL : NORMAL_TERM_VEL;
            const float acc = has_boots ? BOOTS_ACC : NORMAL_ACC;
            const float v_y1 = tp_gameInfo.momentum_ptr->link_momentum.y;
            const float dist_from_last_ground = (tp_zelAudio.link_debug_ptr->position.y - tp_zelAudio.link_debug_ptr->last_ground_y_pos_void);

            // Calculate how many frames before reaching terminal velocity
            float dt_1 = (term_vel - v_y1) / acc;
            // Calculate how much height we will lose during that period
            float x_dt_1 = dist_from_last_ground + (v_y1 + acc * dt_1) * dt_1;

            // If we reach terminal velocity after the voiding point, ...
            if (x_dt_1 <= VOID_HEIGHT) {
                // ... just calculate the time remaining before void using the quadratic formula
                dt = - (v_y1 + tp_sqrt((double)(v_y1 * v_y1 + 2 * acc * (x_dt_1 - VOID_HEIGHT)))) / acc;
            } else {
                // ... else, the time remaining before the void is the time to reach terminal velocity + linear time at velocity
                dt = dt_1 + (x_dt_1 - VOID_HEIGHT) / term_vel;
            }

            if (tp_homeMenuSts.is_visible == 0 && !tp_fopScnRq.isLoading) {
                sprintf(buf, "frames before void: %d", (int)dt);
                log.PrintLog(buf, DEBUG);
            }

            if (strcmp((const char *)tp_gameInfo.current_stage, "F_SP104") == 0 && button_is_down(HOME) && tp_homeMenuSts.is_visible == 0 && !tp_fopScnRq.isLoading) {
                if ((int)dt == TARGET_FRAME) {
                    sprintf(buf, "Got it");
                }
                if ((int)dt > TARGET_FRAME) {
                    sprintf(buf, "%d frames early", (int)dt - TARGET_FRAME);
                }
                if ((int)dt < TARGET_FRAME) {
                    sprintf(buf, "%d frames late", TARGET_FRAME - (int)dt);
                }
                FIFOQueue::push(buf, Queue);
            }
        }
    }
}  // namespace GorgeVoidIndicator
