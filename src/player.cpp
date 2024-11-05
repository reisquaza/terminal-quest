#include "player.h"

Player::Player(Attributes &attributes) : Character(attributes)
{
	playerClass = PlayerClass::None;
	str = attributes.strength;
	wis = attributes.wisdom;
	dex = attributes.dexterity;
}

Player::~Player() {};
