struct Attributes
{
	int strength;
	int wisdom;
	int dexterity;
};

class Character
{
  public:
	Character(Attributes &attributes);
	int attack();
	void updateHealth(int &hp);
	int getHealth();
	int getMana();
	int getStr();
	int getWis();
	int getDex();

  protected:
	int health;
	int mana;
	int str;
	int wis;
	int dex;
	int calculateHealth(int &str);
};
