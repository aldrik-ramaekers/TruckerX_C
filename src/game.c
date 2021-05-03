
static game _game_instance;

static void game_init_current_scene()
{
	switch (_game_instance.current_state)
	{
		case GAME_STATE_LOADING:
			loading_scene_init();
			break;
		case GAME_STATE_MENU:
			menu_scene_init();
			break;
	}
}

static void game_destroy_current_scene()
{
	switch (_game_instance.current_state)
	{
		case GAME_STATE_LOADING:
			loading_scene_destroy();
			break;
		case GAME_STATE_MENU:
			menu_scene_destroy();
			break;
	}
}

void game_set_active_scene(game_state state)
{
	game_destroy_current_scene();
	_game_instance.current_state = state;
	game_init_current_scene();
}

void game_update(platform_window* window)
{
	switch (_game_instance.current_state)
	{
		case GAME_STATE_LOADING:
			loading_scene_update(window);
			break;
		case GAME_STATE_MENU:
			menu_scene_update(window);
			break;
	}
}

void game_render(platform_window* window)
{
	switch (_game_instance.current_state)
	{
		case GAME_STATE_LOADING:
			loading_scene_render(window);
			break;
		case GAME_STATE_MENU:
			menu_scene_render(window);
			break;
	}
}