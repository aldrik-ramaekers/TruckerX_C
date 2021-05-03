/* 
*  BSD 2-Clause “Simplified” License
*  Copyright (c) 2019, Aldrik Ramaekers, aldrik.ramaekers@protonmail.com
*  All rights reserved.
*/

#ifndef INCLUDE_PANEL
#define INCLUDE_PANEL

// 1280 is our reference width.
#define UI_SCALE(_w) (_w/1280.0f)

void panel_render(s32 x, s32 y, s32 w, s32 h);

#endif