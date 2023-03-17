#pragma once
#include<SFML/Graphics.hpp>
#include "Animations.h"
#include "Map.h"
enum Direction { Right, Left, Up, Down };
class Animations
{
public:
	Animations();
	~Animations();
	sf::Texture texture;
	sf::Texture ghosts;
	sf::Texture ghostsBlue;
	sf::Texture ghostsPink;
	sf::Texture ghostsBrown;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture deadGhosts;
	sf::Sprite sprite;
	sf::Sprite spriteBlueGhosts;
	sf::Sprite spritePinkGhosts;
	sf::Sprite spriteBrownGhosts;
	sf::Sprite spriteGhosts;
	sf::Sprite Menu;
	sf::Sprite Gameover;
	sf::Sprite spritedeadGhosts;
	void createGhostsAnimation(sf::Vector2f sourceGhost, sf::Vector2f sourceBlueGhost, sf::Vector2f sourceBrownGhost, sf::Vector2f sourcePinkGhost);
	float g_frameCounter = 0, g_frameSpeed = 20000, g_frameSwitch = 10;
	int frameCounter = 0, frameSpeed = 4000, frameSwitch = 10;
	void createAnimation(sf::Vector2i);
	void createSprites();
	void setSprites();
	void loadTextures();
	
};

