#include "Menu.h"
#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

using namespace sf;
using namespace std;


Menu::Menu() {
	RenderWindow menuWindow(VideoMode(),"Snake!", Style::Fullscreen);
	menuWindow.setFramerateLimit(60);
	buttonSinglePlayer.setSize(Vector2f(385.f, 200.f));
	buttonSinglePlayer.setFillColor(Color::Transparent);
	buttonMultiPlayer.setSize(Vector2f(750.f, 175.f));
	buttonMultiPlayer.setFillColor(Color::Transparent);
	Continue(menuWindow);
}

void Menu::Continue(RenderWindow &target) {
	while (target.isOpen()) {
		Event eventMenu;
		while (target.pollEvent(eventMenu)) {
			if (eventMenu.type == Event::Closed) {
				target.close();
				openGameWindow = false;
			}
			else if (eventMenu.type == Event::KeyPressed && eventMenu.key.code == Keyboard::Escape) {
				target.close();
				openGameWindow = false;
			}
			else if (eventMenu.type == Event::MouseButtonPressed && eventMenu.mouseButton.button == Mouse::Left) {
				
				if (buttonSinglePlayer.getGlobalBounds().contains(Mouse::getPosition(target).x, Mouse::getPosition(target).y)){
					target.close();
					singlePlayer = true;
				}
				else if (buttonMultiPlayer.getGlobalBounds().contains(Mouse::getPosition(target).x, Mouse::getPosition(target).y)) {
					target.close();
					singlePlayer = false;
				}
			}
		}
		DrawMenu(target);
	}
}

void Menu::drawTextMenu(RenderWindow &target, string title, int sizeFont, float positionFontx, float positionFonty) {
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
	drawTextMenu(target, "SNAKE", 250, target.getSize().x / 2.5f, 0);
	drawTextMenu(target, "SINGLE", 125, target.getSize().x / 2.25f, target.getSize().y / 1.5f);
	buttonSinglePlayer.setPosition(target.getSize().x / 2.25f, target.getSize().y / 1.5f);
	target.draw(buttonSinglePlayer);
	drawTextMenu(target, "MULTIPLAYER", 125, target.getSize().x / 2.55f, target.getSize().y / 1.25f);
	buttonMultiPlayer.setPosition(target.getSize().x / 2.55f, target.getSize().y / 1.25f);
	target.draw(buttonMultiPlayer);
	target.display();
}




