#include "character.h"

Character::Character(Attributes &attributes)
{
	str = attributes.strength;
	mana = attributes.wisdom;
	dex = attributes.dexterity;
	health = calculateHealth(str);
}

int Character::calculateHealth(int &strength)
{
	return strength * 2;
};

void Character::updateHealth(int &hp)
{
	health += hp;
}
int Character::getHealth()
{
	return health;
}
int Character::getMana()
{
	return mana;
}
int Character::getStr()
{
	return str;
}
int Character::getWis()
{
	return wis;
}
int Character::getDex()
{
	return dex;
}
int Character::attack()
{
	return 0;
}
