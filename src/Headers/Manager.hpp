#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "../Headers.hpp"

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

#endif // MANAGER_HPP
