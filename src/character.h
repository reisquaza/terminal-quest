struct Attributes
{
	int strength;
	int wisdom;
	int dexterity;
    int health;
    int mana;
};

class Character
{
  public:
	Character(Attributes *attributes);
    int calculateHp(const Attributes *attributes);
    int calculateMp(const Attributes *attributes);
    void increaseAttributes(const Attributes *attributes);
	int attack();
	int hp = 0;
	int mp = 10;
	int str = 0;
	int wis = 0;
	int dex = 0;
};
