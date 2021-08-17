#pragma once
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
class AddingFuel:public Gift
{
public:
	AddingFuel(sf::Vector2f location);
	~AddingFuel();

protected:
	static bool m_registerit;
};


