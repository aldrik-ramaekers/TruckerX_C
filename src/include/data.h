/* 
*  BSD 2-Clause “Simplified” License
*  Copyright (c) 2019, Aldrik Ramaekers, aldrik.ramaekers@protonmail.com
*  All rights reserved.
*/

#ifndef INCLUDE_DATA
#define INCLUDE_DATA

#define FONT_SIZE_SPACING 4
#define FONT_COUNT 20
#define FONT_START 16

image* img_logo;
image* img_world_map;

image* img_panel_bottom;
image* img_panel_top;
image* img_panel_left;
image* img_panel_right;
image* img_panel_bottomleft;
image* img_panel_bottomright;
image* img_panel_topleft;
image* img_panel_topright;

font* font_regular[FONT_START + (FONT_COUNT * FONT_SIZE_SPACING)];

void data_load();

#define SIZE_RD(_w, _size) ((s32)((_size * (_w/1280.0f)) + 3) & ~0x03)
#define FONT_REGULAR(_size) font_regular[(_size-FONT_START)/FONT_SIZE_SPACING];

#endif