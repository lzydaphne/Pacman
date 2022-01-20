// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_settings.h"
#include "scene_menu_object.h"
#include "scene_menu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */

// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.


/* Internal Variables*/
static ALLEGRO_BITMAP* gameTitle = NULL;
static ALLEGRO_SAMPLE_ID menuBGM;
static Button Back_btnSettings;
static Button effOn_btnSettings;//吃豆子的音效
static Button effOff_btnSettings;
static Button bgmOn_btnSettings;//背景音樂
static Button bgmOff_btnSettings;
static Button bgmvolUp_btnSettings;//音量
static Button bgmvolDw_btnSettings;
static Button effvolUp_btnSettings;
static Button effvolDw_btnSettings;



static void init() {

	Back_btnSettings = button_create(325, 575, 150, 120, "Assets/return.png", "Assets/return_hover.png");
	effOn_btnSettings = button_create(475, 450, 150, 100, "Assets/turn_on.png", "Assets/on1.png");
	effOff_btnSettings = button_create(175, 450, 150, 100, "Assets/turn_off.png", "Assets/off1.png");
	bgmOn_btnSettings = button_create(475, 300, 150, 100, "Assets/turn_on.png", "Assets/on1.png");
	bgmOff_btnSettings = button_create(175, 300, 150, 100, "Assets/turn_off.png", "Assets/off1.png");
	bgmvolUp_btnSettings = button_create(600, 100, 50, 50, "Assets/volume_up.png", "Assets/on_hover.png");
	bgmvolDw_btnSettings = button_create(150, 100, 50, 50, "Assets/volume_down.png", "Assets/down_hover.png");
	effvolUp_btnSettings = button_create(600, 200, 50, 50, "Assets/volume_up.png", "Assets/on_hover.png");
	effvolDw_btnSettings = button_create(150, 200, 50, 50, "Assets/volume_down.png", "Assets/down_hover.png");


	// gameTitle = load_bitmap("Assets/title.png");
	//gameTitleW = al_get_bitmap_width(gameTitle);
	//gameTitleH = al_get_bitmap_height(gameTitle);
	stop_bgm(menuBGM);
	menuBGM = play_bgm(themeMusic, music_volume);

}
static void draw(void) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	drawButton(Back_btnSettings);
	drawButton(effOn_btnSettings);
	drawButton(effOff_btnSettings);
	drawButton(bgmOn_btnSettings);
	drawButton(bgmOff_btnSettings);
	drawButton(bgmvolUp_btnSettings);
	drawButton(bgmvolDw_btnSettings);
	drawButton(effvolUp_btnSettings);
	drawButton(effvolDw_btnSettings);

	char voltemp[50];
	sprintf_s(voltemp, 50, "BGM vol = %3.2f", music_volume);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		100,
		ALLEGRO_ALIGN_CENTER,
		voltemp
	);
	char voltemp2[50];
	sprintf_s(voltemp2, 50, "EFFECT vol = %3.2f", effect_volume);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		200 ,
		ALLEGRO_ALIGN_CENTER,
		voltemp2
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		700,
		ALLEGRO_ALIGN_CENTER,
		"Rerurn"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		400,
		340,
		ALLEGRO_ALIGN_CENTER,
		"BGM"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		400,
		490,
		ALLEGRO_ALIGN_CENTER,
		"EFFECT"
	);

}
static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	[HACKATHON 3-7]
	//	TODO: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
	Back_btnSettings.hovered = buttonHover(Back_btnSettings, mouse_x, mouse_y);
	effOn_btnSettings.hovered = buttonHover(effOn_btnSettings, mouse_x, mouse_y);
	effOff_btnSettings.hovered = buttonHover(effOff_btnSettings, mouse_x, mouse_y);
	bgmOn_btnSettings.hovered = buttonHover(bgmOn_btnSettings, mouse_x, mouse_y);
	bgmOff_btnSettings.hovered = buttonHover(bgmOff_btnSettings, mouse_x, mouse_y);
	bgmvolUp_btnSettings.hovered = buttonHover(bgmvolUp_btnSettings, mouse_x, mouse_y);
	bgmvolDw_btnSettings.hovered = buttonHover(bgmvolDw_btnSettings, mouse_x, mouse_y);
	effvolUp_btnSettings.hovered = buttonHover(effvolUp_btnSettings, mouse_x, mouse_y);
	effvolDw_btnSettings.hovered = buttonHover(effvolDw_btnSettings, mouse_x, mouse_y);

}
static void on_mouse_down() {
	if (Back_btnSettings.hovered)
		game_change_scene(scene_menu_create());
	else if (effOff_btnSettings.hovered) {
		effect_volume = 0.0;
		// stop_bgm(menuBGM);
	}

	else if (effOn_btnSettings.hovered) {
		// menuBGM = play_bgm(themeMusic, music_volume);
		effect_volume = 0.5;
	}

	else if (bgmOn_btnSettings.hovered) {
		music_volume = 0.5;
		stop_bgm(menuBGM);
		menuBGM = play_bgm(themeMusic, music_volume);
	}

	else if (bgmOff_btnSettings.hovered) {
		stop_bgm(menuBGM);
		music_volume = 0.0;
	}
	else if (bgmvolUp_btnSettings.hovered) {

		music_volume += 0.3;
	}
	else if (bgmvolDw_btnSettings.hovered) {		// be_solved
		if (music_volume -0.3 <0) 
			music_volume =0;
		else
			music_volume -= 0.3;
	}
	else if (effvolUp_btnSettings.hovered) {

		effect_volume += 0.3;
	}
	else if (effvolDw_btnSettings.hovered) {		// be_solved
		if (effect_volume - 0.3 < 0) {
			effect_volume = 0;
		}
		else
		{
			effect_volume -=0.3;
		}
	}
}
static void destroy() {
	stop_bgm(menuBGM);
	//al_destroy_bitmap(gameTitle);
	al_destroy_bitmap(Back_btnSettings.default_img);
	al_destroy_bitmap(Back_btnSettings.hovered_img);
	al_destroy_bitmap(bgmOn_btnSettings.default_img);
	al_destroy_bitmap(bgmOn_btnSettings.hovered_img);
	al_destroy_bitmap(bgmOff_btnSettings.default_img);
	al_destroy_bitmap(bgmOff_btnSettings.hovered_img);
	al_destroy_bitmap(effOn_btnSettings.default_img);
	al_destroy_bitmap(effOn_btnSettings.hovered_img);
	al_destroy_bitmap(effOff_btnSettings.default_img);
	al_destroy_bitmap(effOff_btnSettings.hovered_img);
	al_destroy_bitmap(bgmvolUp_btnSettings.default_img);
	al_destroy_bitmap(bgmvolDw_btnSettings.hovered_img);
	al_destroy_bitmap(effvolUp_btnSettings.default_img);
	al_destroy_bitmap(effvolDw_btnSettings.hovered_img);
}



// The only function that is shared across files.
Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_down = &on_mouse_down;

	// TODO: Register more event callback functions such as keyboard, mouse, ...
	game_log("Settings scene created");
	return scene;
}