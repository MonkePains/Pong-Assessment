
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



  ball.setPosition({ 540, 360 });
  ball.setScale({ 0.25, 0.25 });

  paddleRed.setPosition({ 475, 25 });
  paddleBlue.setPosition({ 475, 675});
  paddleRed.setScale({ 1.5, 1 });
  paddleBlue.setScale({ 1.5, 1 });

  player1Score.setFillColor(sf::Color::Red);
  player1Score.setPosition({ 237.5, 350 });

  player2Score.setFillColor(sf::Color::Blue);
  player2Score.setPosition({712.5, 350});


	return true;
}

void Game::update(float dt)
{
  player1Score.setString("0" + std::to_string(player_1_score));

  player2Score.setString("0" + std::to_string(player_2_score));

  deltaTime = dt;
  if (in_menu == false)
  {
      if (
        (ball.getPosition().x >
         (window.getSize().x - ball.getGlobalBounds().size.x)) || (ball.getPosition().x < 0))
      {
        reverseX = !reverseX;
      }

      if (reverseX)
      {
        ball.move({ -ballSpeed * dt, 0 });
      }
      else
      {
        ball.move({ ballSpeed * dt, 0 });
      }
      // up and down reverse
      if (
        (ball.getPosition().y >
         window.getSize().y - ball.getGlobalBounds().size.y))
      {
        //reverseY = !reverseY;
        player_1_score++;
        spawn();
        return;
      }
      else if (ball.getPosition().y < 0) // needs to rejoin above if statement
      {
        player_2_score++;
        spawn();
        return;
      }
 
      if (collisionCheck(ball, paddleRed))
      {
       reverseY = !reverseY;
        std::cout << "Collided";
   
      }
      if (collisionCheck(ball, paddleBlue))
      {
         reverseY = !reverseY;
        std::cout << "Collided";
      }
 
       std::cout << reverseY;
      if (reverseY)
      {
        ball.move({ 0, -ballSpeed*dt });
      }
      else
      {
        ball.move({ 0, ballSpeed * dt });
      }
  }
  else
  {
   
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
      window.draw(player1Score);
      window.draw(player2Score);
    }
}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2i click = sf::Mouse::getPosition(window);

}

void Game::keyPressed(sf::Event::KeyPressed keyPressEvent)
{
  if (keyPressEvent.scancode == sf::Keyboard::Scancode::Left)
  {
      paddleBlue.move({ -1.0f * speed * deltaTime, 0 });
  }
  else if (keyPressEvent.scancode == sf::Keyboard::Scancode::Right)
  {
    paddleBlue.move({ 1.0f * speed * deltaTime, 0 });

  }
  if (keyPressEvent.scancode == sf::Keyboard::Scancode::A)
  {
    paddleRed.move({ -1.0f * speed * deltaTime, 0 });
  }
  else if (keyPressEvent.scancode == sf::Keyboard::Scancode::D)
  {
    paddleRed.move({ 1.0f * speed * deltaTime, 0 });
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
        sprite1.getPosition().y + sprite1.getGlobalBounds().size.y &&
      sprite.getPosition().x + sprite.getGlobalBounds().size.x >
        sprite1.getPosition().x &&
      sprite.getPosition().y + sprite.getGlobalBounds().size.y >
        sprite1.getPosition().y)
      {
        return true;
      }
     

    return false;
  }
 
   void Game::spawn()
  {
    ball.setPosition({ 540, 360 });
    return;
  }