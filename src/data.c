void data_load()
{
	img_logo = assets_load_image_from_file("data/img/logo.png");
	img_world_map = assets_load_image_from_file("data/img/world_background.png");

	img_panel_bottom = assets_load_image_from_file("data/img/panel_bottom.png");
	img_panel_top = assets_load_image_from_file("data/img/panel_top.png");
	img_panel_left = assets_load_image_from_file("data/img/panel_left.png");
	img_panel_right = assets_load_image_from_file("data/img/panel_right.png");
	img_panel_bottomleft = assets_load_image_from_file("data/img/panel_bottomleft.png");
	img_panel_bottomright = assets_load_image_from_file("data/img/panel_bottomright.png");
	img_panel_topleft = assets_load_image_from_file("data/img/panel_topleft.png");
	img_panel_topright = assets_load_image_from_file("data/img/panel_topright.png");

	for (int i = 0; i < FONT_COUNT; i++) {
		u16 size = FONT_START + (FONT_SIZE_SPACING * i);
		font_regular[i] = assets_load_font_from_file("data/fonts/Exo-Regular.ttf", size);
	}
}