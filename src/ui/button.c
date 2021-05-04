
void button_render(float scale, char* text, s32 x, s32 y, s32 w, s32 h)
{	
	s32 cornor_size = img_button_topleft->width*(scale/2);
	log_assert(w > cornor_size*2, "Panel width too small");
	log_assert(h > cornor_size*2, "Panel height too small");
	s32 top_width = w - (cornor_size*2);
	s32 size_height = h - (cornor_size*2);

	color tint = rgb(255,255,255);
	color fill = rgb(98, 95, 90);
	if (_global_mouse.x >= x && _global_mouse.x <= x + w && _global_mouse.y >= y && _global_mouse.y <= y + h) {
		tint = rgb(210,210,210);
		fill = rgb(81, 78, 74);
		platform_set_cursor(main_window, CURSOR_POINTER);
	}

	// top
	renderer->render_image_tint(img_button_topleft, x, y, cornor_size, cornor_size, tint);
	renderer->render_image_tint(img_button_top, x + cornor_size, y, top_width, cornor_size, tint);
	renderer->render_image_tint(img_button_topright, x + cornor_size + top_width, y, cornor_size, cornor_size, tint);

	// left
	renderer->render_image_tint(img_button_left, x, y + cornor_size-1, cornor_size, size_height+2, tint);

	// right
	renderer->render_image_tint(img_button_right, x + cornor_size + top_width, y + cornor_size-1, cornor_size, size_height+2, tint);

	// bottom
	renderer->render_image_tint(img_button_bottomleft, x, y + cornor_size + size_height, cornor_size, cornor_size, tint);
	renderer->render_image_tint(img_button_bottom, x + cornor_size, y + cornor_size + size_height, top_width, cornor_size, tint);
	renderer->render_image_tint(img_button_bottomright, x + cornor_size + top_width, y + cornor_size + size_height, cornor_size, cornor_size, tint);

	// fill
	s32 pad = cornor_size;
	renderer->render_rectangle(x+pad, y+pad, w-(pad*2), h-(pad*2), fill);

	// text
	font* font_sml = FONT_REGULAR(SIZE_RDF(scale, 24));
	s32 text_y = y + (h/2) - (font_sml->px_h/2);
	s32 game_title_width = renderer->calculate_text_width(font_sml, text);
	s32 text_x = x + (w/2) - (game_title_width/2);

	renderer->render_text(font_sml, text_x+1, text_y+1, text, rgb(24,24,24));
	renderer->render_text(font_sml, text_x, text_y, text, rgb(207,207,207));
}