
#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"

class Game
{
  public:
	Game(sf::RenderWindow& window);
	~Game();
	bool init();
	void update(float dt);
	void render();
	void mouseClicked(sf::Event event);
	void keyPressed(sf::Event::KeyPressed keypressevent);

  private:
    bool collisionCheck(sf::Sprite sprite, sf::Sprite sprite1);
	sf::RenderWindow& window;

	sf::Texture paddleBlue_texture{ "../Data/Images/paddleBlue.png" };
	sf::Sprite paddleBlue{ paddleBlue_texture };
    sf::Texture paddleRed_texture{ "../Data/Images/paddleRed.png" };
    sf::Sprite paddleRed{ paddleRed_texture };
    sf::Texture ball_texture{ "../Data/Images/ball.png" };
    sf::Sprite ball{ ball_texture };
    sf::Font font{ "../Data/Fonts/OpenSans-Bold.ttf" };

	bool in_menu;
    sf::Text menu_text{ font, "Press Enter to Play ", 50 };

	bool play_selected = true;

	bool reverseX = false;
    bool reverseY = false;

	float speed = 400;
 
};

#endif // WHACKAMOLESFML_GAME_H
