#include "../KeemoObject.hpp"
#include "../KeemoWindow.h"

extern "C" {
	#include "kiss_sdl.h"
}

void button_event(kiss_button* button, SDL_Event* e, int *draw, int *quit)
{
	if(kiss_button_event(button, e, draw))
		*quit = 1;
}

int main(int argc, char* argv[])
{
	SDL_Renderer *renderer;
	SDL_Event e;
	kiss_array objects;
	
	kiss_label label = {0};
	kiss_button button = {0};
	char message[KISS_MAX_LENGTH];
	int draw, quit;

	quit = 0;
	draw = 1;
	kiss_array_new(&objects);
	char title[] = "Hello kiss";
	renderer = kiss_init(title, &objects, 500, 400);
	if(!renderer)
		return 1;

	KeemoWindow w{nullptr, 0, 0, kiss_screen_width, kiss_screen_height};
	KeemoWindow w2{&w, w.width()/2, w.height()/2, w.width()/2, w.height()/2};

	strcpy(message, "Hello World1");

	SDL_Point labelCoord{
		w2.width() / 2 - strlen(message) * kiss_textfont.advance / 2,
		w2.height() / 2 - (kiss_textfont.fontheight + 2 * kiss_normal.h) / 2
	};

	SDL_Point labelCoordG = w2.mapToGlobal(labelCoord);

	kiss_label_new(
		&label, &w2.window, message,
		labelCoordG.x,
		labelCoordG.y
	);
	label.textcolor.r = 255;


	char butonText[] = "OK";
	SDL_Point buttonCoord{
		w2.width() /2 - kiss_normal.w / 2,
		labelCoord.y + kiss_textfont.fontheight + kiss_normal.h
	};
	buttonCoord = w2.mapToGlobal(buttonCoord);
	kiss_button_new(
		&button, &w2.window, butonText,
		buttonCoord.x,
		buttonCoord.y
	);

	w2.setBackgroundColor(kiss_blue);
	w.show();
	w2.show();

	while(!quit)
	{
		SDL_Delay(10);
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
				quit = 1;

			kiss_window_event(&w.window, &e, &draw);
			button_event(&button, &e, &draw, &quit);
		}
		if(!draw)
			continue;

		SDL_RenderClear(renderer);
		kiss_window_draw(&w.window, renderer);
		kiss_window_draw(&w2.window, renderer);
		kiss_label_draw(&label, renderer);
		kiss_button_draw(&button, renderer);
		SDL_RenderPresent(renderer);
		draw = 0;
	}

	kiss_clean(&objects);

	return 0;
}
