#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Player : public Entity
{
  private:
    // Initializers
    void initShape();

  public:
    // Constructor
    Player();

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
