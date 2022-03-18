#pragma once
#include"SFML/Graphics.hpp"



class contain
{
public:
	contain(float width, float height);
	~contain();
	void draw(sf::RenderWindow& window);



private:



	sf::Font fon1;
	sf::Text cont[4];
};
