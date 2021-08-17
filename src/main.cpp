#include "Controller.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TypeSongs.h"
#include"TypeCars.h"
#include "Close.h"
#include "Open.h"
#include<memory>
int main() try
{
  srand(static_cast<unsigned>(time(nullptr)));


  Controller c(std::make_unique<Open>("start", sf::Vector2f(250, 50)), std::make_unique<Close>("exit", sf::Vector2f(250, 400)),
      std::make_unique<TypeCars>("car", Vector2f(50, 400)), std::make_unique<TypeSongs>("song", Vector2f(50, 200)));

    c.run();
}
catch (std::exception& e)
{
    std::cout << "Exception: " << e.what() << '\n';
    return EXIT_FAILURE;
}
catch (...)
{
    std::cout << "Unknown exception\n";
    return EXIT_FAILURE;
}
