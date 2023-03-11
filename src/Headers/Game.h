#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <libconfig.h++>
#include <SFML/Graphics.hpp>

#include "Player.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    Player player;

    // Initializers
    void initWindow();
    void initPlayer();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Update Functions
    void updateSFMLEvent();
    void update();

    // Render Functions
    void render();

    // Functions
    void run();
};

#endif // GAME_H
