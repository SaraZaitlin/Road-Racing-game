#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Observer.h"
#include "Car.h"
class InformationDisplay:public Observer
{
public:
	InformationDisplay(std::unique_ptr<Car>& pCar);
	~InformationDisplay();
	void UpdatingInformationView( sf::RenderWindow& m_window , int& level);
	virtual void Update(int& coins,float& totalFule);
protected:
	float m_totalFule =50;
	int m_total_coins = 0;

	sf::Sprite m_sprite;
	sf::Text m_printLevel;
	sf::Text m_printFuel;
	sf::Text m_printCoin;

	std::vector<sf::Sprite> m_infu;
	sf::Texture m_Level;
	sf::Texture m_coins;
	sf::Texture m_fuel;
	


};


