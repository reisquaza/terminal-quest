#include "character.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "hello" << endl;

	Character character({1, 1, 1});
	std::cout << character.showHealth() << endl;

	return 0;
}
