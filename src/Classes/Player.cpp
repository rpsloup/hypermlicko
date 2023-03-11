#include "../Headers/Player.hpp"

// Initializers

void Player::initShape()
{
  this->shape.setSize(sf::Vector2f(32.f, 32.f));
  this->shape.setPosition(sf::Vector2f(0.f, 0.f));
}

// Constructor

Player::Player()
{
  this->initShape();
}

// Functions

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
