#include"Coins.h"



Coins::~Coins()
{
}

Coins::Coins(sf::Vector2f location):Static("coins", location)
{
}

inline bool Coins::m_registerit = Factory::registerit("coins",
	[](sf::Vector2f location) -> std::unique_ptr<GameObject> { return std::make_unique<Coins>(location); });
