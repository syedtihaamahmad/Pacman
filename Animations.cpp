#include "Animations.h"
#include<SFML/Graphics.hpp>
#include"Map.h"
#include<SFML/Window.hpp>

Animations::Animations()
{

}


Animations::~Animations()
{
}
void Animations::createSprites()
{
	sprite.setTexture(texture);
	spriteBlueGhosts.setTexture(ghostsBlue);
	spritePinkGhosts.setTexture(ghostsPink);
	spriteBrownGhosts.setTexture(ghostsBrown);
	spriteGhosts.setTexture(ghosts);
	Menu.setTexture(texture1);
	Gameover.setTexture(texture2);
	spritedeadGhosts.setTexture(deadGhosts);
}
void Animations::setSprites()
{
	Gameover.setScale(.6, .5);
	spriteGhosts.setPosition(290, 180);
	spritePinkGhosts.setPosition(300, 235);
	spriteBlueGhosts.setPosition(200, 60);
	spriteBrownGhosts.setPosition(300, 60);
	spriteGhosts.setScale(.8, .8);
	spritePinkGhosts.setScale(.8, .8);
	spriteBlueGhosts.setScale(.8, .8);
	spriteBrownGhosts.setScale(.8, .8);
	sprite.setPosition(60, 60);
	Menu.setScale(.5, .5);

}


void Animations::createAnimation(sf::Vector2i source)
{

	if (frameCounter >= frameSwitch)
	{
		frameCounter = 0;
		source.x++;
		if (source.x * 16 >= texture.getSize().x)
			source.x = 0;
	}
	sprite.setTextureRect(sf::IntRect(source.x * 16, source.y * 16, 16, 16));
}
void Animations::createGhostsAnimation(sf::Vector2f sourceGhost, sf::Vector2f sourceBlueGhost, sf::Vector2f sourceBrownGhost, sf::Vector2f sourcePinkGhost)
{
	if (g_frameCounter > g_frameSwitch)
	{
		g_frameCounter = 0;
		sourceGhost.x += 1;
		if (sourceGhost.x * 34.5 >= ghosts.getSize().x)
			sourceGhost.x = 0;
		sourceBlueGhost.x += 1;
		if (sourceBlueGhost.x * 34.5 >= ghostsBlue.getSize().x)
			sourceBlueGhost.x = 0;
		sourceBrownGhost.x += 1;
		if (sourceBrownGhost.x * 34.5 >= ghostsBrown.getSize().x)
			sourceBrownGhost.x = 0;
		sourcePinkGhost.x += 1;
		if (sourcePinkGhost.x * 34.5 >= ghostsPink.getSize().x)
			sourcePinkGhost.x = 0;
	}
}
void Animations::loadTextures()
{

	ghosts.loadFromFile("ghosts.png");
	ghostsBlue.loadFromFile("ghosts.png");
	ghostsBrown.loadFromFile("ghosts.png");
	ghostsPink.loadFromFile("ghosts.png");
	texture.loadFromFile("pac1.png");
	texture1.loadFromFile("mainmenu.png");
	texture2.loadFromFile("gameover.png");
	deadGhosts.loadFromFile("ghosts.png");
}