#pragma once
#include<SFML/Graphics.hpp>
#include "Interface.h"


class Map:public Interface
{
public:
	Map();
	~Map();
	
	void printBorder();
	void printCircles(int);
	sf::CircleShape circles[161];
	void setCircles(int);
	sf::RectangleShape l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l18,l19,l20,l21,l22,l23,l24,l25,l26,l27,l28,l29,l30,l31;
	void setBorder();
};

