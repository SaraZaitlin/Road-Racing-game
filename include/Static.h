#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Car.h"
#include<string>
class Static:public GameObject
{
public:
	Static(const std::string& string, sf::Vector2f location);
	void draw(sf::RenderWindow&, float, sf::Vector3f, float, double);
	void setColor();
protected:


};
