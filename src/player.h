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

class Player : Character
{
  public:
	PlayerAttributes CharAttributes;
	void gainStr(int str);
	void gainWis(int wis);
	void gainDex(int dex);
	Player(PlayerAttributes &attributes);
	~Player();
};

class PlayerBuilder : public CharacterBuilder
{
  private:
	PlayerAttributes Attributes;

  public:
	virtual PlayerBuilder &setStr(int str);
	virtual PlayerBuilder &setWis(int wis);
	virtual PlayerBuilder &setDex(int dex);
	virtual PlayerBuilder &setClass(PlayerClass playerClass);
	virtual Player build();
	PlayerBuilder();
	~PlayerBuilder();
};

#endif // !CHARACTER_H
