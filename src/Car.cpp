#include "Car.h"
#include <iostream>
Car::Car(sf::Vector2f location, int chose) :m_totalFule(200), m_total_coins(0)
{
    UpdateObject( location, chose);
}

Car::~Car()
{
}
//ôåð÷öéä äàçøàéú ìòãëï àú äúîåðä ùì äùç÷ï
void Car::UpdateObject( sf::Vector2f location, int chose)
{
    auto it = Resources::instance().m_image.find("car");
    if (it == Resources::instance().m_image.end())
        throw std::out_of_range("GameObjectIndex item not found.");

    m_spritObject.setPosition(location);
    m_spritObject.setTexture(it->second[chose]);
 
}
//Another function is to print the player on the board
void Car::draw(sf::RenderWindow& window)const
{
    window.draw(m_spritObject);
}
//Function responsible for moving the player (car)
void Car::moveCar(int speed, sf::Time deltaTime)
{


   m_spritObject.setPosition(m_spritObject.getPosition().x + speed * deltaTime.asSeconds() * 10, m_spritObject.getPosition().y);
    if (m_spritObject.getPosition().x < xMin)
       m_spritObject.setPosition(sf::Vector2f(xMin,m_spritObject.getPosition().y));
    if (m_spritObject.getPosition().x > xMax)
        m_spritObject.setPosition(sf::Vector2f(xMax, m_spritObject.getPosition().y));
    return;

}
//Function responsible for giving the current position of the object
sf::Vector2f Car::getPosition()
{
    return m_spritObject.getPosition();

}

//ôåð÷öéä äîåñéôä àú îé ùøåöä ìäøùí
void Car::RegisterObserver(Observer* pObserver)
{
    vec_pObserver_.push_back((pObserver));

}
//ôåð÷öéä äîñéøä 
void Car::RemoveObserver(Observer* pObserver)
{
    vec_pObserver_.erase(remove(vec_pObserver_.begin(), vec_pObserver_.end(), pObserver), vec_pObserver_.end());
}
//Update information display when there is a change (when the player meets the objects in the game).
void Car::NotifyObservers()
{
    for (auto iter = vec_pObserver_.begin(); iter != vec_pObserver_.end(); ++(iter))
    {
        (*iter)->Update(m_total_coins,m_totalFule);
    }

}
//ôåð÷öéä äîáéàä àú äâáåìåú ùì øëá äùç÷ï
FloatRect Car::getGlobalBounds()
{
    return m_spritObject.getGlobalBounds();
}


//----------------------------------
//Function responsible during the player's encounter with coins for adding 5 points to the player.
void Car::additionACoin()
{
    //std::cout << "coin " << m_total_coins << "\n";
    m_total_coins= m_total_coins+5;
    NotifyObservers();
}
//--------------------------
//A function responsible for reducing the player's score when collision an opponent.
void Car::decreaseCoin()
{
    //std::cout << "coin " << m_total_coins << "\n";
    m_total_coins= m_total_coins-10;
    if (m_total_coins < 0)
        m_total_coins = 0;
    NotifyObservers();
}
//---------------------------
//The function is responsible for adding fuel to the player when a collision with a gift.
void Car::additionFuel(int fuel)
{
    m_totalFule=m_totalFule+ fuel;
    NotifyObservers();
}
//The function is responsible for reducing fuel per player in the event of an enemy collision.
void Car::decreaseFuel(sf::Time deltaTime)
{
     m_totalFule = m_totalFule - deltaTime.asSeconds();
        NotifyObservers();

}

