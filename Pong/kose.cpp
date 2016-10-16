#include "kose.h"

using namespace sf;

Kose::Kose(int basX, int basY,float sizeX, float sizeY)
{
	position.x = basX;
	position.y = basY;

	koseShape.setSize(Vector2f(sizeX, sizeY));
	koseShape.setPosition(position);
	koseShape.setFillColor(Color::White);
}

RectangleShape Kose::getShape()
{
	return koseShape;
}

FloatRect Kose::getPos()
{
	return koseShape.getGlobalBounds();
}