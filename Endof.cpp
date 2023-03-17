#include "Endof.h"
#include <SFML/Graphics.hpp>
Endof::Endof(void)
{
}
sf::Sprite Endof::win(){ 
	
	
	//winner.setScale(2.0,2.0);
	//winner.setOrigin(300,200);
	return winner; 

}

void ::Endof::set()
{
	t1.loadFromFile("winner.png");
	winner.setTexture(t1);
}
