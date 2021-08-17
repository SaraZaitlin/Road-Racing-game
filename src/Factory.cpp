#include"Factory.h"



std::unique_ptr<GameObject> Factory::create(const std::string& name, sf::Vector2f location)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(location);
}





bool Factory::registerit(const std::string& name, std::unique_ptr<GameObject>(*f)(sf::Vector2f location))
{
	getMap().emplace(name, f);
	return true;
}
