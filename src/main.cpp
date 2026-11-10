#include "Game.h"


int main()
{
    std::cout << "You should see a window that opens as well as this writing to console..."
        << std::endl;

    // create window and set up
    sf::RenderWindow window(sf::VideoMode({1080, 720}), "Pong!");
    window.setFramerateLimit(60);



    //initialise an instance of the game class
    Game game(window);

    //run the init function of the game class and check it all initialises ok
    if (!game.init())
    {
         return 0;
    }

    // A Clock starts counting as soon as it's created
    sf::Clock clock;

    // Game loop: run the program as long as the window is open
    while (window.isOpen())
    {
        //calculate delta time
        sf::Time time = clock.restart();
        float dt = time.asSeconds();

        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            //add further events here


        }

        //'update' element of the game loop
        game.update(dt);

        window.clear(sf::Color::Black);

        //'render' element of the game loop
        game.render();

        window.display();
    }

    return 0;
}
