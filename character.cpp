struct Attributes
{
	int strength;
	int wisdom;
	int dexterity;
};

class Character
{
  public:
	Character(Attributes attributes);
	void updateHealth(int hp);
	int showHealth();
	int showMana();
	int showStr();
	int showWis();
	int showDex();

  private:
	int health;
	int mana;
	int str;
	int wis;
	int dex;
	int calculateHealth(int str);
};

Character::Character(Attributes attributes)
{
	str = attributes.strength;
	mana = attributes.wisdom;
	dex = attributes.dexterity;
	health = calculateHealth(str);
}

int Character::calculateHealth(int strength)
{
	return strength * 2;
};

void Character::updateHealth(int hp)
{
	health += hp;
}
int Character::showHealth()
{
	return health;
}
int Character::showMana()
{
	return mana;
}
int Character::showStr()
{
	return str;
}
int Character::showWis()
{
	return wis;
}
int Character::showDex()
{
	return dex;
}
