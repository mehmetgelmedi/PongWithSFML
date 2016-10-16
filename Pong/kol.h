#include <SFML\Graphics.hpp>

using namespace sf;

class Kol{
private:
	Vector2f position;
	
	RectangleShape kolShape;

	float kolSpeed = .3f;

public:
	Kol(float basX, float basY);
	FloatRect getPos();
	RectangleShape getShape();
	void moveUp();
	void moveDown();
	void update();
};