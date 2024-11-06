#include "level0.h"
#include <ncurses.h>

Level0::Level0()
{
}

void Level0::distributePoints(Player *player)
{
	int totalPoints = 10;       // Initialize total points
	int strength = player->str; // Initialize attributes
	int wisdom = player->wis;
	int dexterity = player->dex;
	int currentSelection = 0; // 0 = Strength, 1 = Wisdom, 2 = Dexterity

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

	while (true)
	{
		clear();

		mvprintw(0, 0, "You have %d points left to distribute", totalPoints);

		if (currentSelection == 0)
			attron(A_REVERSE);
		mvprintw(2, 0, "Strength: %d", strength);
		if (currentSelection == 0)
			attroff(A_REVERSE);
		if (currentSelection == 1)
			attron(A_REVERSE);
		mvprintw(3, 0, "Wisdom: %d", wisdom);
		if (currentSelection == 1)
			attroff(A_REVERSE);
		if (currentSelection == 2)
			attron(A_REVERSE);
		mvprintw(4, 0, "Dexterity: %d", dexterity);
		if (currentSelection == 2)
			attroff(A_REVERSE);
		int ch = getch();
		if (ch == KEY_UP)
		{
			currentSelection = (currentSelection - 1 + 3) % 3;
		}
		else if (ch == KEY_DOWN)
		{
			currentSelection = (currentSelection + 1) % 3;
		}
		else if (ch == KEY_RIGHT && totalPoints > 0)
		{
			switch (currentSelection)
			{
			case 0:
				strength++;
				break;
			case 1:
				wisdom++;
				break;
			case 2:
				dexterity++;
				break;
			}
			totalPoints--;
		}
		else if (ch == KEY_LEFT)
		{
			switch (currentSelection)
			{
			case 0:
				if (strength > 0)
				{
					strength--;
					totalPoints++;
				}
				break;
			case 1:
				if (wisdom > 0)
				{
					wisdom--;
					totalPoints++;
				}
				break;
			case 2:
				if (dexterity > 0)
				{
					dexterity--;
					totalPoints++;
				}
				break;
			}
		}
		else if (ch == 'q' || ch == 'Q')
		{
			break;
		}

		refresh();
	}

	endwin();
}
void Level0::selectClass()
{
}
void Level0::createPlayer()
{
    Attributes attributes = {1,1,1};
    Player player = Player(&attributes); 
	distributePoints(&player);
}
void Level0::render()
{
    createPlayer();
}
