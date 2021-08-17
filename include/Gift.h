#pragma once
#include"Static.h"
#include <SFML/Graphics.hpp>
#include <string>
class Gift: public Static
{
public:
	Gift(const std::string& string, sf::Vector2f location);
	~Gift();

protected:

};
