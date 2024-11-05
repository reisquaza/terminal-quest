#include "character.h"

Character::Character(Attributes *attributes)
{
	str = attributes->strength;
	mana = attributes->wisdom;
	dex = attributes->dexterity;
	health = attributes->strength * 2;
}
