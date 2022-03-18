#include "Menu.h"
using namespace sf;



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("pacman.ttf"))
		cout << "erorr" << endl;
	menu[0].setFont(font);
	menu[0].setCharacterSize(60);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Start Game");
	menu[0].setPosition(Vector2f(width / 17, height / (Max_members_of_Items + 2) * 2));



	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(60);
	menu[1].setString("Controls ");
	menu[1].setPosition(Vector2f(width / 17, height / (Max_members_of_Items + 2) * 3));



	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setCharacterSize(60);
	menu[2].setString("Contain ");
	menu[2].setPosition(Vector2f(width / 17, height / (Max_members_of_Items + 2) * 4));



	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setCharacterSize(60);
	menu[3].setString("About");
	menu[3].setPosition(Vector2f(width / 17, height / (Max_members_of_Items + 2) * 5));



	menu[4].setFont(font);
	menu[4].setFillColor(Color::White);
	menu[4].setCharacterSize(60);
	menu[4].setString("Quit ");
	menu[4].setPosition(Vector2f(width / 17, height / (Max_members_of_Items + 2) * 6));
	selecteditemindex = 0;
	
}




Menu::~Menu()
{
}
void Menu::draw(RenderWindow &window) {
	for (int i = 0; i < Max_members_of_Items; i++) {
		window.draw(menu[i]);
	}
}



//motion arrows



void Menu::MoveUp() {
	if (selecteditemindex - 1 >= 0) {
		menu[selecteditemindex].setFillColor(Color::White);
		selecteditemindex--;
		menu[selecteditemindex].setFillColor(Color::Red);
	}
}
void Menu::MoveDown() {
	if (selecteditemindex + 1 < Max_members_of_Items) {



		menu[selecteditemindex].setFillColor(Color::White);
		selecteditemindex++;
		menu[selecteditemindex].setFillColor(Color::Red);
	}
}


