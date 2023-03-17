#include "Map.h"
#include "Interface.h"
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>



Map::Map()
{
}


Map::~Map()
{
}

void Map::printBorder()
{
	Window.draw(l1);
	Window.draw(l2);
	Window.draw(l3);
	Window.draw(l4);
	Window.draw(l5);
	Window.draw(l6);
	Window.draw(l7);
	Window.draw(l8);
	Window.draw(l9);
	Window.draw(l10);
	Window.draw(l11);
	Window.draw(l12);
	Window.draw(l13);
	Window.draw(l14);
	Window.draw(l15);
	Window.draw(l16);
	Window.draw(l17);
	Window.draw(l18);
	Window.draw(l19);
	Window.draw(l20);
	Window.draw(l21);
	Window.draw(l22);
	Window.draw(l23);
	Window.draw(l24);
	Window.draw(l25);
	Window.draw(l26);
	Window.draw(l27);
	Window.draw(l28);
	Window.draw(l29);
	Window.draw(l30);
	Window.draw(l31);
}
void Map::setBorder()
{
	l1.setSize(sf::Vector2f(580, 8)); l1.setPosition(5, 5);
	l2.setSize(sf::Vector2f(8, 170)); l2.setPosition(5, 5); l2.setOutlineColor(sf::Color::Cyan);
	l3.setSize(sf::Vector2f(8, 170)); l3.setPosition(5, 210);
	l4.setSize(sf::Vector2f(580, 8)); l4.setPosition(5, 380);
	l5.setSize(sf::Vector2f(8, -170)); l5.setPosition(580, 380);
	l6.setSize(sf::Vector2f(8, 170)); l6.setPosition(580, 5);
	l7.setSize(sf::Vector2f(100, 8)); l7.setPosition(45, 45);
	l8.setSize(sf::Vector2f(130, 8)); l8.setPosition(230, 45);
	l9.setSize(sf::Vector2f(95, 8)); l9.setPosition(445, 45);
	l10.setSize(sf::Vector2f(8, 130)); l10.setPosition(540, 45);
	l11.setSize(sf::Vector2f(8, 130)); l11.setPosition(540, 215);
	l12.setSize(sf::Vector2f(-95, 8)); l12.setPosition(540, 340);
	l13.setSize(sf::Vector2f(-130, 8)); l13.setPosition(360, 340);
	l14.setSize(sf::Vector2f(-100, 8)); l14.setPosition(145, 340);
	l15.setSize(sf::Vector2f(8, -130)); l15.setPosition(45, 340);
	l16.setSize(sf::Vector2f(8, -125)); l16.setPosition(45, 175);
	l17.setSize(sf::Vector2f(8, 45)); l17.setPosition(180, 5);
	l18.setSize(sf::Vector2f(8, 45)); l18.setPosition(395, 5);
	l19.setSize(sf::Vector2f(8, 45)); l19.setPosition(395, 335);
	l20.setSize(sf::Vector2f(8, 45)); l20.setPosition(180, 335);
	l21.setSize(sf::Vector2f(45, 10)); l21.setPosition(95, 170);
	l22.setSize(sf::Vector2f(45, 10)); l22.setPosition(95, 210);
	l23.setSize(sf::Vector2f(45, 10)); l23.setPosition(445, 210);
	l24.setSize(sf::Vector2f(45, 10)); l24.setPosition(445, 170);
	l25.setSize(sf::Vector2f(90, 10)); l25.setPosition(190, 170);
	l26.setSize(sf::Vector2f(70, 10)); l26.setPosition(320, 170);
	l27.setSize(sf::Vector2f(10, 45)); l27.setPosition(385, 170);
	l28.setSize(sf::Vector2f(-205, 10)); l28.setPosition(395, 215);
	l29.setSize(sf::Vector2f(10, -45)); l29.setPosition(190, 215);
	l30.setSize(sf::Vector2f(390, 20)); l30.setPosition(100, 100);
	l31.setSize(sf::Vector2f(390, 20)); l31.setPosition(100, 270);

}
void Map::printCircles(int j)
{

	for (int i = 0; i<550; i += 30) { Window.draw(circles[j]);  j++; }
	for (int i = 0; i<550; i += 30) { Window.draw(circles[j]);  j++; }
	for (int i = 0; i<400; i += 30) { Window.draw(circles[j]);  j++; }
	for (int i = 0; i<400; i += 30) { Window.draw(circles[j]);  j++; }
	for (int i = 0; i<400; i += 30) { Window.draw(circles[j]);  j++; }
	for (int i = 0; i<400; i += 30) {Window.draw(circles[j]); j++; }
	for (int i = 0; i<400; i += 30) {Window.draw(circles[j]); j++; }
	for (int i = 0; i<550; i += 30) { Window.draw(circles[j]); j++; }
	for (int i = 0; i<550; i += 30) { Window.draw(circles[j]); j++; }
	for (int i = 0; i<290; i += 30) { Window.draw(circles[j]); j++; }
	for (int i = 0; i<290; i += 60) { Window.draw(circles[j]); j++; }
	j=0;

}
void Map::setCircles(int j)
{

		for (int i = 0; i<550; i += 30)
		 {
			circles[j].setPosition(22 + i, 25);
			j++;
		 }
		for (int i = 0; i<550; i += 30) {
			circles[j].setPosition(22 + i, 360);
				j++;
			}
		for (int i = 0; i<400; i += 30) {
			circles[j].setPosition(85 + i, 130);
				j++;
			}
		for (int i = 0; i<400; i += 30) {
			circles[j].setPosition(100 + i, 315);
			j++;
		}
		for (int i = 0; i<400; i += 30) {
			circles[j].setPosition(100 + i, 75);
			j++;
		}
		for (int i = 0; i<400; i += 30) {
			circles[j].setPosition(100 + i, 250);
			j++;
		}
		for (int i = 0; i<400; i += 30) {
			circles[j].setPosition(100 + i, 315);
			j++;
		}
		for (int i = 0; i<550; i += 30) {
			circles[j].setPosition(22, 50 + i);
			j++;
		}
		for (int i = 0; i<550; i += 30) {
			circles[j].setPosition(558, 50 + i);
			j++;
		}
		for (int i = 0; i<290; i += 30) {
			circles[j].setPosition(75, 60 + i);
			j++;
		}
		for (int i = 0; i<290; i += 60) {
			circles[j].setPosition(510, 60 + i);
			j++;
		}
			j=0;





}