#include "Aboutus.h"
#include <iostream>
using namespace sf;
using namespace std;
//#include "Menu.h"




Aboutus::Aboutus(float width, float height)
{
	if (!fn1.loadFromFile("pacman.ttf")) {
		cout << "SHIIIT";
	}



	txt[0].setFont(fn1);
	txt[0].setCharacterSize(50);
	txt[0].setFillColor(sf::Color::Red);
	txt[0].setString("CopyRights@2020");
	txt[0].setString("Mohamed Kandil");
	txt[0].setPosition(sf::Vector2f(0, 250));



	txt[1].setFont(fn1);
	txt[1].setCharacterSize(50);
	txt[1].setFillColor(sf::Color::Yellow);
	txt[1].setString("CopyRights@2020");
	txt[1].setString("Mohamed Ahmed");
	txt[1].setPosition(sf::Vector2f(0, 300));




	txt[2].setFont(fn1);
	txt[2].setString("CopyRights@2020");
	txt[2].setString("Esraa Mohamed");
	txt[2].setCharacterSize(50);
	txt[2].setFillColor(sf::Color::Blue);
	txt[2].setPosition(sf::Vector2f(0, 350));




	txt[3].setFont(fn1);
	txt[3].setString("CopyRights@2020");
	txt[3].setString("Rawan Magdy");
	txt[3].setFillColor(sf::Color::Red);
	txt[3].setCharacterSize(50);
	txt[3].setPosition(sf::Vector2f(0, 400));




	txt[4].setFont(fn1);
	txt[4].setString("CopyRights@2020");
	txt[4].setString("Aya Ebrahim");
	txt[4].setFillColor(sf::Color::Yellow);
	txt[4].setCharacterSize(50);
	txt[4].setPosition(sf::Vector2f(0, 450));



	txt[5].setFont(fn1);
	txt[5].setString("CopyRights@2020");
	txt[5].setString("Sara Atef");
	txt[5].setFillColor(sf::Color::Blue);
	txt[5].setCharacterSize(50);
	txt[5].setPosition(sf::Vector2f(0, 500));
}






Aboutus::~Aboutus()
{
}






void Aboutus::draw(sf::RenderWindow& window)
{
	for (int j = 0; j < 6; j++) {
		window.draw(txt[j]);
	}
}