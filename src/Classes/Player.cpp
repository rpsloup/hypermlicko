#include "../Constants.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/Game.hpp"

extern Game game;

// Initializers

void Player::initShape()
{
  this->shape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
  this->shape.setPosition(sf::Vector2f(0.f, 0.f));
}

// Constructor

Player::Player()
{
  this->initShape();
  this->speed = PLAYER_SPEED;
}

// Accessors

sf::Vector2f Player::getPosition()
{
  return this->shape.getPosition();
}

// Modifiers

void Player::setSpeed(const float newSpeed)
{
  this->speed = newSpeed;
}

// Functions

void Player::update()
{
  sf::Vector2f normalisedVector = this->movement;

  // Normalising vector to prevent moving faster than the maximum speed
  if (std::abs(this->movement.x) == 1 && std::abs(this->movement.y))
  {
    normalisedVector /= sqrtf(pow(this->movement.x, 2) + pow(this->movement.y, 2));
  }

  this->shape.move(normalisedVector * this->speed * game.getDt());  
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}

void Player::move(sf::Vector2f movement)
{
  this->movement = movement;
}
