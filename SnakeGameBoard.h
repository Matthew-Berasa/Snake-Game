#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

using namespace std;
using namespace sf;


class SnakeGameBoard
{
	Sprite Apple, gameBoard;
	Texture appleTexture, grassTexture;
	unsigned int gameBoardWidth, gameBoardHeight, appleX, appleY;
	public:
		SnakeGameBoard();
		void gameDisplay(RenderWindow &Game);
		void BoardSetUp(RenderWindow &Game);
		void AppleSetUp();
		void drawBoard(RenderWindow &Game);
		void getAppleSpawn();
};


