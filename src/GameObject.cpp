#include "GameObject.h"
#include"Car.h"
#include<iostream>


GameObject::GameObject(const std::string& string, sf::Vector2f location)
{
	auto it = Resources::instance().m_image.find(string);
	if (it == Resources::instance().m_image.end())
		throw std::out_of_range("GameObjectIndex item not found.");

	m_spritObject.setTexture(it->second[0]);
}

GameObject::~GameObject()
{

}


void GameObject::draw(sf::RenderWindow& window, float m_clip, sf::Vector3f m_center, float m_scale, double m_collectX)
{
}

//פונקציה הבודקת אם היתה התנגשות 
bool GameObject::collides(const std::unique_ptr<Car>& car)const
{
		return m_spritObject.getGlobalBounds().intersects(car->getGlobalBounds());
}


