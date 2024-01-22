#include <iostream>
#include "Gameplay.h"

int main()
{
	//time_delay_intro();
	Top:
    Game();
	if (result == 1)
	{
		std::cout << "Player 1 win." << std::endl;
	}
	else if (result == 2)
	{
		std::cout << "Player2 win." << std::endl;
	}
	else if(result == 3)
	{
		std::cout << "It's a tie." << std::endl;
		goto Top;
	}
	return 0;
}
