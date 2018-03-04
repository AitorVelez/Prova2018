#include<iostream>
#include<SDL.h>
using namespace std;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Surface *s;

	SDL_Rect rectangle;

	rectangle.x = 75;
	rectangle.y = 75;
	rectangle.w = 75;
	rectangle.h = 75;

	SDL_Rect bullet[5];
	bool shot=false;

	window = SDL_CreateWindow("Red Square",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								500,
								500,
								0);

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (window = NULL) {
		cout << "Error on inicialising the window." << endl;
	}

	SDL_Event event;
	bool running = true;

	
	int bullnum = 0;
	
	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_LEFT:
					rectangle.x -= 4;
					break;
				case SDL_SCANCODE_RIGHT:
					rectangle.x+=4;
					break;
				case SDL_SCANCODE_UP:
					rectangle.y -= 4;
					break;
				case SDL_SCANCODE_DOWN:
					rectangle.y += 4;
					break;
				case SDL_SCANCODE_SPACE:
					
					shot = true;
					
					bullet[bullnum].x = rectangle.x + 75;
					bullet[bullnum].y = rectangle.y + (75 / 2);
					bullet[bullnum].w = 15;
					bullet[bullnum].h = 15;
					bullnum++;
					
					if (bullnum == 5) {
						bullnum = 0;
					}
					break;
					case SDL_SCANCODE_ESCAPE:
				running = false;
				break;
				}

			
			} 
		}

		if (shot == true) {
			for (int i = 0; i < 5; i++) {
				bullet[i].x += 1;
			}
			
		}

		//fons
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		//rect
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, &rectangle);
	

		//bullet
	
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		for (int i = 0; i < 5; i++) {
			SDL_RenderFillRect(renderer, &bullet[i]);
		}
		//SDL_RenderFillRect(renderer, &bullet[bullnum]);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		
		
	}
	SDL_Quit();
	return 0;
}

