#define ASSET_FONT_COUNT 25

#include <projectbase/project_base.h>

#include "include/data.h"
#include "include/game.h"
#include "include/ui/panel.h"
#include "include/scenes/loading_scene.h"
#include "include/scenes/menu_scene.h"

#include "data.c"
#include "game.c"
#include "ui/panel.c"
#include "scenes/loading_scene.c"
#include "scenes/menu_scene.c"

#define CONFIG_DIRECTORY "trucker_x"

void update_render_game(platform_window* window)
{
	game_update(window);
	game_render(window);
}

int main(int argc, char** argv)
{
	platform_init(argc, argv, CONFIG_DIRECTORY);

    platform_window *window = platform_open_window("TruckerX",
                1280, 720 + platform_get_titlebar_height(), 1920, 1080, 960, 540 + platform_get_titlebar_height(), update_render_game, 0);

	data_load();
	game_set_active_scene(GAME_STATE_LOADING);

    while(platform_keep_running(window)) {
		window->do_draw = true;
        platform_handle_events();
    }

    settings_write_to_file();
    platform_destroy();

    return 0;
}