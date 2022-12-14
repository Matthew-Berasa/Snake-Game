#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

using namespace sf;
using namespace std;

class Menu{
	RectangleShape buttonSinglePlayer, buttonMultiPlayer;
	public:	
		bool singlePlayer, openGameWindow = true;
		Menu();
		void Continue(RenderWindow &target);
		void drawTextMenu(RenderWindow &target, string title, int sizeFont, float positionFontx, float positionFonty = 0);
		void DrawMenu(RenderWindow &target);
};



