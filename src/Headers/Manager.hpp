#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <string>
#include <stdexcept>
#include <SFML/Graphics.hpp>

template <typename T>
class Manager
{
  private:
    std::map<std::string, T> items;

  public:
    // Functions
    void add(std::string name, T item);
    T& get(std::string name);
    void a();
};

#endif // MANAGER_H
