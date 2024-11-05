struct Attributes
{
	int strength;
	int wisdom;
	int dexterity;
};

class Character
{
  public:
	Character(Attributes *attributes);
	int attack();
	int health;
	int mana;
	int str;
	int wis;
	int dex;
};
