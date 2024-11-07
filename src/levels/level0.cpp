#include "level0.h"
#include <ncurses.h>

Level0::Level0()
{
}

void Level0::distributePoints(Player *player)
{
	Attributes attributes = {0, 0, 0};
	int totalPoints = 10;
	int currentSelection = 0; // 0 = Strength, 1 = Wisdom, 2 = Dexterity

	while (true)
	{
		clear();

		mvprintw(0, 0, "You have %d points left to distribute", totalPoints);

		if (currentSelection == 0)
			attron(A_REVERSE);
		mvprintw(2, 0, "Strength (%d): %d", player->str, attributes.strength);
		if (currentSelection == 0)
			attroff(A_REVERSE);
		if (currentSelection == 1)
			attron(A_REVERSE);
		mvprintw(3, 0, "Wisdom (%d): %d", player->wis, attributes.wisdom);
		if (currentSelection == 1)
			attroff(A_REVERSE);
		if (currentSelection == 2)
			attron(A_REVERSE);
		mvprintw(4, 0, "Dexterity (%d): %d", player->dex, attributes.dexterity);
		if (currentSelection == 2)
			attroff(A_REVERSE);

		mvprintw(6, 0, "Use arrow keys <-- --> to decrease or increase points");
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
				attributes.strength++;
				break;
			case 1:
				attributes.wisdom++;
				break;
			case 2:
				attributes.dexterity++;
				break;
			}
			totalPoints--;
		}
		else if (ch == KEY_LEFT)
		{
			switch (currentSelection)
			{
			case 0:
				if (attributes.strength > 0)
				{
					attributes.strength--;
					totalPoints++;
				}
				break;
			case 1:
				if (attributes.wisdom > 0)
				{
					attributes.wisdom--;
					totalPoints++;
				}
				break;
			case 2:
				if (attributes.dexterity > 0)
				{
					attributes.dexterity--;
					totalPoints++;
				}
				break;
			}
		}
		else if (ch == '\n' | ch == 10)
		{
			player->increaseAttributes(&attributes);
			break;
		}
	}
}
PlayerAttributes Level0::selectClass()
{
	int currentSelection = 0; // 0 = Strength, 1 = Wisdom, 2 = Dexterity
	PlayerAttributes attributes;
	attributes.health = 20;
	attributes.mana = 10;

	while (true)
	{
		clear();

		mvprintw(0, 0, "Pick your class");

		if (currentSelection == 0)
			attron(A_REVERSE);
		mvprintw(2, 0, "Warrior");
		if (currentSelection == 0)
			attroff(A_REVERSE);
		if (currentSelection == 1)
			attron(A_REVERSE);
		mvprintw(3, 0, "Mage");
		if (currentSelection == 1)
			attroff(A_REVERSE);
		if (currentSelection == 2)
			attron(A_REVERSE);
		mvprintw(4, 0, "Rogue");
		if (currentSelection == 2)
			attroff(A_REVERSE);

		mvprintw(6, 0, "Press enter to confirm");
		int ch = getch();
		if (ch == KEY_UP)
		{
			currentSelection = (currentSelection - 1 + 3) % 3;
		}
		else if (ch == KEY_DOWN)
		{
			currentSelection = (currentSelection + 1) % 3;
		}
		else if (ch == '\n' | ch == 10)
		{
			switch (currentSelection)
			{
			case 0:
				attributes.playerClass = PlayerClass::Warrior;
				attributes.strength = 5;
				attributes.wisdom = 1;
				attributes.dexterity = 4;
				break;
			case 1:
				attributes.playerClass = PlayerClass::Mage;
				attributes.strength = 1;
				attributes.wisdom = 5;
				attributes.dexterity = 4;
				break;
			case 2:
				attributes.playerClass = PlayerClass::Rogue;
				attributes.strength = 3;
				attributes.wisdom = 3;
				attributes.dexterity = 4;
				break;
			}
			break;
		}
	}
	return attributes;
}
Player Level0::createPlayer()
{
	PlayerAttributes attributes = selectClass();
	Player player = Player(&attributes);
	distributePoints(&player);
	return player;
}
void Level0::render()
{
	Player player = createPlayer();
	clear();
	initscr();
	mvprintw(0, 0, "Final Attributes:");
	mvprintw(1, 0, "Strength: %d", player.str);
	mvprintw(2, 0, "Wisdom: %d", player.wis);
	mvprintw(3, 0, "Dexterity: %d", player.dex);
	mvprintw(4, 0, "Health: %d", player.hp);
	mvprintw(5, 0, "Mana: %d", player.mp);
	mvprintw(6, 0, "Class: %d", player.playerClass);
	mvprintw(8, 0, "Press any key to continue...");
	refresh();

	printw("Press any key to exit...");
	refresh();
	getch();

	endwin();
}
