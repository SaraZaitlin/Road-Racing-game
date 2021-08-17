#include "AddingFuel.h"

AddingFuel::AddingFuel(sf::Vector2f location) :Gift("addingFuel", location)
{
}

AddingFuel::~AddingFuel()
{
}

inline bool AddingFuel::m_registerit = Factory::registerit("addingFuel",
	[](sf::Vector2f location) -> std::unique_ptr<GameObject> { return std::make_unique<AddingFuel>(location); });