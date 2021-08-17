#pragma once
#include "Static.h"
#include <SFML/Graphics.hpp>
#include"Factory.h"
class Fox :public Static
{
public:
	Fox(sf::Vector2f location);
	~Fox();
protected:
	static bool m_registerit;

};