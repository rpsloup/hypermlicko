#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <libconfig.h++>
#include <SFML/Graphics.hpp>

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    // Initializers
    void initWindow();

  public:
    Game();

    // Update Functions
    void updateSFMLEvent();
    void update();

    // Render Functions
    void render();

    // Functions
    void run();
};

#endif // GAME_H
