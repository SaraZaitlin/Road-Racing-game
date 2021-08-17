#pragma once
#include "BackgroundGame.h"
#include"InformationDisplay.h"
#include <SFML/Graphics.hpp>
#include<memory>
#include <ctime>
#include <thread>
class car;
#include "Observer.h"
class Level:public Observer
{
public:
	Level(std::unique_ptr<Car>& pCar);
	 ~Level();
	void runLevel(sf::RenderWindow& window, std::string song);
	void endelEvent(sf::RenderWindow& window, sf::Time deltaTime);
	virtual void Update(int& coins, float& totalFule);
	bool checkEndLevel(BackgroundGame& BackgroundGame, sf::RenderWindow& window);
	void howEndGame(sf::RenderWindow& window);
	void SetUpTextur(int index, sf::RenderWindow& window);
	void displayHowCoins(sf::RenderWindow& window, int coin);
	sf::Sprite setTextur(std::string name, int index);
protected:
	
	std::unique_ptr<Car>& m_car;
	GameObject m_gameObject;
	int m_level=1;
	float m_totalFule = 200;
	int m_total_coins = 0;
};

