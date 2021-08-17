#include "AddingCoins.h"



AddingCoins::AddingCoins(sf::Vector2f location):Gift("addingCoins",location)
{
}

AddingCoins::~AddingCoins()
{
}

inline bool AddingCoins::m_registerit = Factory::registerit("addingCoins",
	[](sf::Vector2f location) -> std::unique_ptr<GameObject> { return std::make_unique<AddingCoins>(location); });