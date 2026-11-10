
#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>

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

	sf::RenderWindow& window;

	//Create variables


};

#endif // WHACKAMOLESFML_GAME_H
