#include "character.h"

Character::Character(Attributes &attributes)
{
	this->CharAttributes = attributes;
}

Character::~Character()
{
}

int Character::attack()
{
	return 0;
}

int CharacterCalculation::calculateHp(int str)
{
	return str * 4;
}

int CharacterCalculation::calculateMp(int wis)
{
	return wis * 2;
}

CharacterBuilder::CharacterBuilder()
{
}

IncreaseHp CharacterCalculation::increaseHp(int str, int currentHp)
{
	return {calculateHp(str), currentHp - calculateHp(str)};
}

IncreaseMp CharacterCalculation::increaseMp(int wis, int currentMp)
{
	return {calculateMp(wis), currentMp - calculateMp(wis)};
}

CharacterBuilder::~CharacterBuilder()
{
}
