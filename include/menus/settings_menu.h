#include "menu.h"

#define CURSOR_RGBA cursor_rgba

enum SettingsIndex {
    AREA_RELOAD_BEHAVIOR_INDEX,
	CURSOR_COLOR_INDEX,
    DROP_SHADOWS_INDEX,
    SAVE_CARD_INDEX,
    LOAD_CARD_INDEX,
	POS_SETTINGS_MENU_INDEX
};
extern bool g_drop_shadows;
extern int g_area_reload_behavior;
extern int g_cursor_color;
extern bool g_cursor_color_flag;
extern int cursor_rgba;
#define LOAD_AREA 0
#define LOAD_FILE 1

enum cursor_colors {
	CURSOR_GREEN,
	CURSOR_BLUE,
	CURSOR_RED,
	CURSOR_ORANGE,
	CURSOR_YELLOW,
	CURSOR_PURPLE
};

class SettingsMenu : public Menu {
public:
    SettingsMenu() : Menu() {}
    static void render(Font& font);
};