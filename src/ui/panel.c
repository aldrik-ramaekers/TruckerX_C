
void panel_render(float scale, s32 x, s32 y, s32 w, s32 h)
{	
	s32 cornor_size = img_panel_topleft->width*(scale/2);
	log_assert(w > cornor_size*2, "Panel width too small");
	log_assert(h > cornor_size*2, "Panel height too small");
	s32 top_width = w - (cornor_size*2);
	s32 size_height = h - (cornor_size*2);

	// top
	renderer->render_image(img_panel_topleft, x, y, cornor_size, cornor_size);
	renderer->render_image(img_panel_top, x + cornor_size, y, top_width, cornor_size);
	renderer->render_image(img_panel_topright, x + cornor_size + top_width, y, cornor_size, cornor_size);

	// left
	renderer->render_image(img_panel_left, x, y + cornor_size-1, cornor_size, size_height+2);

	// right
	renderer->render_image(img_panel_right, x + cornor_size + top_width, y + cornor_size-1, cornor_size, size_height+2);

	// bottom
	renderer->render_image(img_panel_bottomleft, x, y + cornor_size + size_height, cornor_size, cornor_size);
	renderer->render_image(img_panel_bottom, x + cornor_size, y + cornor_size + size_height, top_width, cornor_size);
	renderer->render_image(img_panel_bottomright, x + cornor_size + top_width, y + cornor_size + size_height, cornor_size, cornor_size);

	// fill
	s32 pad = cornor_size;
	renderer->render_rectangle(x+pad, y+pad, w-(pad*2), h-(pad*2), rgb(66, 63, 58));
}