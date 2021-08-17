#pragma once
#include <memory>
#include <map>
#include<string>
#include "GameObject.h"
#include <SFML/Graphics.hpp>

typedef std::map<std::string, std::unique_ptr<GameObject>(*)(sf::Vector2f)> mymap;


class Factory
{
public:
	static std::unique_ptr<GameObject> create(const std::string& name, sf::Vector2f location);

	static bool registerit(const std::string& name, std::unique_ptr<GameObject>(*f)(sf::Vector2f location));
	
private:
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
	
};

