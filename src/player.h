#ifndef CHARACTER_H
#define CHARACTER_H

#include "character.h"

enum PlayerClass
{
	Warrior,
	Mage,
	Rogue,
	None
};

class Player : public Character
{
  private:
	PlayerClass playerClass;

  public:
	Player(Attributes &Attributes);
	~Player();
};

#endif // !CHARACTER_H
