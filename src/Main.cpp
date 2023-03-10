#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow mainWindow(sf::VideoMode(400, 400), "SFML");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Red);

  while (mainWindow.isOpen())
  {
    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        mainWindow.close();
    }

    mainWindow.clear();
    mainWindow.draw(shape);
    mainWindow.display();
  }

  return 0;
}
