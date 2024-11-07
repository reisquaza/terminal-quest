#include "character.h"

Character::Character(Attributes *attributes)
{
	str += attributes->strength;
	wis += attributes->wisdom;
	dex += attributes->dexterity;

}

int Character::calculateMp(const Attributes *attributes)
{
	return attributes->mana + (attributes->wisdom * 2);
}
int Character::calculateHp(const Attributes *attributes)
{
	return attributes->health + (attributes->strength * 4);
}

void Character::increaseAttributes(const Attributes *attributes)
{
	str += attributes->strength;
	wis += attributes->wisdom;
	dex += attributes->dexterity;
	mp += calculateMp(attributes);
	hp += calculateHp(attributes);
}
