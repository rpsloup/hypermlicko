#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <libconfig.h++>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Manager.hpp"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    Player player;

    // Managers
    Manager<sf::Texture> textureManager;

    // Initializers
    void initWindow();
    void initTextures();
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
