#include "top.h"

using namespace sf;

Top::Top(float basX, float basY){
	position.x = basX;
	position.y = basY;

	topShape.setSize(Vector2f(10, 10));
	topShape.setPosition(position);
}

FloatRect Top::getPos(){
	return topShape.getGlobalBounds();
}

RectangleShape Top::getShape()
{
	return topShape;
}

float Top::getXSpeed()
{
	return xSpeed;
}
float Top::getYSpeed()
{
	return ySpeed;
}

void Top::sekmeY()
{
	ySpeed = -ySpeed;
}
void Top::sekmeX()
{
	xSpeed = -xSpeed;
}

void Top::update(){
	position.x += xSpeed;
	position.y += ySpeed;

	topShape.setPosition(position);
}
void Top::update(int x, int y)
{
	position.x += x;
	position.y += y;
	topShape.setPosition(position);
}