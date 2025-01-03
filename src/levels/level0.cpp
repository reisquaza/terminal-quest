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
		mvprintw(2, 0, "Strength (%d): %d", player->CharAttributes.strength,
		         attributes.strength);
		if (currentSelection == 0)
			attroff(A_REVERSE);
		if (currentSelection == 1)
			attron(A_REVERSE);
		mvprintw(3, 0, "Wisdom (%d): %d", player->CharAttributes.wisdom,
		         attributes.wisdom);
		if (currentSelection == 1)
			attroff(A_REVERSE);
		if (currentSelection == 2)
			attron(A_REVERSE);
		mvprintw(4, 0, "Dexterity (%d): %d", player->CharAttributes.dexterity,
		         attributes.dexterity);
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
			player->gainStr(attributes.strength);
			break;
		}
	}
}
Player Level0::selectClass()
{
	int currentSelection = 0; // 0 = Warrior, 1 = Mage, 2 = Rogue
	PlayerAttributes attributes;
	Player player = Player(attributes);

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
				player = PlayerBuilder()
				             .setDex(4)
				             .setWis(1)
				             .setStr(5)
				             .setClass(PlayerClass::Warrior)
				             .build();
				break;
			case 1:
				player = PlayerBuilder()
				             .setDex(4)
				             .setWis(5)
				             .setStr(1)
				             .setClass(PlayerClass::Mage)
				             .build();
				break;
			case 2:
				player = PlayerBuilder()
				             .setDex(4)
				             .setWis(3)
				             .setStr(3)
				             .setClass(PlayerClass::Rogue)
				             .build();
				break;
			}
			break;
		}
	}
	return player;
}
Player Level0::createPlayer()
{
	Player player = selectClass();
	distributePoints(&player);
	return player;
}

void Level0::render()
{
	Player player = createPlayer();
	clear();
	initscr();
	mvprintw(0, 0, "Final Attributes:");
	mvprintw(1, 0, "Strength: %d", player.CharAttributes.strength);
	mvprintw(2, 0, "Wisdom: %d", player.CharAttributes.wisdom);
	mvprintw(3, 0, "Dexterity: %d", player.CharAttributes.dexterity);
	mvprintw(4, 0, "Health: %d/%d", player.CharAttributes.currentHealth,
	         player.CharAttributes.maxHealth);
	mvprintw(5, 0, "Mana: %d/%d", player.CharAttributes.currentMana,
	         player.CharAttributes.maxMana);
	mvprintw(6, 0, "Class: %d", player.CharAttributes.playerClass);
	mvprintw(8, 0, "Press any key to continue...");
	refresh();

	printw("Press any key to exit...");
	refresh();
	getch();

	endwin();
}
