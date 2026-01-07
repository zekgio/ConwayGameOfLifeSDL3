#include <SDL3/SDL.h>
#include "screen.h"
#include <cstdlib>
#include <ctime>

const int GAME_WIDTH = 640;
const int GAME_HEIGHT = 480;

bool isAlive(std::vector<uint8_t>& display, int x, int y) {
	int alive = 0;
	// adjacent neighbors
	if (x > 0 && display[(y * GAME_WIDTH) + x - 1] == 1) 				alive++;
	if (x < (GAME_WIDTH - 1) && display[(y * GAME_WIDTH) + x + 1] == 1) alive++;
	if (y > 0 && display[ ((y-1) * GAME_WIDTH) + x] == 1) 				alive++;
	if (y < (GAME_HEIGHT - 1) && display[((y+1)*GAME_WIDTH) + x] == 1)	alive++;

	// diagonal neighbors
	if (x > 0 && y > 0 && display[((y-1) * GAME_WIDTH) + x - 1] == 1)								 alive++; // top-left
	if (x < (GAME_WIDTH - 1) && y > 0 && display[((y-1) * GAME_WIDTH) + x + 1] == 1)				 alive++; // top-right
	if (x > 0 && y < (GAME_HEIGHT - 1) && display[((y+1) * GAME_WIDTH) + x - 1] == 1)				 alive++; // bottom-left
	if (x < (GAME_WIDTH - 1) && y < (GAME_HEIGHT - 1) && display[((y+1) * GAME_WIDTH) + x + 1] == 1) alive++; // bottom-right

	//live and less than 2 neighbors -> die
	if (display[x + y * GAME_WIDTH] == 1 && alive < 2)	return false;
	// alive and 2 or 3 neighbors -> live
	if (display[x + y * GAME_WIDTH] == 1 && (alive == 2 || alive == 3))	return true;
	if (alive > 3) return false; // overpopulation -> die
	// dead and exactly 3 neighbors -> live
	if (display[x + y * GAME_WIDTH] == 0 && alive == 3) return true;

	return false;
}

int main(int argc, char* argv[]) {
	G screen;
	std::vector<uint8_t> display(GAME_WIDTH * GAME_HEIGHT, 0);
	std::vector<uint8_t> swap(GAME_WIDTH * GAME_HEIGHT, 0);
	srand(time(nullptr));

	for(auto& cell : display)
		if ( (rand() % 10) == 0 ) {
			cell = 1; // Alive
		} else {
		    cell = 0; // Dead
		}

	while (true) {
		for (int i = 0; i < GAME_WIDTH; i++) 
			for(int j=0; j<GAME_HEIGHT; j++) 
				swap[j * GAME_WIDTH + i] = isAlive(display, i, j) ? 1 : 0;

		for (int i = 0; i < GAME_WIDTH; i++) 
			for(int j=0; j<GAME_HEIGHT; j++) 
				if (swap[j * GAME_WIDTH + i] == 1)
					screen.drawpixel(i, j, 255, 255, 255, 255);

		std::copy(swap.begin(), swap.end(), display.begin());

		screen.update();
		SDL_Delay(5);
		screen.input();
		screen.clearpixels();
	}

	return 0;
}