#pragma once
#include "Command.h"
#include <SFML/Graphics.hpp>


class TypeCars : public Command
{
public:
	TypeCars(std::string string, sf::Vector2f loction);
	~TypeCars();
	


protected:
};

