#include <string>
#include <iostream>

void draw_screen(int& height, int& width) {
    	for (int i{0}; i < width; ++i) {
		for (int j{0}; j < height; ++j) {
			std::cout << ". ";
		}
	
		std::cout << "\n";
	}
}

int main() {

	int screen_height{10};
	int screen_width{8};

    	while (true) {
        	draw_screen(screen_height, screen_width);
    	}
    
    	return 0;
}
