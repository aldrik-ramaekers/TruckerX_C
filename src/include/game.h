/* 
*  BSD 2-Clause “Simplified” License
*  Copyright (c) 2019, Aldrik Ramaekers, aldrik.ramaekers@protonmail.com
*  All rights reserved.
*/

#ifndef INCLUDE_GAME
#define INCLUDE_GAME

typedef enum t_game_state
{
	GAME_STATE_LOADING = 1,
	GAME_STATE_MENU = 2,
} game_state;

typedef struct t_game
{
	game_state current_state;
} game;

void game_set_active_scene(game_state state);
void game_update(platform_window* window);
void game_render(platform_window* window);

#endif