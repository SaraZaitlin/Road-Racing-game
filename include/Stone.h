#pragma once
#include "Static.h"
#include <SFML/Graphics.hpp>
#include"Factory.h"
class Stone :public Static
{
public:
	Stone (sf::Vector2f location);
	~Stone ();
	
protected:
	static bool m_registerit;

};