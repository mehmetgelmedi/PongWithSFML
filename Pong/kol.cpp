#include "kol.h"

using namespace sf;

Kol::Kol(float basX, float basY){
	position.x = basX;
	position.y = basY;

	kolShape.setSize(sf::Vector2f(50, 5));
	kolShape.setRotation(90);
	kolShape.setPosition(basX, basY);
}
FloatRect Kol::getPos()
{
	return kolShape.getGlobalBounds();
}

RectangleShape Kol::getShape()
{
	return kolShape;
}

void Kol::moveDown()
{
	position.y += kolSpeed;
}

void Kol::moveUp()
{
	position.y -= kolSpeed;
}

void Kol::update()
{
	kolShape.setPosition(position);
}