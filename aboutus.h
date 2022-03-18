#pragma once
#include"SFML/Graphics.hpp"
class Aboutus
{
public:
	Aboutus(float width, float height);
	~Aboutus();
	void draw(sf::RenderWindow& window);



private:



	sf::Font fn1;
	sf::Text txt[6];
};

