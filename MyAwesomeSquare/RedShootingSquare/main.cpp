#include "..\SDL\include\SDL.h"
#include "..\SDL_Image\include\SDL_image.h"
#include <iostream>


using namespace std;

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")
#pragma comment(lib,"SDL2_Image.lib")

int main(int argc, char* argv[]) {
	bool running = true;
	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted&flags) != flags) {
	cout<<("IMG_Init: Failed to init required jpg and png support!\n")<<endl;
	cout<<("IMG_Init: %s\n", IMG_GetError()) << endl;
//	 handle error
	}
	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *backSurf = NULL;
	SDL_Surface *image=NULL;
	SDL_Texture *spaceship=NULL;
	SDL_Texture *background =NULL;
	


	

	SDL_Rect rectangle;

	rectangle.x = 75;
	rectangle.y = 75;
	rectangle.w = 75;
	rectangle.h = 75;

	backSurf = IMG_Load("background.png");
	image = IMG_Load("spaceship.png");

	background = SDL_CreateTextureFromSurface(renderer, backSurf);

	spaceship = SDL_CreateTextureFromSurface(renderer, image);

	

	SDL_FreeSurface(image);

	SDL_Rect bullet[5];
	bool shot = false;

	window = SDL_CreateWindow("Red Square",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (window = NULL) {
		//	cout << "Error on inicialising the window." << endl;
	}

	SDL_Event event;



	int bullnum = 0;
	int vel = 5;

	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;


	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_LEFT:
					left = false;
					break;
				case SDL_SCANCODE_RIGHT:
					right = false;
					break;
				case SDL_SCANCODE_UP:
					up = false;
					break;
				case SDL_SCANCODE_DOWN:
					down = false;
					break;

				}
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_LEFT:
					left = true;
					rectangle.x -= 5;
					break;
				case SDL_SCANCODE_RIGHT:
					right = true;
					rectangle.x += 5;
					break;
				case SDL_SCANCODE_UP:
					up = true;
					rectangle.y -= 5;
					break;
				case SDL_SCANCODE_DOWN:
					down = true;
					rectangle.y += 5;
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
				bullet[i].x += vel;
			}

		}
		if (left)rectangle.x -= 5;
		if (right)rectangle.x += 5;
		if (up)rectangle.y -= 5;
		if (down)rectangle.y += 5;

		//fons
		//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		SDL_RenderClear(renderer);

		//rect
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderCopy(renderer, spaceship, NULL, &rectangle);
	


		//bullet

		//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		for (int i = 0; i < 5; i++) {
			SDL_RenderFillRect(renderer, &bullet[i]);
		}
		SDL_RenderFillRect(renderer, &bullet[bullnum]);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
//	SDL_DestroyTexture(spaceship);

	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	return 0;
}