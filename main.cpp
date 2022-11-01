#include <iostream>
#include "Menu.h"
#include "SnakeGameBoard.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

using namespace std;
using namespace sf;


int main()
{
	Menu playerMenu;
	if (playerMenu.openGameWindow) {
		if (playerMenu.singlePlayer)
			SnakeGameBoard singlePlayerBoard;
		else
			SnakeGameBoard MultiplayerBoard;
	}
	return 0;
}