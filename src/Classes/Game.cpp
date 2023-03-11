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

void Game::initTextures()
{
  this->textureManager.add("player", loadTexture("assets/Textures/player.png"));
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
  this->initPlayer();
}

Game::~Game()
{
  delete this->window;
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

void Game::update()
{
  this->updateSFMLEvent();
}

// Render Functions

void Game::render()
{
  this->window->clear();
  this->player.render(*this->window);
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
