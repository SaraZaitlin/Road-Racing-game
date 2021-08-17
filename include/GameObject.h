#pragma once

#include <SFML/Graphics.hpp>
#include<string>
class Car;
class GameObject
{
public:
	GameObject() = default;
	GameObject(const std::string& str, sf::Vector2f location);
	virtual ~GameObject();
	virtual void draw(sf::RenderWindow&, float, sf::Vector3f, float, double);
	virtual bool collides(const std::unique_ptr<Car>& player)const;
	
protected:
	sf::Sprite m_spritObject;
};
