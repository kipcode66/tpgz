#include "libtpw_c/include/controller.h"
#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/system.h"
#include "utils/link.hpp"
#include "utils/memory.hpp"
#include "fonts/consolas.h"
#include "font.h"
#include "fifo_queue.h"
#include "menu.h"
#include "gz_flags.h"
#include "input_viewer.h"
#include "timer.h"

_FIFOQueue Queue;
bool card_load = true;
Font default_font;

extern "C" {

void init() {
    default_font = Font(f_Consolas, consolas_bytes);
}

void game_loop() {
    using namespace Controller::Mote;
    
    // check and load gz settings card if found
    // Utilities::load_gz_card(card_load);

    if (tp_mPad.buttons == (Z | C | MINUS) && tp_fopScnRq.isLoading != 1) {
        mm_visible = true;
        fifo_visible = false;
    }
    if (tp_fopScnRq.isLoading == 1) {
        MenuRendering::close_active_menus();
    }

    GZFlags::apply_active_flags();

    // This is the funciton that game_loop replaces when patched, so we call it here
    tp_fapGm_Execute();
}

void draw() {
    default_font.setupRendering();
    //Consolas.setupRendering();
    if (fifo_visible) {
        FIFOQueue::renderItems(Queue, default_font);
    }
    if (ToolItems[Tools::LINK_DEBUG_INDEX].active) {
        Utilities::show_link_debug_info(default_font);
    }
    if (ToolItems[Tools::INPUT_VIEWER_INDEX].active) {
        InputViewer::render(default_font);
    }
    if (ToolItems[Tools::TIMER_INDEX].active) {
        Timer::render(default_font);
    }
    MenuRendering::render_active_menus(default_font);
    Utilities::render_active_watches(default_font);
}
}