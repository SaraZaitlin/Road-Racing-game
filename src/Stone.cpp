#include "Stone.h"
Stone::Stone(sf::Vector2f location):Static("stone", location)
{
}

Stone ::~Stone()
{
}



inline bool Stone::m_registerit = Factory::registerit("stone",
	[](sf::Vector2f location) -> std::unique_ptr<GameObject> { return std::make_unique<Stone>(location); });