#pragma once
#include "Static.h"
#include <SFML/Graphics.hpp>
#include"Factory.h"
class Coins:public Static
{
public:
	
	~Coins();
	Coins(sf::Vector2f location);

protected:
	static bool m_registerit;
};


