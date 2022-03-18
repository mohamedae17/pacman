#include "contain.h"
#include <iostream>
using namespace sf;
using namespace std;



contain::contain(float width, float height)
{
	if (!fon1.loadFromFile("arial.ttf"))
	{
		cout << "SHIIIIIT";
	}
	cont[0].setFont(fon1);
	cont[0].setFillColor(Color::Yellow);
	cont[0].setString("CopyRights@2020");
	cont[0].setPosition(Vector2f(30, 250));
	cont[0].setString("Bacman is classic game.");



	cont[1].setFont(fon1);
	cont[1].setFillColor(Color::White);
	cont[1].setString("CopyRights@2020");
	cont[1].setCharacterSize(20);
	cont[1].setPosition(Vector2f(30, 350));
	cont[1].setString("The idea is simple one,guid pacman around the maze and eat ");



	cont[2].setFont(fon1);
	cont[2].setFillColor(Color::White);
	cont[2].setString("CopyRights@2020");
	cont[2].setCharacterSize(20);
	cont[2].setPosition(Vector2f(30, 400));
	cont[2].setString("all the little white dots whilst avoiding those nasty ghost");



	cont[3].setFont(fon1);
	cont[3].setFillColor(Color::White);
	cont[3].setString("CopyRights@2020");
	cont[3].setCharacterSize(20);
	cont[3].setPosition(Vector2f(30, 450));
	cont[3].setString("if you eat a power pill you will get extra live.");



}



contain::~contain()
{
}



void contain::draw(sf::RenderWindow& window)
{
	for (int j = 0; j < 4; j++) {
		window.draw(cont[j]);
	}
}
