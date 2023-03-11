#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

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

#endif // ENTITY_H
