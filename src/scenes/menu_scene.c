
void menu_scene_init()
{

}

static void menu_draw_background(platform_window* window)
{
	vec4 area = camera_get_target_rectangle(window);
	s32 screen_center_x = area.x + (area.w/2);
	s32 screen_center_y = area.y + (area.h/2);
	renderer->render_rectangle(area.x, area.y, area.w, area.h, rgb(82,148,255));
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

static void menu_draw_title(platform_window* window)
{
	vec4 area = camera_get_target_rectangle(window);

	float panel_scale = UI_SCALE(area.w);
	s32 panel_w = 198 * panel_scale;
	s32 panel_h = 70 * panel_scale;
	s32 panel_pad = 50*panel_scale;
	s32 panel_x = area.x + panel_pad;
	s32 panel_y = area.y + area.h - panel_h - panel_pad;
	panel_render(panel_x, panel_y, panel_w, panel_h);
	
	font* font_reg = FONT_REGULAR(SIZE_RD(area.w, 44));
	font* font_sml = FONT_REGULAR(SIZE_RD(area.w, 20));
	s32 text_pad = 5*panel_scale;
	s32 total_text_h = font_reg->px_h + text_pad + font_sml->px_h;
	s32 text_y = panel_y + (panel_h/2) - (total_text_h/2);
	char* game_title = "TruckerX";
	char* game_version = "rev "GAME_VERSION;
	s32 game_title_width = renderer->calculate_text_width(font_reg, game_title);
	s32 text_x = panel_x + (panel_w/2) - (game_title_width/2);

	renderer->render_text(font_reg, text_x+2, text_y+2, game_title, rgb(24,24,24));
	renderer->render_text(font_reg, text_x, text_y, game_title, rgb(207,207,207));

	renderer->render_text(font_sml, 10*panel_scale + text_x+2,font_reg->px_h + text_pad + text_y+2, game_version, rgb(24,24,24));
	renderer->render_text(font_sml, 10*panel_scale + text_x,  font_reg->px_h + text_pad + text_y, game_version, rgb(207,207,207));
}

void menu_scene_render(platform_window* window)
{
	menu_draw_background(window);
	menu_draw_options(window);
	menu_draw_title(window);
}

void menu_scene_update(platform_window* window)
{
	
}

void menu_scene_destroy()
{

}