#ifndef GAME_HPP
#define GAME_HPP

#include "../Headers.hpp"
#include "../Constants.hpp"
#include "Player.hpp"
#include "Manager.hpp"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    Player player;

    // Texts
    sf::Text positionText;

    // Managers
    Manager<sf::Texture> textureManager;
    Manager<sf::Font> fontManager;

    // Clocks
    sf::Clock dtClock;
    float dt;

    // Initializers
    void initWindow();
    void initTextures();
    void initFonts();
    void initTexts();
    void initPlayer();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Accessors
    const float getDt() const;

    // Update Functions
    void updateSFMLEvent();
    void updateClocks();
    void updateKeys();
    void updateTexts();
    void update();

    // Render Functions
    void renderTexts();
    void render();

    // Functions
    void run();
};

#endif // GAME_HPP
