
void loading_scene_init()
{

}

void loading_scene_render(platform_window* window)
{
	vec4 area = camera_get_target_rectangle(window);
	renderer->render_rectangle(area.x, area.y, area.w, area.h, rgb(255,255,255));

	font* font_reg = FONT_REGULAR(SIZE_RD(area.w, 36));
	s32 target_size = area.h/5;
	s32 logo_text_pad = 20;
	s32 total_height = target_size + logo_text_pad + font_reg->px_h;

	s32 screen_center_x = area.x + (area.w/2);
	s32 screen_center_y = area.y + (area.h/2);
	s32 logo_x = screen_center_x - (target_size/2);
	s32 logo_y = screen_center_y - (total_height/2);
	renderer->render_image(img_logo, logo_x, logo_y, target_size, target_size);

	s32 text_y = logo_y + target_size + logo_text_pad;
	char* company_name = "Tar Software";
	s32 company_name_width = renderer->calculate_text_width(font_reg, company_name);
	s32 text_x = screen_center_x - (company_name_width/2);

	renderer->render_text(font_reg, text_x, text_y, company_name, rgb(8, 10, 12));
}

void loading_scene_update(platform_window* window)
{
	if (global_asset_collection.done_loading_assets) {
		game_set_active_scene(GAME_STATE_MENU);
	}
}

void loading_scene_destroy()
{

}