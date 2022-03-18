#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;
#define Max_members_of_Items 5



class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();


	int GetpressedItem() {
		return selecteditemindex;



	}
private:
	int selecteditemindex;
	int selecteditem;
	Font font;
	Text menu[Max_members_of_Items];



};

