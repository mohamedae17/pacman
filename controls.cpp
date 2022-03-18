
#include "controls.h"
#include <iostream>
using namespace sf;
using namespace std;




controls::controls(float width, float height)
{
	if (!fn3.loadFromFile("pacman.ttf")) {
		cout << "SHIIIIIT";
	}



	t3[0].setFont(fn3);
	t3[0].setCharacterSize(50);
	t3[0].setFillColor(sf::Color::White);
	t3[0].setString("M:Mute");
	t3[0].setPosition(sf::Vector2f(0, 400));



	t3[1].setFont(fn3);
	t3[1].setCharacterSize(50);
	t3[1].setFillColor(sf::Color::Red);
	t3[1].setString("U:unmute");
	t3[1].setPosition(sf::Vector2f(0, 350));




	t3[2].setFont(fn3);
	t3[2].setCharacterSize(50);
	t3[2].setFillColor(sf::Color::Yellow);
	t3[2].setString("Backspace:Return to menu");
	t3[2].setPosition(sf::Vector2f(0, 300));




}
void controls::draw(sf::RenderWindow& window)
{
	for (int j = 0; j < 3; j++) {
		window.draw(t3[j]);
	}
}