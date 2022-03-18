#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class controls
#define Max_members_of_Items 3



	//class controls
{
public:



	controls(float width, float height);
	void draw(sf::RenderWindow& window);
private:
	sf::Font fn3;
	sf::Text t3[Max_members_of_Items];

};
