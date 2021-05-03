
void menu_scene_init()
{

}

static void menu_draw_background(platform_window* window)
{
	vec4 area = camera_get_target_rectangle(window);
	s32 screen_center_x = area.x + (area.w/2);
	s32 screen_center_y = area.y + (area.h/2);
	renderer->render_image(img_world_map, area.x, area.y, area.w, area.h);
}

static void menu_draw_options(platform_window* window)
{
	vec4 area = camera_get_target_rectangle(window);
	s32 screen_center_x = area.x + (area.w/2);
	s32 screen_center_y = area.y + (area.h/2);

	float panel_scale = UI_SCALE(area.w);
	s32 panel_w = 198 * panel_scale;
	s32 panel_h = 173 * panel_scale;
	panel_render(screen_center_x - (panel_w/2), screen_center_y - (panel_h/2), panel_w, panel_h);
}

void menu_scene_render(platform_window* window)
{
	menu_draw_background(window);
	menu_draw_options(window);
}

void menu_scene_update(platform_window* window)
{
	
}

void menu_scene_destroy()
{

}