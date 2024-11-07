#include "src/levels/level0.h"
#include <ncurses.h>

int main(int argc, char *argv[])
{
	initscr();            // Start ncurses mode
	noecho();             // Don't echo keypresses to the screen
	keypad(stdscr, TRUE); // Enable arrow keys
	curs_set(0);          // Hide cursor

	// Initialize color if the terminal supports it
	if (has_colors())
	{
		start_color();
		init_pair(1, COLOR_BLACK, COLOR_WHITE); // Highlighted color pair
	}

	Level0 level0 = Level0();
	level0.render();

	endwin();
	return 0;
}
