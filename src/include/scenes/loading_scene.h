/* 
*  BSD 2-Clause “Simplified” License
*  Copyright (c) 2019, Aldrik Ramaekers, aldrik.ramaekers@protonmail.com
*  All rights reserved.
*/

#ifndef INCLUDE_LOADING_SCENE
#define INCLUDE_LOADING_SCENE

void loading_scene_init();
void loading_scene_render(platform_window* window);
void loading_scene_update(platform_window* window);
void loading_scene_destroy();

#endif