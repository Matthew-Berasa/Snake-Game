#include "Menu.h"
#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

using namespace sf;
using namespace std;


Menu::Menu() {
	RenderWindow menu(VideoMode(),"Snake!", Style::Fullscreen);
	menu.setFramerateLimit(60);
	buttonSinglePlayer.setSize(Vector2f(385.f, 200.f));
	buttonSinglePlayer.setFillColor(Color::Transparent);
	buttonMultiPlayer.setSize(Vector2f(750.f, 175.f));
	buttonMultiPlayer.setFillColor(Color::Transparent);
	Continue(menu);
}

void Menu::Continue(RenderWindow &target) {
	while (target.isOpen()) {
		Event event;
		while (target.pollEvent(event)) {
			if (event.type == Event::Closed)
				target.close();
			else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				target.close();
			else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				
				if (buttonSinglePlayer.getGlobalBounds().contains(Mouse::getPosition(target).x, Mouse::getPosition(target).y)){
					target.close();
					RenderWindow gameSinglePlayer(VideoMode(1700, 1700), "Snake Single Player");
					while (gameSinglePlayer.isOpen())
					{
						gameSinglePlayer.clear();
						gameSinglePlayer.display();
					}
				}
				else if (buttonMultiPlayer.getGlobalBounds().contains(Mouse::getPosition(target).x, Mouse::getPosition(target).y)) {
					target.close();
					RenderWindow gameMultiPlayer(VideoMode(1700, 1700), "Snake Multiplayer");
					while (gameMultiPlayer.isOpen())
					{
						gameMultiPlayer.clear();
						gameMultiPlayer.display();
					}
				}
			}
		}
		DrawMenu(target);
	}
}

void Menu::textMenu(RenderWindow &target, string title, int sizeFont, float positionFontx, float positionFonty) {
	Font menuFont;
	menuFont.loadFromFile("Fonts/FontsFree-Net-GamePlayDemoRegular.ttf");

	Text menuText;
	menuText.setFont(menuFont);
	menuText.setCharacterSize(sizeFont);
	menuText.setFillColor(Color::Red);
	menuText.setString(title);
	menuText.setPosition(positionFontx, positionFonty);
	target.draw(menuText);
}

void Menu::DrawMenu(RenderWindow &target) {
	target.clear(Color::Black);
	textMenu(target, "SNAKE", 250, target.getSize().x / 2.5f, 0);
	textMenu(target, "SINGLE", 125, target.getSize().x / 2.25f, target.getSize().y / 1.5f);
	buttonSinglePlayer.setPosition(target.getSize().x / 2.25f, target.getSize().y / 1.5f);
	target.draw(buttonSinglePlayer);
	textMenu(target, "MULTIPLAYER", 125, target.getSize().x / 2.55f, target.getSize().y / 1.25f);
	buttonMultiPlayer.setPosition(target.getSize().x / 2.55f, target.getSize().y / 1.25f);
	target.draw(buttonMultiPlayer);
	target.display();
}



