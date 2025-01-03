struct Attributes
{
	int strength;
	int wisdom;
	int dexterity;
	int maxHealth;
	int currentHealth;
	int maxMana;
	int currentMana;
};

struct IncreaseHp
{
	int maxHp;
	int currentHp;
};

struct IncreaseMp
{
	int maxMp;
	int currentMp;
};

class CharacterCalculation
{
  public:
	static int calculateHp(int str);
	static int calculateMp(int wis);
	static IncreaseHp increaseHp(int str, int currentHp);
	static IncreaseMp increaseMp(int wis, int currentMp);
};

class Character
{
  protected:
	Attributes CharAttributes = {0, 0, 0, 0, 0, 0, 0};

  public:
	Character(Attributes &attributes);
	int attack();
};

class CharacterBuilder
{
  private:
	Attributes Attributes;

  public:
	CharacterBuilder();

	~CharacterBuilder();
};