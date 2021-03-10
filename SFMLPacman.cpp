
#include "src/Game.h"
//#include "src/scenes/MainScene.h" +
//#include "src/sceneManager/SceneManager.h"
//#include "src/Context.h"
#include <iostream>


int main()
{
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/
    Game game;
    std::cout << "1\n";
    game.Run();

    //Context cn;

    //Engine::MainScene m_s;
    /*std::cout << "1\n";
    Engine::SceneManager sm;
    std::cout << "2\n";*/
    //sm.

    return 0;
}

