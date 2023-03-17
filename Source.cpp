#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include"Interface.h"
#include"Map.h"
#include"Animations.h"
#include"Endof.h"
#define widthResolution 600
#define heightResolution 400
float pinkSpeed = 2 * 0.05*1, redSpeed = 2 * 0.07*1, blueSpeed = 2 * 0.04*1, brownSpeed = 2 * 0.06*1;		//Speeds of ghosts
using namespace std;
using namespace sf;
//enum Direction { Right, Left, Up, Down };
enum Collision { freezeUp, freezeDown, freezeRight, freezeLeft, animate };
enum Blue { bRight, bLeft, bUp, bDown };
enum Red { rRight, rLeft, rUp, rDown };
enum Brown { brRight, brLeft, brUp, brDown };
enum Pink { pRight, pLeft, pUp, pDown };
enum pinkColission { freezeUpPink, freezeDownPink, freezeRightPink, freezeLeftPink };

int main() {
	Animations a;
	Interface o;
	Map b;
	b.Window.create(sf::VideoMode(widthResolution, heightResolution), "PAKISTANI PACMAN");		//Create Window via SFML
	b.Window.setKeyRepeatEnabled(false);
	Vector2i source(0, Right);
	FreeConsole();		//Get Rid of Console
	a.loadTextures();
	a.createSprites();
	a.setSprites();		//Animation object sets sprites from textures

	for (int i = 0; i<161; i++)
	{
		b.circles[i].setFillColor(Color::Cyan);
		b.circles[i].setRadius(4);
	}
	Clock clock;
	Time q, q1;
	Time ti, ti1;
	Clock Controlclock;
	sf::CircleShape c1; c1.setRadius(2.8); c1.setFillColor(sf::Color::Cyan);
	Vector2f sourceGhost(0, 0);
	Vector2f source1(0, 0);
	Vector2f sourceBlueGhost(0, 2);
	Vector2f sourceBrownGhost(0, 3);
	Vector2f sourcePinkGhost(0, 1);
	Vector2f sourceDeadGhost(0, 4);
	srand(time(NULL));
	int j = 0, checkCircle2 = 0, c = 1, p = 0, controlAnimation = 0, controlMovement = 0, i = 2, checkCircle = 0, move = animate, freezePink = 0, moveBlue = 0, moveBrown = 0, movePink = 0, moveRed = 0, drawPacman = 0;

	CircleShape Circle(11);		//The Red Dot
	CircleShape Circle2(11);		//The Blue Dot
	movePink = pRight; moveRed = rUp; moveBlue = bUp; moveBrown = brUp;
	Circle.setFillColor(Color::Red);

	Circle.setPosition(20, 20);

	int start = 0;
	int exit = 0, check = 0, g = 0;
	Vector2i glocalPosition(0, 0);



	b.Window.draw(a.Menu);		//Draw Menu in the created Window
	b.Window.display();			//Render the drawn window


								/*			Load and Set Sounds			*/
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	if (soundBuffer.loadFromFile("start.wav"))
		sound.setBuffer(soundBuffer);

	sf::SoundBuffer soundBuffer1;
	sf::Sound sound1;
	if (soundBuffer1.loadFromFile("dead.wav"))
		sound1.setBuffer(soundBuffer1);
	sf::SoundBuffer soundBuffer2;
	sf::Sound sound2;
	if (soundBuffer2.loadFromFile("click.wav"))
		sound2.setBuffer(soundBuffer2);
	sf::SoundBuffer soundBuffer3;
	sf::Sound sound3;
	if (soundBuffer3.loadFromFile("eat.wav"))
		sound3.setBuffer(soundBuffer3);
	sf::SoundBuffer soundBuffer5;
	sf::Sound sound5;
	if (soundBuffer5.loadFromFile("start3.wav"))
		sound5.setBuffer(soundBuffer5);
	Circle2.setPosition(550, 350);
	Circle2.setFillColor(Color::Blue);

	sound5.play();
	sound5.setVolume(10);
	sound.setVolume(10);
	b.setBorder();
	while (start == 0) {		//Menu Logic


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			glocalPosition = Mouse::getPosition(b.Window);
		}



		if (250 < glocalPosition.y&&glocalPosition.y  <330)
		{
			cout << glocalPosition.x;
			cout << glocalPosition.y;


			if (185 < glocalPosition.x&& glocalPosition.x < 240) { start++; }

			else if (330 < glocalPosition.x&&glocalPosition.x  <386) { exit++; }

			if (start == 1)
			{
				sound5.pause();
				sound2.play();
				b.Window.clear();
			}
			else if (exit == 1)
			{
				sound5.pause();
				sound2.play();
				b.Window.close();
			}
			sound2.pause();
		}


	}



	while (b.Window.isOpen())
	{
		sound5.pause();
		Event Event;




		for (int j = 0; j <= heightResolution; j++)		//Horizontal Wrap Around
		{

			if (a.sprite.getPosition().y >= j && a.sprite.getPosition().x >= 0 && a.sprite.getPosition().x <= 1)
			{
				a.sprite.move(widthResolution - 5, 1);
			}
			if (a.sprite.getPosition().y >= j && a.sprite.getPosition().x >= 599 && a.sprite.getPosition().x <= 600)
			{
				a.sprite.move(-widthResolution + 5, 1);
			}
			if (a.spritePinkGhosts.getPosition().y >= j &&a.spritePinkGhosts.getPosition().x >= 0 && a.spritePinkGhosts.getPosition().x <= 1)
			{
				a.spritePinkGhosts.move(widthResolution - 5, 1);
			}
			if (a.spritePinkGhosts.getPosition().y >= j && a.spritePinkGhosts.getPosition().x >= 599 && a.spritePinkGhosts.getPosition().x <= 600)
			{
				a.spritePinkGhosts.move(-widthResolution + 5, 1);
			}
			if (a.spriteGhosts.getPosition().y >= j && a.spriteGhosts.getPosition().x >= 0 && a.spriteGhosts.getPosition().x <= 1)
			{
				a.spriteGhosts.move(widthResolution - 5, 1);
			}
			if (a.spriteGhosts.getPosition().y >= j && a.spriteGhosts.getPosition().x >= 599 && a.spriteGhosts.getPosition().x <= 600)
			{
				a.spriteGhosts.move(-widthResolution + 5, 1);
			}
			if (a.spriteBlueGhosts.getPosition().y >= j && a.spriteBlueGhosts.getPosition().x >= 0 && a.spriteBlueGhosts.getPosition().x <= 1)
			{
				a.spriteBlueGhosts.move(widthResolution - 5, 1);
			}
			if (a.spriteBlueGhosts.getPosition().y >= j &&a.spriteBlueGhosts.getPosition().x >= 599 &&a.spriteBlueGhosts.getPosition().x <= 600)
			{
				a.spriteBlueGhosts.move(-widthResolution + 5, 1);
			}
			if (a.spriteBrownGhosts.getPosition().y >= j && a.spriteBrownGhosts.getPosition().x >= 0 && a.spriteBrownGhosts.getPosition().x <= 1)
			{
				a.spriteBrownGhosts.move(widthResolution - 5, 1);
			}
			if (a.spriteBrownGhosts.getPosition().y >= j && a.spriteBrownGhosts.getPosition().x >= 599 && a.spriteBrownGhosts.getPosition().x <= 600)
			{
				a.spriteBrownGhosts.move(-widthResolution + 5, 1);
			}

		}
		for (int j = 0; j <= widthResolution; j++)		//Vertical Wrap Around
		{
			if (a.sprite.getPosition().x >= j && a.sprite.getPosition().y >= 0 && a.sprite.getPosition().y <= 1)
			{
				a.sprite.move(1, heightResolution - 5);
			}
			if (a.sprite.getPosition().x >= j && a.sprite.getPosition().y >= 399 && a.sprite.getPosition().y <= 400)
			{
				a.sprite.move(1, -heightResolution + 5);
			}
		}

		sound.play();



		while (b.Window.pollEvent(Event))		//Check if event has occured i.e: KeyPress, windowClosed
		{



			switch (Event.type)
			{



			case Event::Closed:
				b.Window.close();
				break;
			case Event::KeyPressed:

				if (Event.key.code == Keyboard::Up)
				{
					source.y = Up;
					i = 0;

				}
				else if (Event.key.code == Keyboard::Down)
				{
					source.y = Down;
					i = 1;

				}
				else if (Event.key.code == Keyboard::Right)
				{
					source.y = Right;
					i = 2;

				}
				else if (Event.key.code == Keyboard::Left)
				{
					source.y = Left;
					i = 3;

				}
				break;

			}


			move = animate;
		}

		switch (i)		// Move pacman corresponding to event code caught in snippet above
		{
		case 0:
			if (move != freezeUp)
				a.sprite.move(0, -0.1 * 2);
			break;
		case 1:
			if (move != freezeDown)
				a.sprite.move(0, 0.1 * 2);
			break;
		case 2:
			if (move != freezeRight)
				a.sprite.move(.1 * 2, 0);
			break;
		case 3:
			if (move != freezeLeft)
				a.sprite.move(-.1 * 2, 0);
			break;
		}

		a.frameCounter += a.frameSpeed*clock.restart().asSeconds();
		a.createAnimation(source);		//PACMAN animate


		a.g_frameCounter += a.g_frameSpeed*clock.restart().asSeconds();
		a.createGhostsAnimation(sourceGhost, sourceBlueGhost, sourceBrownGhost, sourcePinkGhost);		//GHOST animate
																										//controlAnimation determines whether a circle is recently consumed by PACMAN or not
		if (controlAnimation == 0)		// In normal mode, set ghosts' sprites from textures.
		{
			a.spriteGhosts.setTextureRect(IntRect(sourceGhost.x * 34.5, sourceGhost.y * 30, 33, 30));
			a.spriteBlueGhosts.setTextureRect(IntRect(sourceBlueGhost.x * 34.5, sourceBlueGhost.y * 32, 33, 32));
			a.spriteBrownGhosts.setTextureRect(IntRect(sourceBrownGhost.x * 34.5, sourceBrownGhost.y * 32, 33, 32));
			a.spritePinkGhosts.setTextureRect(IntRect(sourcePinkGhost.x * 34.5, sourcePinkGhost.y * 30, 33, 30));
		}
		else
		{						// Set ghosts' sprites from texture when a circle is recently consumed.
			a.spriteGhosts.setTextureRect(IntRect(sourceDeadGhost.x * 34.5, sourceDeadGhost.y * 32, 33, 32));
			a.spriteBlueGhosts.setTextureRect(IntRect(sourceDeadGhost.x * 34.5, sourceDeadGhost.y * 32, 33, 32));
			a.spriteBrownGhosts.setTextureRect(IntRect(sourceDeadGhost.x * 34.5, sourceDeadGhost.y * 32, 33, 32));
			a.spritePinkGhosts.setTextureRect(IntRect(sourceDeadGhost.x * 34.5, sourceDeadGhost.y * 32, 33, 32));
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Pink Ghost Control
		if (movePink == pDown)		    //Pink Ghost down movement
		{
			a.spritePinkGhosts.move(0, pinkSpeed);
		}
		else if (movePink == pUp)     //Pink Ghost Up movement
		{
			a.spritePinkGhosts.move(0, -pinkSpeed);
		}

		else if (movePink == pLeft)      //Pink Ghost Left movement
		{
			a.spritePinkGhosts.move(-pinkSpeed, 0);
		}
		else if (movePink == pRight)       //Pink Ghost Right movement
		{
			a.spritePinkGhosts.move(pinkSpeed, 0);
		}

		//Pink Ghost boundary control. Avoids flying over the Barriers

		if (movePink == pRight && ((a.spritePinkGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds()))))
		{
			a.spritePinkGhosts.move(-pinkSpeed, 0);
			if (a.sprite.getPosition().y - a.spritePinkGhosts.getPosition().y>0)
				movePink = pDown;

			else
				movePink = pUp;

		}
		else if (movePink == pLeft && ((a.spritePinkGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds()))))
		{
			a.spritePinkGhosts.move(pinkSpeed, 0);
			if (a.sprite.getPosition().y - a.spritePinkGhosts.getPosition().y>0)
				movePink = pDown;
			else
				movePink = pUp;
		}
		else if (movePink == pDown && ((a.spritePinkGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds()))))
		{
			a.spritePinkGhosts.move(0, -pinkSpeed);
			if (a.sprite.getPosition().x - a.spritePinkGhosts.getPosition().x>0)
				movePink = pRight;
			else
				movePink = pLeft;

		}

		else if (movePink == pUp && ((a.spritePinkGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spritePinkGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds()))))
		{
			a.spritePinkGhosts.move(0, pinkSpeed);
			if (a.sprite.getPosition().x - a.spritePinkGhosts.getPosition().x>0)
				movePink = pRight;
			else
				movePink = pLeft;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Blue Ghost Control
		if (moveBlue == bDown)			// blue ghost down movement
		{
			a.spriteBlueGhosts.move(0, blueSpeed);
		}
		else if (moveBlue == bUp)                                    // blue ghost up movement
		{
			a.spriteBlueGhosts.move(0, -blueSpeed);
		}

		else if (moveBlue == bLeft)                              // blue ghost left movement
		{
			a.spriteBlueGhosts.move(-blueSpeed, 0);
		}
		else if (moveBlue == bRight)                            // blue ghost right movement
		{
			a.spriteBlueGhosts.move(blueSpeed, 0);
		}


		//  Blue Ghost boundary control. Avoids flying over the Barriers


		if (moveBlue == bRight && (((a.spriteBlueGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBlueGhosts.move(-blueSpeed, 0);
			if (a.sprite.getPosition().y - a.spriteBlueGhosts.getPosition().y>0)
				moveBlue = bDown;

			else
				moveBlue = bUp;

		}
		else if (moveBlue == bLeft && (((a.spriteBlueGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBlueGhosts.move(blueSpeed, 0);
			if (a.sprite.getPosition().y - a.spriteBlueGhosts.getPosition().y>0)
				moveBlue = bDown;
			else
				moveBlue = bUp;
		}
		else if (moveBlue == bDown && (((a.spriteBlueGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBlueGhosts.move(0, -blueSpeed);
			if (a.sprite.getPosition().x - a.spriteBlueGhosts.getPosition().x>0)
				moveBlue = bRight;
			else
				moveBlue = bLeft;

		}

		else if (moveBlue == bUp && (((a.spriteBlueGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBlueGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBlueGhosts.move(0, blueSpeed);
			if (a.sprite.getPosition().x - a.spriteBlueGhosts.getPosition().x>0)
				moveBlue = bRight;
			else
				moveBlue = bLeft;
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Red Ghost Control
		if (moveRed == rDown)		// Red Ghost down movement
		{
			a.spriteGhosts.move(0, redSpeed);
		}
		else if (moveRed == rUp)      // Red Ghost Up movement
		{
			a.spriteGhosts.move(0, -redSpeed);
		}

		else if (moveRed == rLeft)      // Red Ghost left movement
		{
			a.spriteGhosts.move(-redSpeed, 0);
		}
		else if (moveRed == rRight)       // Red Ghost right movement
		{
			a.spriteGhosts.move(redSpeed, 0);
		}

		//  Red Ghost boundary control. Avoids flying over the Barriers

		if (moveRed == rRight && (((a.spriteGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteGhosts.move(-redSpeed, 0);
			if (a.sprite.getPosition().y - a.spriteGhosts.getPosition().y>0)
				moveRed = rDown;

			else
				moveRed = rUp;

		}
		else if (moveRed == rLeft && (((a.spriteGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteGhosts.move(redSpeed, 0);
			if (a.sprite.getPosition().y - a.spriteGhosts.getPosition().y>0)
				moveRed = rDown;
			else
				moveRed = rUp;
		}
		else if (moveRed == rDown && (((a.spriteGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteGhosts.move(0, -redSpeed);
			if (a.sprite.getPosition().x - a.spriteGhosts.getPosition().x>0)
				moveRed = rRight;
			else
				moveRed = rLeft;

		}

		else if (moveRed == rUp && (((a.spriteGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteGhosts.move(0, redSpeed);
			if (a.sprite.getPosition().x - a.spriteGhosts.getPosition().x>0)
				moveRed = rRight;
			else
				moveRed = rLeft;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////
		//Brown Ghost control
		if (moveBrown == brDown)		                            //Brwon Ghost down movement
		{
			a.spriteBrownGhosts.move(0, brownSpeed);
		}
		else if (moveBrown == brUp)                                    //Brwon Ghost up movement
		{
			a.spriteBrownGhosts.move(0, -brownSpeed);
		}

		else if (moveBrown == brLeft)                                   //Brwon Ghost left movement
		{
			a.spriteBrownGhosts.move(-brownSpeed, 0);
		}
		else if (moveBrown == brRight)                                  //Brwon Ghost right movement
		{
			a.spriteBrownGhosts.move(brownSpeed, 0);
		}


		//  Brown Ghost boundary control. Avoids flying over the Barriers


		if (moveBrown == brRight && (((a.spriteBrownGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBrownGhosts.move(-brownSpeed, 0);
			if (a.sprite.getPosition().y - a.spriteBrownGhosts.getPosition().y>0)
				moveBrown = brDown;

			else
				moveBrown = brUp;

		}
		else if (moveBrown == brLeft && (((a.spriteBrownGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBrownGhosts.move(brownSpeed, 0);
			if (a.sprite.getPosition().y - a.spriteBrownGhosts.getPosition().y>0)
				moveBrown = brDown;
			else
				moveBrown = brUp;
		}
		else if (moveBrown == brDown && (((a.spriteBrownGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBrownGhosts.move(0, -brownSpeed);
			if (a.sprite.getPosition().x - a.spriteBrownGhosts.getPosition().x>0)
				moveBrown = brRight;
			else
				moveBrown = brLeft;

		}

		else if (moveBrown == brUp && (((a.spriteBrownGhosts.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l21.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.spriteBrownGhosts.getGlobalBounds().intersects(b.l31.getGlobalBounds())))))
		{
			a.spriteBrownGhosts.move(0, brownSpeed);
			if (a.sprite.getPosition().x - a.spriteBrownGhosts.getPosition().x>0)
				moveBrown = brRight;
			else
				moveBrown = brLeft;
		}
		///////////////////////////////////////////////////////////////////////////////////
		// PACMAN boundary control. Avoids flying over the Barriers.
		if (source.y == Down && ((a.sprite.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l21.getGlobalBounds())) || a.sprite.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l31.getGlobalBounds())))
		{
			a.sprite.move(0, -.1);
			move = freezeDown;
		}
		else if (source.y == Up && ((a.sprite.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l21.getGlobalBounds())) || a.sprite.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l31.getGlobalBounds())))
		{
			a.sprite.move(0, .1);
			move = freezeUp;
		}
		else if (source.y == Right && ((a.sprite.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l21.getGlobalBounds())) || a.sprite.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l31.getGlobalBounds())))
		{
			a.sprite.move(-.1, 0);
			move = freezeRight;
		}
		else if (source.y == Left && ((a.sprite.getGlobalBounds().intersects(b.l1.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l2.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l3.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l4.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l5.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l6.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l7.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l8.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l9.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l10.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l11.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l12.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l13.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l14.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l15.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l16.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l17.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l18.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l19.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l20.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l21.getGlobalBounds())) || a.sprite.getGlobalBounds().intersects(b.l22.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l23.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l24.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l25.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l26.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l27.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l28.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l29.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l30.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(b.l31.getGlobalBounds())))
		{
			a.sprite.move(.1, 0);
			move = freezeLeft;
		}

		/////////////////////////////////////////////////////////////////////////////
		if (a.sprite.getGlobalBounds().intersects(Circle.getGlobalBounds()))		//If Red Circle is Consumed
		{
			Circle.setRadius(0);		// Red Circle Vanishes
			Circle.~CircleShape();		//Circle Object Dies
			controlMovement++;
			controlAnimation++;		//Sets Control Animation to 1. Causing the ghosts to assume DEAD_MODE
			pinkSpeed = -1 * pinkSpeed;		//Reverse Speed of Ghosts
			blueSpeed = -1 * blueSpeed;
			redSpeed = -1 * redSpeed;
			brownSpeed = -1 * brownSpeed;
			checkCircle++;
			check++;

			Controlclock.restart();
			ti = seconds(5);
		}
		q = Controlclock.getElapsedTime();
		cout << q.asSeconds() << endl;
		cout << ti.asSeconds() << endl;
		//cout<<ti.asSeconds();
		if (p == 0 && ti.asSeconds() != 0) {			// if timer expires Return ghosts to normal.
			if (q.asSeconds() >ti.asSeconds())
			{
				pinkSpeed = -1.00* pinkSpeed;
				blueSpeed = -1.00 * blueSpeed;
				redSpeed = -1.00 * redSpeed;
				brownSpeed = -1.00 * brownSpeed;
				controlAnimation = 0;
				p = 1;
				check = 0;
			}
		}
		///
		if (Circle.getRadius() == 0) // If Red circle is consumed, make available the Blue circle.
		{
			if (a.sprite.getGlobalBounds().intersects(Circle2.getGlobalBounds()))		// If blue circle is consumed
			{
				Circle2.setRadius(0);		// Blue Circle Vanishes
				Circle2.~CircleShape();		// Shape Dies.
				controlMovement++;
				controlAnimation++;		//	Cause the Ghosts to assume DEAD_MODE
				pinkSpeed = -1 * pinkSpeed;	// Reverse Ghost speeds
				blueSpeed = -1 * blueSpeed;
				redSpeed = -1 * redSpeed;
				brownSpeed = -1 * brownSpeed;
				checkCircle2++;
				check++;

				Controlclock.restart();
				ti1 = seconds(5);
			}
			q1 = Controlclock.getElapsedTime();

			if (g == 0 && ti1.asSeconds() != 0) {
				if (q1.asSeconds() >ti1.asSeconds())
				{
					pinkSpeed = -1.00* pinkSpeed;		//Reset Ghost Speeds to Original Mode.
					blueSpeed = -1.00 * blueSpeed;
					redSpeed = -1.00 * redSpeed;
					brownSpeed = -1.00 * brownSpeed;
					controlAnimation = 0;		//Reset Ghosts to Original Mode
					g = 1;
					check = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////
		if ((check == 0) && (a.sprite.getGlobalBounds().intersects(a.spriteBlueGhosts.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(a.spriteGhosts.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(a.spritePinkGhosts.getGlobalBounds()) || a.sprite.getGlobalBounds().intersects(a.spriteBrownGhosts.getGlobalBounds())))
		{//^ If a normal Ghost collides with PACMAN
					//GAME OVER!!!
			b.Window.clear();
			b.Window.draw(a.Gameover);
			b.Window.display();
			sound1.play();                 // sound of game over
			b.Window.clear();
			Sleep(2000);
			b.Window.close();           // screen clears
			main();                   // back to main menu 


		}
		else if ((check == 1) && (a.sprite.getGlobalBounds().intersects(a.spriteBlueGhosts.getGlobalBounds())))
		{
			a.spriteBlueGhosts.setPosition(200, 60);
			check = 0;
		}
		else if ((check == 1) && (a.sprite.getGlobalBounds().intersects(a.spriteGhosts.getGlobalBounds())))
		{
			a.spriteGhosts.setPosition(290, 180);
			check = 0;
		}
		else if ((check == 1) && (a.sprite.getGlobalBounds().intersects(a.spritePinkGhosts.getGlobalBounds())))
		{
			a.spritePinkGhosts.setPosition(300, 235);
			check = 0;
		}
		else if ((check == 1) && (a.sprite.getGlobalBounds().intersects(a.spriteBrownGhosts.getGlobalBounds())))
		{
			a.spriteBrownGhosts.setPosition(300, 60);
			check = 0;
		}

		////////////////////////////////////////////////////////////////////////////

		for (int k = 0; k<161; k++) {
			if (a.sprite.getGlobalBounds().intersects(b.circles[k].getGlobalBounds())) {

				b.circles[k].setRadius(0);


			}
		}
		j = 0;
		b.setCircles(j);
		b.printCircles(j);
		int countC = 0;
		for (int k = 0; k <= 161; k++)
		{
			if (b.circles[k].getRadius() == 0)
				countC++;
		}
		if (countC>=145)
			{
			Endof obj;
			obj.set();
			Sprite q=obj.win();
			q.setScale(1.2,.84);
			b.Window.clear();
			b.Window.draw(q);
			b.Window.display();
			Sleep(2000);
			b.Window.clear();
			b.Window.close();
			main();
		
			}

		a.sprite.setScale(1.55, 1.55);
		if (checkCircle == 0)
			b.Window.draw(Circle);
		if (checkCircle2 == 0)
			b.Window.draw(Circle2);
		if (drawPacman == 0)
			b.Window.draw(a.sprite);

		//drawing of ghosts

		b.Window.draw(a.spriteGhosts);
		b.Window.draw(a.spriteBlueGhosts);
		b.Window.draw(a.spriteBrownGhosts);
		b.Window.draw(a.spritePinkGhosts);
		b.printBorder();               // printing of border
		b.Window.display();            // displaying the menu
		b.Window.clear();              // clearing the screen 
		sound.pause();                 // pausing the game ringtone 

	}

}

