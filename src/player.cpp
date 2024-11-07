#include "player.h"

Player::Player(PlayerAttributes *attributes) : Character(attributes)
{
	playerClass = attributes->playerClass;
}

Player::~Player() {};
