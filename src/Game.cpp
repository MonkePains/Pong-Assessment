
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
  paddleRed.setPosition({ 400, 100 });
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
    ball.setTextureRect(
      sf::IntRect(
        { (int)ball.getLocalBounds().size.x, 0 },
        { (int)-ball.getLocalBounds().size.x,
          (int)ball.getLocalBounds().size.y }));
  }
  else
  {
    ball.move({ 1.0f * speed * dt, 0 });
    ball.setTextureRect(
      sf::IntRect(
        { 0, 0 },
        { (int)ball.getLocalBounds().size.x,
          (int)ball.getLocalBounds().size.y }));
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
  if (
    (keyPressEvent.scancode == sf::Keyboard::Scancode::Left) ||
    (keyPressEvent.scancode == sf::Keyboard::Scancode::Right))
  {
    play_selected = !play_selected;
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

