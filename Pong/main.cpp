#include <SFML\Graphics.hpp>
#include <sstream> //stringstream
#include "kose.h";
#include "kol.h"
#include "top.h"

const int WIDTH = 640, HEIGHT = 480;
const char* TITLE = "Pong";
const int kalinlik = 5;

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE); //Style::Fullscreen
	
	Kol oyuncu1(50, HEIGHT / 2);
	Kol oyuncu2(WIDTH - 50, HEIGHT / 2);

	Top top(WIDTH / 2, HEIGHT / 2);

	Kose yukari(kalinlik, 0, WIDTH*kalinlik, kalinlik);
	Kose asagi(kalinlik, HEIGHT - kalinlik, WIDTH*kalinlik, kalinlik);
	Kose sol(0, 0, kalinlik, HEIGHT);
	Kose sag(WIDTH - kalinlik, 0, kalinlik, HEIGHT);

	Text skor;
	Font font;

	int p1 = 0, p2 = 0;

	if (!font.loadFromFile("Score Board St.ttf"))
		return EXIT_FAILURE;
	skor.setCharacterSize(45);
	skor.setFont(font);
	skor.setFillColor(Color::White);
	skor.setOutlineThickness(1);
	skor.setOutlineColor(Color::Blue);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//oyuncu yonetimi
		if (Keyboard::isKeyPressed(Keyboard::Key::W)){
			oyuncu1.moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S)){
			oyuncu1.moveDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up)){
			oyuncu2.moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down)){
			oyuncu2.moveDown();
		}
		//Top yukari ile kesiþtiðinde
		if (top.getPos().intersects(yukari.getPos()))
		{
			top.sekmeY();
			int x = yukari.getPos().top+ yukari.getPos().height - top.getPos().top;
			top.update(0, x * 2);
		}
		//Top asagi ile kesiþtiðinde
		if (top.getPos().intersects(asagi.getPos()))
		{
			top.sekmeY();
			int x = asagi.getPos().top - top.getPos().height - top.getPos().top;
			top.update(0, x * 2);
		}
		//Top sol ile kesiþtiðinde 
		if (top.getPos().intersects(sol.getPos()))
		{
			top.update(oyuncu1.getPos().left - oyuncu1.getPos().width - 5, HEIGHT / 2);
			p2++;
		}
		//Top sag ile kesiþtiðinde
		if (top.getPos().intersects(sag.getPos()))
		{
			top.update(oyuncu1.getPos().left + oyuncu1.getPos().width + 5, HEIGHT / 2);
			p1++;
		}
		//Top oyuncu1  veya oyuncu2 ile kesiþtiðinde...




	/*	if (top.getPos().intersects(oyuncu1.getPos()))
		{
			top.sekmeX();
			int x = oyuncu1.getPos().left + oyuncu1.getPos().width - top.getPos().left;
			int left = oyuncu1.getPos().left + oyuncu1.getPos().width + x;
			top.update(left, top.getPos().top);
		}*/
		//top ve kollarý güncelle
		top.update();
		oyuncu1.update();
		oyuncu2.update();

		//skor alaný
		stringstream ss;
		ss << " P1 : " << p1 << "		 P2 : " << p2;
		skor.setString(ss.str());

		window.clear();
		//çizdir
		window.draw(yukari.getShape());
		window.draw(asagi.getShape());
		window.draw(sol.getShape());
		window.draw(sag.getShape());
		window.draw(oyuncu1.getShape());
		window.draw(oyuncu2.getShape());
		window.draw(top.getShape());
		window.draw(skor);
		
		window.display();
	}

	return EXIT_SUCCESS;
}