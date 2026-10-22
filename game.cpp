#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include <vector>

//Game state variables
const int screen_width{80};
const int screen_height{30};
const int FPS{12};
const std::chrono::milliseconds frame_duration(1000 / FPS); //33 ms

void enableAnsiSupport() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void draw_screen(int width, int height) {
	std::string frame_buffer = "";
    
	frame_buffer += "\033[H";
	frame_buffer += "\n";

    	for (int y{0}; y < height; ++y) {
		for (int x{0}; x < width; ++x) {
			if (y == 0 or y == height-1 or x == 0 or x == width-1) {
				frame_buffer += '#';
			} else {
				frame_buffer += 'O';
			}
		}
	std::cout << "\n";
	}

	std::cout << frame_buffer << std::flush;
}

int main() {
	
	enableAnsiSupport();
	std::cout << "\x1b[8;30;80t";
	std::cout << "\033[?25l";

    while (true) {
		auto frame_start = std::chrono::steady_clock::now();
		
		//input logic will go here

		draw_screen(screen_width, screen_height);

		auto frame_end = std::chrono::steady_clock::now();

		auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(frame_end - frame_start);

		if (dt < frame_duration) {
			std::this_thread::sleep_for(frame_duration - dt);
		}
	}
	
	std::cout << "\033[?25h";
    return 0;
}
