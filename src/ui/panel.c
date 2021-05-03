
void panel_render(s32 x, s32 y, s32 w, s32 h)
{	
	s32 cornor_size = img_panel_topleft->width;
	log_assert(w > cornor_size*2, "Panel width too small");
	log_assert(h > cornor_size*2, "Panel height too small");
	s32 top_width = w - (cornor_size*2);
	s32 size_height = h - (cornor_size*2);

	// top
	renderer->render_image(img_panel_topleft, x, y, img_panel_topleft->width, img_panel_topleft->height);
	renderer->render_image(img_panel_top, x + cornor_size, y, top_width, img_panel_top->height);
	renderer->render_image(img_panel_topright, x + cornor_size + top_width, y, img_panel_topright->width, img_panel_topright->height);

	// left
	renderer->render_image(img_panel_left, x, y + cornor_size-1, img_panel_left->width, size_height+2);

	// right
	renderer->render_image(img_panel_right, x + cornor_size + top_width, y + cornor_size-1, img_panel_right->width, size_height+2);

	// bottom
	renderer->render_image(img_panel_bottomleft, x, y + cornor_size + size_height, img_panel_topleft->width, img_panel_topleft->height);
	renderer->render_image(img_panel_bottom, x + cornor_size, y + cornor_size + size_height, top_width, img_panel_top->height);
	renderer->render_image(img_panel_bottomright, x + cornor_size + top_width, y + cornor_size + size_height, img_panel_topright->width, img_panel_topright->height);

	// fill
	s32 pad = 10;
	renderer->render_rectangle(x+pad, y+pad, w-(pad*2), h-(pad*2), rgb(66, 63, 58));
}