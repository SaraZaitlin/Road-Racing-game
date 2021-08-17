#pragma once
#include <SFML/Graphics.hpp>

#include "Command.h"
class TypeSongs :public Command
{
public:
	TypeSongs(std::string string, sf::Vector2f loction);
	~TypeSongs();

protected:

};

