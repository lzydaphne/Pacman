// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_settings.h"
#include "scene_menu_object.h"
#include "scene_menu.h"
#include "scene_game.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

#include "scene_map.h" //added

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.
/* Define your static vars / function prototypes below. */

// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.

extern ALLEGRO_SAMPLE* click;
bool map1 = false;//added
bool map2 = false;
static ALLEGRO_SAMPLE_ID CLICK_ID;
/* Internal Variables*/
static Button map1_btnSettings;
static Button map2_btnSettings;//吃豆子的音效

static void init() {				//x y 圖片寬高
	map1_btnSettings = button_create(250, 200, 320, 120, "Assets/map1.png", "Assets/map1_2.png");
	map2_btnSettings = button_create(250, 400, 320, 120, "Assets/map2.png", "Assets/map2_2.png");
}

static void draw(void) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	drawButton(map1_btnSettings);
	drawButton(map2_btnSettings);
}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	[HACKATHON 3-7]
	//	TODO: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
	map1_btnSettings.hovered = buttonHover(map1_btnSettings, mouse_x, mouse_y);
	map2_btnSettings.hovered = buttonHover(map2_btnSettings, mouse_x, mouse_y);	
	if (map1_btnSettings.hovered || map2_btnSettings.hovered)
	{
		stop_bgm(CLICK_ID);
		CLICK_ID = play_audio(PACMAN_MOVESOUND, effect_volume);
	}
}

static void on_mouse_down() {
	if (map1_btnSettings.hovered) {
		map1=true;
		game_change_scene(scene_main_create());

	}

	else if (map2_btnSettings.hovered) {
		map2 = true;
		
		game_change_scene(scene_main_create());
	}

}
static void destroy() {
	al_destroy_bitmap(map1_btnSettings.default_img);
	al_destroy_bitmap(map1_btnSettings.hovered_img);
	al_destroy_bitmap(map2_btnSettings.default_img);
	al_destroy_bitmap(map2_btnSettings.hovered_img);
}



// The only function that is shared across files.
Scene scene_map_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_down = &on_mouse_down;

	// TODO: Register more event callback functions such as keyboard, mouse, ...
	game_log("map scene created");
	return scene;
}