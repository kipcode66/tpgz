#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/system.h"
#include "libtpw_c/include/controller.h"
#include "menu.h"
#include "controller.h"
#include "fifo_queue.h"
#include "utils/cursor.hpp"
#include "utils/lines.hpp"
#include "gorge.h"
#include "rollcheck.h"
#include "save_injector.h"
#include "log.h"
#include "fs.h"
#define LINES 24

static Cursor cursor = {0,0};
static CameraMatrix camera = {0, 0, 0, 0, 0, 0, 0, 0};
static uint16_t angle = 0;
static Vec3 position = {0, 0, 0};
bool init_once = false;
bool wii_any_saves_visible;

Line lines[LINES] = {
    {"sewers", WII_SEWERS_INDEX, "The sewers segment at the beginning"},
    {"sword and shield skip", WII_HUGO_INDEX, "Hangin' with Hugo"},
    {"faron", WII_FARON_INDEX, "The Faron Twilight Segment"},
    {"grove", WII_GROVE_INDEX, "The lost woods segment"},
    {"forest temple", WII_FT_INDEX, "The Forest Temple segment"},
    {"lanayru 1", WII_LAN1_INDEX, "The 1st segment in lanayru twilight"},
    {"eldin twilight", WII_ELDIN_INDEX, "The eldin twilight segment"},
    {"midna dive", WII_MD_INDEX, "Divin' into lakebed"},
    {"lakebed 1", WII_LB1_INDEX, "Jake, please be nice."},
    {"lanayru 2", WII_LAN2_INDEX, "Clearing lanayru twilight"},
    {"lakebed 2", WII_LB2_INDEX, "The second lakebed segment"},
    {"morpheel", WII_MORPHEEL_INDEX, "The segment before morpheel"},
    {"MDH", WII_MDH_INDEX, "The midna's desperate hour segment"},
    {"post MDH", WII_POST_MDH_INDEX, "After MDH"},
    {"arbiter's grounds", WII_AG1_INDEX, "The Arbiter's Grounds segment"},
    {"arbiter's 2", WII_AG2_INDEX, "The second part of arbiters"},
    {"post arbiters", WII_POST_AG_INDEX, "The segment after arbiter's"},
    {"snowpeak ruins", WII_SPR_INDEX, "The Snowpeak Ruins dungeon segment"},
    {"city in the sky 1", WII_CITS1_INDEX, "The first City in the Sky segment"},
    {"city in the sky 2", WII_CITS2_INDEX, "The second City in the Sky segment"},
    {"palace of twilight", WII_POT1_INDEX, "The first part of the Twilight segment"},
    {"palace of twilight end", WII_POT2_INDEX, "The end of Palace of Twilight"},
    {"hyrule castle", WII_HC1_INDEX, "The Hyrule Castle segment"},
    {"final tower climb", WII_HC2_INDEX, "The tower climb before the final boss fights"}};

void default_load() {
    practice_file.inject_options_before_load = SaveInjector::inject_default_before;
    practice_file.inject_options_during_load = SaveInjector::inject_default_during;
    practice_file.inject_options_after_load = SaveInjector::inject_default_after;
    practice_file.inject_options_after_counter = 0;
    inject_save_flag = true;
    fifo_visible = true;
    prac_visible = false;
    wii_any_saves_visible = false;
    mm_visible = false;
    init_once = false;
}

void set_camera_angle_position() {
    tp_matrixInfo.matrix_info->camera0 = camera.c0;
    tp_matrixInfo.matrix_info->camera1 = camera.c1;
    tp_matrixInfo.matrix_info->camera2 = camera.c2;
    tp_matrixInfo.matrix_info->camera3 = camera.c3;
    tp_matrixInfo.matrix_info->camera4 = camera.c4;
    tp_matrixInfo.matrix_info->camera5 = camera.c5;
    tp_matrixInfo.matrix_info->camera6 = camera.c6;
    tp_matrixInfo.matrix_info->camera7 = camera.c7;
    tp_zelAudio.link_debug_ptr->facing = angle;
    tp_zelAudio.link_debug_ptr->position = position;
}

void set_angle_position() {
    tp_zelAudio.link_debug_ptr->facing = angle;
    tp_zelAudio.link_debug_ptr->position = position;
}

void hugo() {
    SaveInjector::inject_default_during();
    tp_gameInfo.temp_flags.temp_flag_bit_field_19 = 128;  // midna trigger off
    tp_gameInfo.temp_flags.temp_flag_bit_field_17 = 0;    // hugo alive
}

void WiiAnySavesMenu::render(Font& font) {
    if (button_is_pressed(Controller::B)) {
        wii_any_saves_visible = false;
	    prac_visible = true;
        mm_visible = false;
        init_once = false;
        return;
    };

    if (!init_once) {
        Controller::reset_button(Controller::A);
        init_once = true;
    }

    if (button_is_down(Controller::A) && !button_is_held(Controller::A)) {
        switch (cursor.y) {
            case WII_SEWERS_INDEX: {
                loadFile("tpgzw/save_files/wii_any/sewers.bin");
                default_load();
                break;
            }
            case WII_HUGO_INDEX: {
                loadFile("tpgzw/save_files/wii_any/hugo.bin");
                default_load();
                camera = {465.674622f, 421.052704f, -11651.0684f, 735.525391f, 524.418701f, -11576.4746f, 1.36201766f, 280.0f};
                angle = 63622;
                position = {701.797302f, 85.5212784f, -5299.6123f};
                practice_file.inject_options_during_load = hugo;
                practice_file.inject_options_after_load = set_camera_angle_position;
                break;
            }
            case WII_FARON_INDEX: {
                loadFile("tpgzw/save_files/wii_any/faron.bin");
                default_load();
                break;
            }
            case WII_GROVE_INDEX: {
                loadFile("tpgzw/save_files/wii_any/grove.bin");
                default_load();
                break;
            }
            case WII_FT_INDEX: {
                loadFile("tpgzw/save_files/wii_any/forest_temple.bin");
                default_load();
                break;
            }
            case WII_LAN1_INDEX: {
                loadFile("tpgzw/save_files/wii_any/lanayru_1.bin");
                default_load();
                break;
            }
            case WII_ELDIN_INDEX: {
                loadFile("tpgzw/save_files/wii_any/eldin.bin");
                default_load();
                break;
            }
            case WII_MD_INDEX: {
                loadFile("tpgzw/save_files/wii_any/midna_dive.bin");
                default_load();
                break;
            }
            case WII_LB1_INDEX: {
                loadFile("tpgzw/save_files/wii_any/lakebed_1.bin");
                default_load();
                break;
            }
            case WII_LAN2_INDEX: {
                loadFile("tpgzw/save_files/wii_any/lanayru_2.bin");
                default_load();
                break;
            }
            case WII_LB2_INDEX: {
                loadFile("tpgzw/save_files/wii_any/lakebed_2.bin");
                default_load();
                break;
            }
            case WII_MORPHEEL_INDEX: {
                loadFile("tpgzw/save_files/wii_any/morpheel.bin");
                default_load();
                break;
            }
            case WII_MDH_INDEX: {
                loadFile("tpgzw/save_files/wii_any/mdh.bin");
                default_load();
                break;
            }
            case WII_POST_MDH_INDEX: {
                loadFile("tpgzw/save_files/wii_any/post_mdh.bin");
                default_load();
                break;
            }
            case WII_AG1_INDEX: {
                loadFile("tpgzw/save_files/wii_any/arbiters_1.bin");
                default_load();
                break;
            }
            case WII_AG2_INDEX: {
                loadFile("tpgzw/save_files/wii_any/arbiters_2.bin");
                default_load();
                break;
            }
            case WII_POST_AG_INDEX: {
                loadFile("tpgzw/save_files/wii_any/post_arbiters.bin");
                default_load();
                break;
            }
            case WII_SPR_INDEX: {
                loadFile("tpgzw/save_files/wii_any/snowpeak.bin");
                default_load();
                break;
            }
            case WII_CITS1_INDEX: {
                loadFile("tpgzw/save_files/wii_any/cits_1.bin");
                default_load();
                break;
            }
            case WII_CITS2_INDEX: {
                loadFile("tpgzw/save_files/wii_any/cits_2.bin");
                default_load();
                break;
            }
            case WII_POT1_INDEX: {
                loadFile("tpgzw/save_files/wii_any/pot_1.bin");
                default_load();
                break;
            }
            case WII_POT2_INDEX: {
                loadFile("tpgzw/save_files/wii_any/pot_2.bin");
                default_load();
                break;
            }
            case WII_HC1_INDEX: {
                loadFile("tpgzw/save_files/wii_any/hc_1.bin");
                default_load();
                break;
            }
            case WII_HC2_INDEX: {
                loadFile("tpgzw/save_files/wii_any/hc_2.bin");
                default_load();
                break;
            }
        }
    }

    Utilities::move_cursor(cursor, LINES);
    Utilities::render_lines(font, lines, cursor.y, LINES);
};