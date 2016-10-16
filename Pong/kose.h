#include <SFML\Graphics.hpp>

using namespace sf;

class Kose{
private:
	Vector2f position;
	RectangleShape koseShape;

public:
	Kose(int basX, int basY, float sizeX, float sizeY);
	FloatRect getPos();
	RectangleShape getShape();
};