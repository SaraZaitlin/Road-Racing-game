#include "Fox.h"
Fox::Fox(sf::Vector2f location) :Static("fox", location)
{
}

Fox ::~Fox()
{
}


inline bool Fox::m_registerit = Factory::registerit("fox",
	[](sf::Vector2f location) -> std::unique_ptr<GameObject> { return std::make_unique<Fox>(location); });