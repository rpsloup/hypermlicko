#include "../Headers/Game.hpp"

// Initializers

void Game::initWindow()
{
  // Reading the window config file
  libconfig::Config windowConfig;
  try
  {
    windowConfig.readFile("config/Window.cfg");
  }
  catch (const libconfig::FileIOException &ioException)
  {
    std::cerr << "I/O error when reading the configuration file." << std::endl;
    return;
  }
  catch (const libconfig::ParseException &parseException)
  {
    std::cerr << "Parse error at " << parseException.getFile() << ": " << parseException.getLine()  << " - " << parseException.getError() << std::endl;
    return;
  }

  // Declaring the window properties as variables
  unsigned int windowWidth;
  unsigned int windowHeight;
  std::string windowTitle;
  unsigned int windowFps;
  bool windowVSync;

  // Loading the variables from the config file
  windowConfig.lookupValue("width", windowWidth);
  windowConfig.lookupValue("height", windowHeight);
  windowConfig.lookupValue("title", windowTitle);
  windowConfig.lookupValue("fps", windowFps);
  windowConfig.lookupValue("vsync", windowVSync);

  // Creating and setting up the window
  this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
  this->window->setVerticalSyncEnabled(windowVSync);
  this->window->setFramerateLimit(windowFps);
}

sf::Texture loadTexture(std::string path)
{
  sf::Texture loadedTexture;
  if (!loadedTexture.loadFromFile(path))
  {
    std::cout << "ERROR::GAME::CANT_LOAD_TEXTURE" << std::endl;
  }
  return loadedTexture;
}

sf::Font loadFont(std::string path)
{
  sf::Font loadedFont;
  if (!loadedFont.loadFromFile(path))
  {
    std::cout << "ERROR::GAME::CANT_LOAD_FONT" << std::endl;
  }
  return loadedFont;
}

void Game::initTextures()
{
  this->textureManager.add("player", loadTexture("assets/Textures/player.png"));
}

void Game::initFonts()
{
  this->fontManager.add("terminus", loadFont("assets/Fonts/Terminus.ttf"));
}

void Game::initTexts()
{
  this->positionText.setFont(this->fontManager.get("terminus"));
  this->positionText.setFillColor(sf::Color::White);
  this->positionText.setCharacterSize(BASE_FONT_SIZE);
}

void Game::initPlayer()
{
  this->player.setTexture(&this->textureManager.get("player"));
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initTextures();
  this->initFonts();
  this->initTexts();
  this->initPlayer();
}

Game::~Game()
{
  delete this->window;
}

// Accessors

const float Game::getDt() const
{
  return this->dt;
}

// Update Functions

void Game::updateSFMLEvent()
{
  while (this->window->pollEvent(this->sfEvent))
  {
    switch (this->sfEvent.type)
    {
      case sf::Event::Closed:
        this->window->close();
        break;

      default:
        break;
    }
  }
}

void Game::updateClocks()
{
  this->dt = this->dtClock.restart().asSeconds();
}


void Game::updateKeys()
{
  sf::Vector2f finalMovementVector;

  // WASD Movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
  {
    finalMovementVector.y = -1;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    finalMovementVector.y = 1;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    finalMovementVector.x = -1;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    finalMovementVector.x = 1;
  }

  this->player.move(finalMovementVector);
}

void Game::updateTexts()
{
  sf::Vector2f playerPosition = this->player.getPosition();
  sf::Vector2i roundedPosition = sf::Vector2i(playerPosition);
  this->positionText.setString(
    "Position\n\nX: " + std::to_string(roundedPosition.x) + "\nY: " + std::to_string(roundedPosition.y)
  );
}

void Game::update()
{
  this->updateSFMLEvent();
  this->updateClocks();
  this->updateKeys();
  this->updateTexts();
  this->player.update();
}

// Render Functions

void Game::renderTexts()
{
  this->window->draw(this->positionText);
}

void Game::render()
{
  this->window->clear();
  this->player.render(*this->window);
  this->renderTexts();
  this->window->display();
}

// Functions

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
