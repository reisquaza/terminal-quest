#ifndef CHARACTER_H
#define CHARACTER_H

#include "character.h"

enum PlayerClass
{
	None,
	Warrior,
	Mage,
	Rogue,
};

struct PlayerAttributes : Attributes
{
	PlayerClass playerClass;
};

class Player : public Character
{
  private:
	int level;
	int exp;

  public:
	Player(PlayerAttributes *attributes);
	PlayerClass playerClass;
	~Player();
};

#endif // !CHARACTER_H
