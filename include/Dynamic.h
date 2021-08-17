#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include<string>
class Dynamic:public GameObject
{
public:

	Dynamic(const std::string& string, sf::Vector2f location);

	Dynamic() = default;
	~Dynamic();
protected:

};
