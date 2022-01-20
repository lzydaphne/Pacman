#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

#include "scene_GameOver.h"
#include "utility.h"
#include "shared.h"
#include "scene_menu.h"

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */

// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.

// to create image amd BGM
static ALLEGRO_BITMAP* gameEnd = NULL;
static int gameEndW;
static int gameEndH;

static void init() {

	gameEnd = load_bitmap("Assets/game_over4.png");
	if (gameEnd == NULL) {
		game_abort("Error reading picture");
		return;
	}
	gameEndW = al_get_bitmap_width(gameEnd);
	gameEndH = al_get_bitmap_height(gameEnd);
	//menuBGM = play_bgm(themeMusic, music_volume);
	//stop_bgm(menuBGM);

}
static void destroy() {
	// stop_bgm(menuBGM);
	al_destroy_bitmap(gameEnd);
}



static void draw(void) {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameEndW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameEndH;
	al_draw_scaled_bitmap(
		gameEnd,
		0, 0,
		gameEndW, gameEndH,
		offset_w, offset_h,
		gameEndW * scale, gameEndH * scale,
		0
	);

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"ENTER\"  TO RESTART"
	);
}

static void on_key_down(int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_ENTER:
		game_change_scene(scene_menu_create());
		break;
	default:
		break;
	}
}

// The only function that is shared across files.
Scene scene_GameOver_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "GameOver";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_key_down = &on_key_down;
	// TODO: Register more event callback functions such as keyboard, mouse, ...
	game_log("GameOver scene created");
	return scene;
}