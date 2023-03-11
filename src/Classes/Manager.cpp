#include "../Headers/Manager.hpp"

// Functions

template <typename T>
void Manager<T>::add(std::string name, T item)
{
  this->items.insert(std::make_pair(name, item));
}

template <typename T>
T& Manager<T>::get(std::string name)
{
  typename std::map<std::string, T>::iterator iterator = this->items.find(name);
  if (iterator == this->items.end()) {
    throw std::runtime_error("Item \"" + name + "\" does not exist.");
  }
  return iterator->second;
}

template <typename T>
void Manager<T>::a()
{
  return;
}

template class Manager<sf::Texture>;
