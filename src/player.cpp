#include "player.h"

void Player::gainStr(int str)
{
	this->CharAttributes.strength += str;
	IncreaseHp IncreaseHp = CharacterCalculation::increaseHp(
	    this->CharAttributes.strength, this->CharAttributes.currentHealth);
	this->CharAttributes.currentHealth += IncreaseHp.currentHp;
}

void Player::gainStr(int str)
{
}

void Player::gainStr(int str)
{
}

Player::Player(PlayerAttributes &attributes) : Character(attributes)
{
	this->CharAttributes = attributes;
}

Player::~Player() {};

PlayerBuilder::PlayerBuilder()
{
	Attributes.maxHealth = 20;
	Attributes.currentHealth = 20;
	Attributes.maxMana = 10;
	Attributes.currentMana = 10;
}

Player PlayerBuilder::build()
{
	return Player(this->Attributes);
}

PlayerBuilder &PlayerBuilder::setStr(int str)
{
	this->Attributes.strength = str;
	int health = CharacterCalculation::calculateHp(str);
	this->Attributes.maxHealth += health;
	this->Attributes.currentHealth += health;
	return *this;
}

PlayerBuilder &PlayerBuilder::setWis(int wis)
{
	this->Attributes.wisdom = wis;
	int mana = CharacterCalculation::calculateMp(wis);
	this->Attributes.maxMana += mana;
	this->Attributes.currentMana += mana;
	return *this;
}

PlayerBuilder &PlayerBuilder::setDex(int dex)
{
	this->Attributes.dexterity = dex;
	return *this;
}

PlayerBuilder &PlayerBuilder::setClass(PlayerClass playerClass)
{
	this->Attributes.playerClass = playerClass;
	return *this;
}

PlayerBuilder::~PlayerBuilder() {};
