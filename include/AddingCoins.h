#pragma once
#include "Gift.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
class AddingCoins:public Gift
{
public:
	AddingCoins(sf::Vector2f location);
	~AddingCoins();

protected:
	static bool m_registerit;
};


