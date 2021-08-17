#include "Car.h"
#include <iostream>
Car::Car(sf::Vector2f location, int chose) :m_totalFule(200), m_total_coins(0)
{
    UpdateObject( location, chose);
}

Car::~Car()
{
}
//פונקציה האחראית לעדכן את התמונה של השחקן
void Car::UpdateObject( sf::Vector2f location, int chose)
{
    auto it = Resources::instance().m_image.find("car");
    if (it == Resources::instance().m_image.end())
        throw std::out_of_range("GameObjectIndex item not found.");

    m_spritObject.setPosition(location);
    m_spritObject.setTexture(it->second[chose]);
 
}
//פונקציה האחראית להדפיס את הרכב
void Car::draw(sf::RenderWindow& window)const
{
    window.draw(m_spritObject);
}
//פונקציה האחראית על התזוזה של הרכב
void Car::moveCar(int speed, sf::Time deltaTime)
{


   m_spritObject.setPosition(m_spritObject.getPosition().x + speed * deltaTime.asSeconds() * 10, m_spritObject.getPosition().y);
    if (m_spritObject.getPosition().x < xMin)
       m_spritObject.setPosition(sf::Vector2f(xMin,m_spritObject.getPosition().y));
    if (m_spritObject.getPosition().x > xMax)
        m_spritObject.setPosition(sf::Vector2f(xMax, m_spritObject.getPosition().y));
    return;

}
//פונקציה המחזירה את המיקום
sf::Vector2f Car::getPosition()
{
    return m_spritObject.getPosition();

}

//פונקציה המוסיפה את מי שרוצה להרשם
void Car::RegisterObserver(Observer* pObserver)
{
    vec_pObserver_.push_back((pObserver));

}
//פונקציה המסירה 
void Car::RemoveObserver(Observer* pObserver)
{
    vec_pObserver_.erase(remove(vec_pObserver_.begin(), vec_pObserver_.end(), pObserver), vec_pObserver_.end());
}
//פונקציה האחראית לעדכן את כל מי שנירשם (תצוגת מידה ושלב.. 
void Car::NotifyObservers()
{
    for (auto iter = vec_pObserver_.begin(); iter != vec_pObserver_.end(); ++(iter))
    {
        (*iter)->Update(m_total_coins,m_totalFule);
    }

}
//פונקציה המביאה את הגבולות של רכב השחקן
FloatRect Car::getGlobalBounds()
{
    return m_spritObject.getGlobalBounds();
}


//----------------------------------
//פונקציה המוסיפה מטבעות
void Car::additionACoin()
{
    //std::cout << "coin " << m_total_coins << "\n";
    m_total_coins= m_total_coins+5;
    NotifyObservers();
}
//--------------------------
//פונקציה המורידה מטבעות
void Car::decreaseCoin()
{
    //std::cout << "coin " << m_total_coins << "\n";
    m_total_coins= m_total_coins-10;
    if (m_total_coins < 0)
        m_total_coins = 0;
    NotifyObservers();
}
//---------------------------
//פונקציה האחראית על הוספת דלק
void Car::additionFuel(int fuel)
{
    m_totalFule=m_totalFule+ fuel;
    NotifyObservers();
}
//פונקציה המורידה דלק
void Car::decreaseFuel(sf::Time deltaTime)
{
     m_totalFule = m_totalFule - deltaTime.asSeconds();
        NotifyObservers();

}

