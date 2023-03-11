#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Headers.hpp"
#include "../Constants.hpp"
#include "Entity.hpp"

class Player : public Entity
{
  private:
    float speed;
    sf::Vector2f movement;

    // Initializers
    void initShape();

  public:
    // Constructor
    Player();

    // Accessors
    sf::Vector2f getPosition();

    // Modifiers
    void setSpeed(const float newSpeed);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
    void move(sf::Vector2f movement);
};

#endif // PLAYER_HPP
