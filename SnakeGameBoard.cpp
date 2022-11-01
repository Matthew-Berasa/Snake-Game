#include "SnakeGameBoard.h"
#include <iostream>
#include <string>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <stdlib.h> 
#include <time.h>  

using namespace sf;
using namespace std;


SnakeGameBoard::SnakeGameBoard(){
	RenderWindow gameWindow(VideoMode(), "Snake!", Style::Fullscreen);
	gameWindow.setFramerateLimit(60);	
	BoardSetUp(gameWindow);
	gameBoardWidth = gameBoard.getGlobalBounds().width;
	gameBoardHeight = gameBoard.getGlobalBounds().height;
	AppleSetUp();
	gameDisplay(gameWindow);
}

void SnakeGameBoard::gameDisplay(RenderWindow &Game) {
	while (Game.isOpen()){
		Event eventGame;
		while (Game.pollEvent(eventGame)) {
			if (eventGame.type == Event::Closed)
				Game.close();
			else if (eventGame.type == Event::KeyPressed && eventGame.key.code == Keyboard::Escape)
				Game.close();
		}
		drawBoard(Game);
	}
}

void SnakeGameBoard::BoardSetUp(RenderWindow &Game) {
	grassTexture.loadFromFile("Images/Grass.jpg");
	gameBoard.setTexture(grassTexture);
	gameBoard.setScale((Vector2f(4.7f,3.2f)));
	gameBoard.setPosition(Game.getSize().x/25.f,Game.getSize().y/25.f);
}

void SnakeGameBoard::AppleSetUp() {
	appleTexture.loadFromFile("Images/Snake Game Apple.png");
	Apple.setTexture(appleTexture);
	Apple.setScale(.20f, .20f);
	getAppleSpawn();
}

void SnakeGameBoard::drawBoard(RenderWindow &Game) {
	Game.clear(Color::Black);
	Game.draw(gameBoard); 
	Game.draw(Apple);
	Game.display();
}

void SnakeGameBoard::getAppleSpawn() {
	srand(time(NULL));
	appleX = rand() % gameBoardWidth;
	appleY = rand() % gameBoardHeight;
	while (!gameBoard.getGlobalBounds().contains(appleX, appleY)) {
		appleX = rand() % gameBoardWidth;
		appleY = rand() % gameBoardHeight;
	}
	Apple.setPosition(appleX, appleY);
}



