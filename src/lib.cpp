#include <stdio.h>
#include <stdint.h>
#include "libtpw_c/include/system.h"
#include "libtpw_c/include/link.h"
#include "libtpw_c/include/tp.h"
#include "libtpw_c/include/controller.h"
#include "libtpw_c/include/addrs.h"
//#include "gcn_c/include/card.h"
#include "controller.h"
#include "fonts/consolas.h"
#include "font.h"
#include "fifo_queue.h"
#include "menu.h"
#include "fs.h"
#include "input_viewer.h"
#include "log.h"
#include "utils.h"
#include "save_injector.h"
#include "commands.h"
#include "cheats.h"
#include "timer.h"
#include "spawning.h"
#include "gz_flags.h"

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

    //Patch for the BitE Crash (MOVE TO A DIFFERENT FILE LATER)

    if (tp_gameInfo.current_stage!=NULL&&strncmp((char*)tp_gameInfo.current_stage,"F_SP102",0x8)==0){
        memset((void *)0x804BCB94,0,0x4);
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
    MenuRendering::render_active_menus(default_font);
}
}