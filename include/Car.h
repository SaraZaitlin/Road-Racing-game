#pragma once
#include"Dynamic.h"
#include <SFML/Graphics.hpp>
#include<memory>
#include<vector>
#include "Resources.h"
#include "Const.h"
#include "Observer.h"
//#include "Subject.h"
using namespace sf;
class Car:public Dynamic//, Subject
{
public:
	Car(sf::Vector2f location, int chose);
	Car() = default;
	virtual ~Car();

	void UpdateObject(sf::Vector2f location, int chose);

 void draw(sf::RenderWindow& window)const;
	void moveCar(int speed, sf::Time deltaTime);
	sf::Vector2f getPosition();
	virtual void RegisterObserver(Observer* pObserver);
	virtual void RemoveObserver(Observer* pObserver) ;
	virtual void NotifyObservers() ;
	 FloatRect getGlobalBounds();
	void additionACoin();
	void decreaseCoin();
	void additionFuel(int fuel);
	void decreaseFuel(sf::Time deltaTime= sf::seconds(10.1f));
protected:
	std::vector<Observer*> vec_pObserver_;
	float m_totalFule;
	int m_total_coins;
	
};
