#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Headers.hpp"

class Entity
{
  protected:
    sf::Texture* texture;
    sf::RectangleShape shape;

  public:
    // Mutators
    void setTexture(sf::Texture* texture);
    void setPosition(sf::Vector2f position);

    // Accessors
    const sf::FloatRect getBounds() const;

    // Functions
    virtual void update() = 0;
    virtual void render(sf::RenderTarget &target) = 0;
};

#endif // ENTITY_HPP
