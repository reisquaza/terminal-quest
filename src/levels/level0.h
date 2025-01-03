#ifndef LEVEL0_H
#define LEVEL0_H

#include "../player.h"

class Level0
{
  public:
	Level0();
	void render();

  private:
	Player createPlayer();
	void distributePoints(Player *player);
	Player selectClass();
};

#endif // !LEVEL0_H
