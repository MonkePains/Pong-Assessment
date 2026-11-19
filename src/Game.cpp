
#include "Game.h"


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
	srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  bool in_menu = true;

  menu_text.setPosition(
    { window.getSize().x / 2 - menu_text.getGlobalBounds().size.x / 2, 50 });

  ball.setPosition({ 400, 400 });
  ball.setScale({ 0.25, 0.25 });
  paddleRed.setPosition({ 475, 25 });
  paddleBlue.setPosition({ 475, 675});
  paddleRed.setScale({ 1.5, 1 });
  paddleBlue.setScale({ 1.5, 1 });
	return true;
}

void Game::update(float dt)
{
  if (
    (ball.getPosition().x >
     (window.getSize().x - ball.getGlobalBounds().size.x)) ||
    (ball.getPosition().x < 0))
  {
    reverseX = !reverseX;
  }

  if (reverseX)
  {
    ball.move({ -1.0f * speed * dt, 0 });
  }
  else
  {
    ball.move({ 1.0f * speed * dt, 0 });
  }
  // up and down reverse
  if (
    (ball.getPosition().y >
     (window.getSize().y - ball.getGlobalBounds().size.y)) ||
    (ball.getPosition().y < 0))
  {
    reverseY = !reverseY;
  }
  
  if (reverseY)
  {
    ball.move({ 0 * speed * dt, -1.0f });
  }
  else
  {
    ball.move({ 0 * speed * dt, 1.0f });
  }
  if (collisionCheck(ball, paddleRed))
  {
   reverseY;
  }
  if (collisionCheck(ball, paddleBlue))
  {
     !reverseY;
  }
}

void Game::render()
{
    if (in_menu)
    {
      window.draw(menu_text);
    }
    else
    {
      window.draw(paddleBlue);
      window.draw(paddleRed);
      window.draw(ball);
    }
}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);

}

void Game::keyPressed(sf::Event::KeyPressed keyPressEvent)
{
  float dt = 0.075f;

  if (keyPressEvent.scancode == sf::Keyboard::Scancode::Left)
  {
      paddleBlue.move({ -1.0f * speed * dt, 0 });
  }
  else if (keyPressEvent.scancode == sf::Keyboard::Scancode::Right)
  {
      paddleBlue.move({ 1.0f * speed * dt, 0 });

  }
  if (keyPressEvent.scancode == sf::Keyboard::Scancode::A)
  {
    paddleRed.move({ -1.0f * speed * dt, 0 });
  }
  else if (keyPressEvent.scancode == sf::Keyboard::Scancode::D)
  {
    paddleRed.move({ 1.0f * speed * dt, 0 });
  }

  else if (keyPressEvent.scancode == sf::Keyboard::Scancode::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }
}

  bool Game::collisionCheck(sf::Sprite sprite, sf::Sprite sprite1)
  {
    if (
      sprite.getPosition().x < sprite1.getPosition().x + sprite1.getGlobalBounds().size.x &&
      sprite.getPosition().y <
        sprite1.getPosition().y + sprite1.getGlobalBounds().size.y)
    {
      if (
        sprite.getPosition().x > sprite1.getPosition().x &&
        sprite.getPosition().y > sprite1.getPosition().y)
      {
        return true;
      }
    }
    return false;
  }

