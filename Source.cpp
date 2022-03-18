#include <SFML/Graphics.hpp>
#include<iostream>
#include<iostream>
#include"SFML/graphics.hpp"
#include"SFML/audio.hpp"
#include"Menu.h"
#include "Aboutus.h"
#include "controls.h"
#include "contain.h"
#include <windows.h>
#include <sstream>
using namespace std;
using namespace sf;
int active;


Clock mohamed;
Time ahmed;
stringstream ss;
int s = 0;
int g = 0;
int m = 0;

float PinkyDir = 0;
float BlinkyDir = 0;
float InkyDir = 0;
float ClydeDir = 0;
int Lives = 3;
int ScoreCounter = 0;
int c = 0;
stringstream score;


char maze[23][31] =
{
 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
 '#','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
 '#',' ','#','#','#','#','#','#','#','#','#',' ','0','0',' ','#',' ','0','0',' ','#','#','#','#','#','#','#','#','#',' ','#',
 '#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
 '#',' ',' ',' ','#','#','#',' ','#',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ','#',' ','#','#','#',' ',' ',' ','#',
 '#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#',
 '#',' ',' ',' ','#',' ','#','#','#','#','#','#','#',' ',' ','#',' ',' ','#','#','#','#','#','#','#',' ','#',' ',' ','!','#',
 '#',' ','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#','#','#',' ','#',
 '#',' ',' ',' ',' ',' ',' ',' ','#',' ','0',' ',' ',' ',' ',' ',' ',' ',' ',' ','0',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
 '#',' ',' ',' ',' ',' ','#',' ','#',' ','0',' ','#','#','0','0','0','#','#',' ','0',' ','#',' ','#',' ',' ',' ',' ',' ','#',
 '#','#','#','#',' ',' ','#',' ',' ',' ','0',' ','0','0','0','0','0','0','0',' ','0',' ',' ',' ','#',' ',' ','#','#','#','#',
 '0','0','0','0',' ',' ','0',' ',' ',' ','0',' ','0','0','0','0','0','0','0',' ','0',' ',' ',' ','0',' ',' ','0','0','0','0',
 '#','#','#','#',' ',' ','#',' ','#',' ','0',' ','0','0','0','0','0','0','0',' ','0',' ','#',' ','#',' ',' ','#','#','#','#',
 '#',' ',' ',' ',' ',' ','#',' ','#',' ','0',' ','#','#','0','0','0','#','#',' ','0',' ','#',' ','#',' ',' ',' ',' ',' ','#',
 '#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
 '#',' ','#','#','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#',
 '#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',
 '#','#','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#','#',
 '#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
 '#',' ',' ',' ',' ',' ',' ','!','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
 '#',' ','#','#','#','#','#','#','#','#','#','#','#',' ',' ','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',
 '#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
 '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
};


int main()
{
	while (true) {
		RenderWindow window(VideoMode(800, 800), "Pac-man ", Style::Close | Style::Resize);

		Font fontt;
		fontt.loadFromFile("PAC-FONT.ttf");
		Text  scoretext;
		scoretext.setFont(fontt);
		scoretext.setString("Score : ");
		scoretext.setCharacterSize(25);
		scoretext.setPosition(40, 40);
		scoretext.setFillColor(Color::Yellow);

		Font fonttt;
		fonttt.loadFromFile("novem___.ttf");
		Text scorenum("", fonttt);
		scorenum.setPosition(200, 40);
		scorenum.setCharacterSize(30);
		scorenum.setFillColor(Color::Yellow);



		Text  timers;
		timers.setFont(fontt);
		timers.setString("timer :");
		timers.setCharacterSize(25);
		timers.setPosition(510, 40);
		timers.setFillColor(Color::Yellow);



		Text timer("", fonttt);
		timer.setPosition(650, 40);
		timer.setCharacterSize(30);
		timer.setFillColor(Color::Yellow);




		Texture heart;
		heart.loadFromFile("heart.PNG");
		Sprite heartt(heart);
		heartt.setScale(Vector2f(0.17, 0.17));

		Texture cherryy;
		cherryy.loadFromFile("cherry.PNG");
		Sprite cherry(cherryy);
		cherry.setScale(Vector2f(0.09, 0.09));

		Font fontt3;
		fontt3.loadFromFile("PAC-FONT.TTF");
		Text  over;
		over.setFont(fontt3);
		over.setString("game over");
		over.setCharacterSize(90);
		over.setPosition(20, 300);
		over.setFillColor(Color::Yellow);

		Font fontt4;
		fontt4.loadFromFile("PAC-FONT.TTF");
		Text  win1;
		win1.setFont(fontt4);
		win1.setString("you win");
		win1.setCharacterSize(60);
		win1.setPosition(200, 300);
		win1.setFillColor(Color::Yellow);

		Font fontt5;
		fontt5.loadFromFile("PAC-FONT.TTF");
		Text  win2;
		win2.setFont(fontt5);
		win2.setString("your score is :");
		win2.setCharacterSize(60);
		win2.setPosition(20, 400);
		win2.setFillColor(Color::Yellow);



		//right face
		Texture pacy;
		pacy.loadFromFile("pac1.png");
		Sprite pac(pacy);
		pac.setPosition(Vector2f(0, 0));
		pac.setScale(Vector2f(.2, .2));
		//pac.setTextureRect(IntRect(3, 3, 90, 90));
		pac.setPosition(30, 114);

		// close face
		Texture pacy2;
		pacy2.loadFromFile("pac2.png");
		Sprite pac2(pacy2);
		pac2.setPosition(Vector2f(0, 0));
		pac2.setScale(Vector2f(.2, .2));
		//pac2.setTextureRect(IntRect(112, 3, 90, 90));
		pac2.setPosition(30, 114);

		// left face
		Texture pacy3;
		pacy3.loadFromFile("pac3.png");
		Sprite pac3(pacy3);
		pac3.setScale(Vector2f(.2, .2));
		//	pac3.setTextureRect(IntRect(770, 3, 180, 180));
		pac3.setPosition(30, 114);

		//down face
		Texture pacy4;
		pacy4.loadFromFile("pac4.png");
		Sprite pac4(pacy4);
		pac4.setScale(Vector2f(.2, 0.2));
		//pac4.setTextureRect(IntRect(5, 3, 150, 145));
		pac4.setPosition(30, 114);

		// up face
		Texture pacy5;
		pacy5.loadFromFile("pac5.png");
		Sprite pac5(pacy5);
		pac5.setScale(Vector2f(.2, .2));
		//pac5.setTextureRect(IntRect(5, 3, 150, 145));
		pac5.setPosition(30, 114);





		/*red*/
		Texture texture2;
		if (!texture2.loadFromFile("aaa.JPG")) {
			cout << "Error to downdload the pic2" << endl;
		}
		Sprite pinky(texture2);
		pinky.setPosition(Vector2f(342, 396));
		pinky.setScale(Vector2f(0.15, 0.15));
		pinky.setTextureRect(IntRect(94, 94, 150, 150));


		/*foshya*/
		Texture texture3;
		if (!texture3.loadFromFile("aaa.jpg")) {
			cout << "Error to downdload the pic2" << endl;
		}
		Sprite blinky(texture3);
		blinky.setPosition(Vector2f(390, 396));
		blinky.setScale(Vector2f(0.15, 0.15));
		blinky.setTextureRect(IntRect(94, 251, 150, 150));


		/*blue*/
		Texture texture4;
		if (!texture4.loadFromFile("aaa.jpg")) {
			cout << "Error to downdload the pic2" << endl;
		}
		Sprite clyde(texture4);
		clyde.setPosition(Vector2f(410, 348));
		clyde.setScale(Vector2f(0.15, 0.15));
		clyde.setTextureRect(IntRect(94, 400, 150, 150));

		/*yollow*/
		Texture texture5;
		if (!texture5.loadFromFile("aaa.jpg")) {
			cout << "Error to downdload the pic2" << endl;
		}
		Sprite inky(texture5);
		inky.setPosition(Vector2f(432, 396));
		inky.setScale(Vector2f(0.15, 0.15));
		inky.setTextureRect(IntRect(94, 550, 150, 150));




		Texture texture6;
		Texture t2;

		if (!texture6.loadFromFile("bluetile.JPG"))
		{
			cout << "error loading tile texture";
		}
		if (!t2.loadFromFile("dots.PNG"))
		{
			cout << "error loading dots texture";
		}
		Sprite bluetile(texture6);
		Sprite dots(t2);
		bluetile.setTextureRect(IntRect(70, 70, 120, 120));
		dots.setTextureRect(IntRect(0, 0, 4, 4));
		bluetile.setScale(Vector2f(0.22, 0.22));

		Menu menu(window.getSize().x, window.getSize().y);
		contain cont(window.getSize().x, (window.getSize().y));
		Aboutus txt(window.getSize().x, (window.getSize().y));
		controls t3(window.getSize().x, (window.getSize().y));

		Texture pic1;  //pacman interface
		if (!pic1.loadFromFile("b2.jpg"))
			cout << "error" << endl;

		Sprite sprite1(pic1);
		sprite1.setPosition(sf::Vector2f(100, 300));//???? ????.???? ???? 
		sprite1.setScale(sf::Vector2f(1, 1)); //???? ???? ,???? ???? ???? 

		Texture back;  //background
		if (!back.loadFromFile("b.jpg"))
			cout << "error" << endl;

		Sprite background(back);
		background.setScale(0.5, 0.7);
		background.setPosition(300, 400);

		Texture back2;  //background
		if (!back2.loadFromFile("bb.png"))
			cout << "error" << endl;

		Sprite background2(back2);
		background2.setScale(1, 1);
		background2.setPosition(100, 0);



		int i = 0;
		SoundBuffer buffer;    //          audio
		if (!buffer.loadFromFile("intro.wav"))
			cout << "error" << endl;
		Sound sound;
		sound.setBuffer(buffer);
		sound.setLoop(i == 0);//??? ???? ????
		sound.setVolume(20);
		sound.play();


		SoundBuffer Musica;
		Musica.loadFromFile("Music.wav");
		Sound music;
		music.setBuffer(Musica);
		music.setVolume(40);
		music.setLoop(i == 0);

		SoundBuffer pacman_chomp;
		if (!pacman_chomp.loadFromFile("chomp.wav"))
			cout << "hhhhhhhhh" << std::endl;
		Sound chomp;
		chomp.setBuffer(pacman_chomp);
		chomp.setVolume(5);

		SoundBuffer pacman_death;
		if (!pacman_death.loadFromFile("pacman_death.wav"))
			cout << "SHIIIT" << std::endl;
		Sound death;
		death.setBuffer(pacman_death);
		death.setVolume(20);

		SoundBuffer pacman_eatfruit;
		if (!pacman_eatfruit.loadFromFile("pacman_eatfruit.wav"))
			cout << "SHIIIT" << std::endl;
		Sound eatfruit;
		eatfruit.setBuffer(pacman_eatfruit);
		eatfruit.setVolume(20);

		SoundBuffer pacman_eatghost;
		if (!pacman_eatghost.loadFromFile("pacman_eatghost.wav"))
			cout << "SHIIIT" << std::endl;
		Sound eatghost;
		eatghost.setBuffer(pacman_eatghost);
		eatghost.setVolume(20);

		SoundBuffer pacman_extrapac;
		if (!pacman_extrapac.loadFromFile("pacman_eatghost.wav"))
			cout << "SHIIIT" << std::endl;
		Sound extrapac;
		extrapac.setBuffer(pacman_extrapac);
		extrapac.setVolume(20);

		SoundBuffer pacman_intermission;
		if (!pacman_intermission.loadFromFile("pacman_intermission.wav"))
			cout << "SHIIIT" << std::endl;
		Sound intermission;
		intermission.setBuffer(pacman_intermission);
		intermission.setVolume(20);

		//audio
		Font font, font1;
		Style::Resize;
		Style::Close;
		while (window.isOpen()) {
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
				switch (event.type) {
				case Event::KeyPressed:
					switch (event.key.code) {
					case Keyboard::E:
						window.close();
						break;
					}
				}

				switch (event.type) {
				case Event::KeyPressed:
					switch (event.key.code) {
					case Keyboard::U:
						sound.play();
						break;

					}
				}
				switch (event.type) {
				case Event::KeyPressed:
					switch (event.key.code) {
					case Keyboard::M:
						sound.stop();
						break;
					}
				}
				if (event.type == Event::KeyReleased) {
					if (event.key.code == Keyboard::Up)
					{
						menu.MoveUp();
						break;
					}
					if (event.key.code == Keyboard::Down)
					{
						menu.MoveDown();
						break;
					}

					//choose page
					if (event.key.code == Keyboard::Return) {
						int x = menu.GetpressedItem();
						if (x == 0) {
							window.close();
							active = 0;
						}
						if (x == 1) {
							window.close();
							active = 1;
						}
						if (x == 2) {
							window.close();
							active = 2;
						}
						if (x == 3) {
							window.close();
							active = 3;
						}
						if (x == 4) {
							window.close();
							active = 4;
						}
					}
				}
			}
			window.clear();

			window.draw(background);
			window.draw(background2);
			window.draw(sprite1);
			menu.draw(window);
			window.display();
		}
		if (active == 0) {
			sound.stop();
			music.play();
			RenderWindow window(VideoMode(800, 800), "Play", Style::Close);
			while (window.isOpen()){

				// Time equations
				ss.str("");

				ahmed = mohamed.getElapsedTime();
				s = ahmed.asSeconds();
				g = s / 3600;
				m = (s - (g * 3600)) / 60;
				s = s - (g * 3600 + m * 60);

				if (g < 10)
				{
					ss << "0" << g;
				}
				else
				{
					ss << g;
				}
				if (m < 10)
				{
					ss << ":" << "0" << m;
				}
				else
				{
					ss << ":" << m;
				}
				if (s < 10)
				{
					ss << ":" << "0" << s;
				}
				else
				{
					ss << ":" << s;
				}

				timer.setString(ss.str());


				
						
					Event event;
					while (window.pollEvent(event)) {
						
						switch (event.type) {
						case Event::KeyPressed:
							switch (event.key.code) {
							case Keyboard::BackSpace:
								window.close();
								break;
							}

						}
						sound.stop();
						if (event.type == Event::Closed)
							window.close();

						// pac movement
						if (event.type == Event::KeyPressed) {


							if (event.key.code == Keyboard::Down) {
								//pac.setRotation(90);
								pac.move(Vector2f(0, 6));
								pac2.move(Vector2f(0, 6));
								pac3.move(Vector2f(0, 6));
								pac4.move(Vector2f(0, 6));
								pac5.move(Vector2f(0, 6));
							}
							if (event.key.code == Keyboard::Up) {
								//pac.setRotation(-90);
								pac.move(Vector2f(0, -6));
								pac2.move(Vector2f(0, -6));
								pac3.move(Vector2f(0, -6));
								pac4.move(Vector2f(0, -6));
								pac5.move(Vector2f(0, -6));
							}
							if (event.key.code == Keyboard::Right) {
								//pac.setRotation(0);
								pac.move(Vector2f(6, 0));
								pac2.move(Vector2f(6, 0));
								pac3.move(Vector2f(6, 0));
								pac4.move(Vector2f(6, 0));
								pac5.move(Vector2f(6, 0));
							}
							if (event.key.code == Keyboard::Left) {
								//pac.setRotation(180);
								pac.move(Vector2f(-6, 0));
								pac2.move(Vector2f(-6, 0));
								pac3.move(Vector2f(-6, 0));
								pac4.move(Vector2f(-6, 0));
								pac5.move(Vector2f(-6, 0));

							}
							if (pac.getPosition().x == -18 || pac.getPosition().x == -14 && pac.getPosition().y == 372) {
								pac.setPosition(790, 372);
								pac2.setPosition(790, 372);
								pac3.setPosition(790, 372);
								pac4.setPosition(790, 372);
								pac5.setPosition(790, 372);
							}
							if (pac.getPosition().x == 804 || pac.getPosition().x == 802 && pac.getPosition().y == 372) {
								pac.setPosition(10, 372);
								pac2.setPosition(10, 372);
								pac3.setPosition(10, 372);
								pac4.setPosition(10, 372);
								pac5.setPosition(10, 372);
							}


						}
					}
					window.clear();



					// ghosts movement
					srand(time(NULL));
					int  PinkyDir = rand() % 4 + 1;
					if (PinkyDir == 1)
					{
						pinky.move(0, -0.4);
					}
					if (PinkyDir == 2)
					{
						pinky.move(0, 0.4);
					}
					if (PinkyDir == 3)
					{
						pinky.move(-0.4, 0);
					}
					if (PinkyDir == 4)
					{
						pinky.move(0.4, 0);
					}






					int  BlinkyDir = rand() % 4 + 1;
					if (BlinkyDir == 1)
					{
						blinky.move(0, -0.4);
					}
					if (BlinkyDir == 2)
					{
						blinky.move(0, 0.4);
					}
					if (BlinkyDir == 3)
					{
						blinky.move(-0.4, 0);
					}
					if (BlinkyDir == 4)
					{
						blinky.move(0.4, 0);
					}




					int InkyDir = rand() % 4 + 1;
					if (InkyDir == 1)
					{
						inky.move(0, -0.4);
					}
					if (InkyDir == 2)
					{
						inky.move(0, 0.4);
					}
					if (InkyDir == 3)
					{
						inky.move(-0.4, 0);
					}
					if (InkyDir == 4)
					{
						inky.move(0.4, 0);
					}





					int  ClydeDir = rand() % 4 + 1;
					if (ClydeDir == 1)
					{
						clyde.move(0, -0.4);
					}
					if (ClydeDir == 2)
					{
						clyde.move(0, 0.4);
					}
					if (ClydeDir == 3)
					{
						clyde.move(-0.4, 0);
					}
					if (ClydeDir == 4)
					{
						clyde.move(0.4, 0);
					}

					
					window.clear();
					if (event.type == Event::KeyReleased) {


						if (event.key.code == Keyboard::Down) {
							window.draw(pac2);
						}
						if (event.key.code == Keyboard::Up) {
							window.draw(pac2);
						}
						if (event.key.code == Keyboard::Right)
						{
							window.draw(pac2);
						}
						if (event.key.code == Keyboard::Left) {

							window.draw(pac2);
						}
					}

					if (event.type == Event::KeyPressed) {


						if (event.key.code == Keyboard::Down) {
							window.draw(pac4);
						}
						if (event.key.code == Keyboard::Up) {
							window.draw(pac5);
						}
						if (event.key.code == Keyboard::Right)
						{
							window.draw(pac);
						}
						if (event.key.code == Keyboard::Left) {

							window.draw(pac3);

						}
					}

					
					for (int i = 0; i < 23; i++)
					{
						for (int j = 0; j < 31; j++)
						{
							if (maze[i][j] == '#')
							{
								bluetile.setPosition(j * 25.7, i * 25.7 + 85);
								window.draw(bluetile);

								//collision pac with map

								if (pac.getGlobalBounds().intersects(bluetile.getGlobalBounds())) {

									if (event.type == Event::KeyPressed) {


										if (event.key.code == Keyboard::Down) {

											pac.move(Vector2f(0, -6));
											pac2.move(Vector2f(0, -6));
											pac3.move(Vector2f(0, -6));
											pac4.move(Vector2f(0, -6));
											pac5.move(Vector2f(0, -6));

										}



										if (event.key.code == Keyboard::Up) {

											pac.move(Vector2f(0, 6));
											pac2.move(Vector2f(0, 6));
											pac3.move(Vector2f(0, 6));
											pac4.move(Vector2f(0, 6));
											pac5.move(Vector2f(0, 6));

										}

										if (event.key.code == Keyboard::Right) {

											pac.move(Vector2f(-6, 0));
											pac2.move(Vector2f(-6, 0));
											pac3.move(Vector2f(-6, 0));
											pac4.move(Vector2f(-6, 0));
											pac5.move(Vector2f(-6, 0));

										}

										if (event.key.code == Keyboard::Left) {

											pac.move(Vector2f(6, 0));
											pac2.move(Vector2f(6, 0));
											pac3.move(Vector2f(6, 0));
											pac4.move(Vector2f(6, 0));
											pac5.move(Vector2f(6, 0));

										}


									}
								}
								//collision ghosts with map

								if (pinky.getGlobalBounds().intersects(bluetile.getGlobalBounds())) {

									if (PinkyDir == 1)
									{
										pinky.move(0, 0.4);
									}
									if (PinkyDir == 2)
									{
										pinky.move(0, -0.4);
									}
									if (PinkyDir == 3)
									{
										pinky.move(0.4, 0);
									}
									if (PinkyDir == 4)
									{
										pinky.move(-0.4, 0);
									}
								}

								if (blinky.getGlobalBounds().intersects(bluetile.getGlobalBounds())) {



									if (BlinkyDir == 1)
									{
										blinky.move(0, 0.4);
									}
									if (BlinkyDir == 2)
									{
										blinky.move(0, -0.4);
									}
									if (BlinkyDir == 3)
									{
										blinky.move(0.4, 0);
									}
									if (BlinkyDir == 4)
									{
										blinky.move(-0.4, 0);
									}
								}

								if (inky.getGlobalBounds().intersects(bluetile.getGlobalBounds())) {

									if (InkyDir == 1)
									{
										inky.move(0, 0.4);
									}
									if (InkyDir == 2)
									{
										inky.move(0, -0.4);
									}
									if (InkyDir == 3)
									{
										inky.move(0.4, 0);
									}
									if (InkyDir == 4)
									{
										inky.move(-0.4, 0);
									}

								}
								if (clyde.getGlobalBounds().intersects(bluetile.getGlobalBounds())) {

									if (ClydeDir == 1)
									{
										clyde.move(0, 0.4);
									}
									if (ClydeDir == 2)
									{
										clyde.move(0, -0.4);
									}
									if (ClydeDir == 3)
									{
										clyde.move(0.4, 0);
									}
									if (ClydeDir == 4)
									{
										clyde.move(-0.4, 0);
									}

								}




							}
							//collision pac with ghosts
							if (pac.getGlobalBounds().intersects(pinky.getGlobalBounds()))
							{
								pinky.setPosition(Vector2f(342, 396));
								pac.setPosition(30, 114);
								pac2.setPosition(30, 114);
								pac3.setPosition(30, 114);
								pac4.setPosition(30, 114);
								pac5.setPosition(30, 114);

								ScoreCounter -= 10;
								Lives--;
								death.play();
							}
							if (pac.getGlobalBounds().intersects(blinky.getGlobalBounds()))
							{
								blinky.setPosition(Vector2f(342, 396));
								pac.setPosition(30, 114);
								pac2.setPosition(30, 114);
								pac3.setPosition(30, 114);
								pac4.setPosition(30, 114);
								pac5.setPosition(30, 114);

								ScoreCounter -= 10;
								Lives--;
								death.play();
							}
							if (pac.getGlobalBounds().intersects(inky.getGlobalBounds()))
							{
								inky.setPosition(Vector2f(342, 396));
								pac.setPosition(30, 114);
								pac2.setPosition(30, 114);
								pac3.setPosition(30, 114);
								pac4.setPosition(30, 114);
								pac5.setPosition(30, 114);

								ScoreCounter -= 10;
								Lives--;
								death.play();
							}
							if (pac.getGlobalBounds().intersects(clyde.getGlobalBounds()))
							{
								clyde.setPosition(Vector2f(342, 396));
								pac.setPosition(30, 114);
								pac2.setPosition(30, 114);
								pac3.setPosition(30, 114);
								pac4.setPosition(30, 114);
								pac5.setPosition(30, 114);

								ScoreCounter -= 10;
								Lives--;
								death.play();
							}


							if (maze[i][j] == ' ')
							{
								dots.setPosition(j * 25.7 + 9.5, i * 25.7 + 9.5 + 85);
								window.draw(dots);

								if (pac.getGlobalBounds().intersects(dots.getGlobalBounds()))
								{
									score.str("");
									maze[i][j] = '0';
									score << ScoreCounter;
									scorenum.setString(score.str());
									ScoreCounter++;
									maze[i][j] = '0';
									chomp.play();
								}

							}
							if (maze[i][j] == '!')
							{
								cherry.setPosition(j * 25.7 + 3, i * 25.7 + 83);
								window.draw(cherry);
								if (pac.getGlobalBounds().intersects(cherry.getGlobalBounds()))
								{

									maze[i][j] = '0';


									ScoreCounter += 5;
									Lives++;
									eatfruit.play();



								}
							}
						}


					}
					for (int i = 0; i < Lives; i++)
					{
						heartt.setPosition(20 + i * 62, 680);
						heartt.setScale(Vector2f(0.17, 0.17));
						window.draw(heartt);

					}
					if (Lives <= 0) {
						c++;
						if (c == 1) {
							music.stop();
							intermission.play();
						}
						window.draw(over);
						window.draw(win2);
						scorenum.setPosition(700, 410);
						scorenum.setCharacterSize(70);
						pinky.setPosition(Vector2f(-1000, -1000));
						pinky.setColor(Color(0, 0, 0));
						blinky.setPosition(Vector2f(-1000, -1000));
						blinky.setColor(Color(0, 0, 0));
						clyde.setPosition(Vector2f(-1000, -1000));
						clyde.setColor(Color(0, 0, 0));
						inky.setPosition(Vector2f(-1000, -1000));
						inky.setColor(Color(0, 0, 0));
					}
					if (ScoreCounter == 341 && Lives == 1 || ScoreCounter == 351 && Lives == 2 || ScoreCounter == 361 && Lives == 3 || ScoreCounter == 371 && Lives == 4 || ScoreCounter == 381 && Lives == 5) {

						window.draw(win1);
						window.draw(win2);
						scorenum.setPosition(700, 410);
						scorenum.setCharacterSize(70);

						pinky.setPosition(Vector2f(-1000, -1000));
						pinky.setColor(Color(0, 0, 0));
						blinky.setPosition(Vector2f(-1000, -1000));
						blinky.setColor(Color(0, 0, 0));
						clyde.setPosition(Vector2f(-1000, -1000));
						clyde.setColor(Color(0, 0, 0));
						inky.setPosition(Vector2f(-1000, -1000));
						inky.setColor(Color(0, 0, 0));
					}

					//window.draw(pac);
					window.draw(scorenum);
					window.draw(scoretext);
					window.draw(timer);
					window.draw(timers);
					window.draw(pinky);
					window.draw(blinky);
					window.draw(clyde);
					window.draw(bluetile);
					window.draw(inky);
					
					window.display();

					



				}
			
		}
		if (active == 1) {
			RenderWindow win(VideoMode(800, 800), "Controls", Style::Close);
			while (win.isOpen()) {
				Event event;
				while (win.pollEvent(event)) {

					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::U:
							sound.play();
							break;

						}
					}
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::M:
							sound.stop();
							break;
						}
					}
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::BackSpace:
							win.close();
							break;
						}
					}

					if (event.type == Event::Closed)
						win.close();
				}
				win.clear();
				t3.draw(win);
				win.draw(background2);
				win.draw(background);
				win.display();
			}
		}
		if (active == 2) {
			RenderWindow win(VideoMode(800, 800), "Contain", Style::Close);
			while (win.isOpen()) {
				Event event;
				while (win.pollEvent(event)) {
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::U:
							sound.play();
							break;

						}
					}
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::M:
							sound.stop();
							break;
						}
					}
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::BackSpace:
							win.close();
							break;
						}
					}
					if (event.type == Event::Closed)
						win.close();
				}
				win.clear();
				cont.draw(win);
				win.draw(background2);
				//win.draw(background);
				win.display();
			}
		}
		if (active == 3) {
			RenderWindow win(VideoMode(800, 800), "About Us", Style::Close);
			while (win.isOpen()) {
				Event event;
				while (win.pollEvent(event)) {
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::U:
							sound.play();
							break;

						}
					}
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::M:
							sound.stop();
							break;
						}
					}
					switch (event.type) {
					case Event::KeyPressed:
						switch (event.key.code) {
						case Keyboard::BackSpace:
							win.close();
							break;
						}
					}
					if (event.type == Event::Closed)
						win.close();
				}
				win.clear();
				txt.draw(win);
				win.draw(background2);
				win.draw(background);

				win.display();
			}
		}
		if (active == 4) {
			break;
		}
	}
	return 0;
}