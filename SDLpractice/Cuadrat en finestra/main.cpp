#include<iostream>
#include<SDL.h>
using namespace std;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Renderer *rectanglerend = NULL;
	SDL_Surface *s;

	SDL_Rect rectangle;

	rectangle.x = 75;
	rectangle.y = 75;
	rectangle.w = 75;
	rectangle.h = 75;

	window = SDL_CreateWindow("Cuadrat vermell",
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

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					rectangle.x = rectangle.x - 4;
					break;
				case SDLK_RIGHT:
					rectangle.x = rectangle.x + 4;
					break;
				case SDLK_UP:
					rectangle.y = rectangle.y - 4;
					break;
				case SDLK_DOWN:
					rectangle.y = rectangle.y + 4;
					break;
				}



			}


		}
		//SDL_FillRect(screen, NULL, 0);
		//SDL_FillRect(screen, &rectangle, blue);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
	SDL_Quit();
	return 0;
}

