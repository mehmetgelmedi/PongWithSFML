#include <SFML\Graphics.hpp>

using namespace sf;

class Top
{
public:
	Top(float basX, float basY);
	FloatRect getPos();
	RectangleShape getShape();
	
	float getXSpeed();
	float getYSpeed();

	//geri tepme, sekme
	void sekmeY();
	void sekmeX();
	void update();
	void update(int x, int y);


private:
	float xSpeed = .1f;
	float ySpeed = .1f;

	Vector2f position;
	
	RectangleShape topShape;

};