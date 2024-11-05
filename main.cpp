#include "src/player.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	Attributes attributes;
    attributes.strength = 1;
    attributes.dexterity = 1;
    attributes.wisdom = 1;
    Player player(&attributes);
	std::cout << player.wis;
	return 0;
}
