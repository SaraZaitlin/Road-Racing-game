#include "CollisionHandling.h"
#include "Resources.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "AddingFuel.h"
#include "Coins.h"
#include "Stone.h"
#include "Car.h"
#include"CarEnemy.h"
#include "Fox.h"


namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    bool carStone(GameObject& car,
        GameObject& stone)
    {
        Car& c = static_cast<Car&>(car);
        Stone& ston = static_cast<Stone&>(stone);
        c.decreaseCoin();
        Resources::instance(). playSound("bam", 100);
       return true;
  
    }
    bool carEemeyCar(GameObject& car,
        GameObject& carEnemy)
    {
        Car& c = static_cast<Car&>(car);
        CarEnemy& carEne = static_cast<CarEnemy&>(carEnemy);
        c.decreaseFuel();
        Resources::instance().playSound("bam", 100);

        return true;

    }
    bool carFox(GameObject& car,
        GameObject& fox)
    {

        std::cout << "car and stone collision!" << std::endl;
        Car& c = static_cast<Car&>(car);
        Fox& fo = static_cast<Fox&>(fox);
        c.decreaseCoin();
        c.decreaseFuel();
        Resources::instance().playSound("bam", 100);

        return true;

    }

    bool carCoins(GameObject& car,
        GameObject& coins)
    {
       Car& c = static_cast<Car&>(car);
         Coins&  coin  = static_cast<Coins&>(coins);
         c.additionACoin();
        coin.setColor();
        Resources::instance().playSound("coins", 15);
     
        return false;
    }

    bool carFuel(GameObject& car,
        GameObject& fuel)
    {

        Car& c = static_cast<Car&>(car);
        Coins& fu = static_cast<Coins&>(fuel);
        c.additionFuel(50);
        fu.setColor();
        return false;

    }
  

 

  

    using HitFunctionPtr = bool (*)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Car), typeid(Stone))] = &carStone;
        phm[Key(typeid(Car), typeid(Coins))] = &carCoins;
        phm[Key(typeid(Car), typeid(AddingFuel))] = &carFuel;
        phm[Key(typeid(Car), typeid(CarEnemy))] = &carEemeyCar;
        phm[Key(typeid(Car), typeid(Fox))] = &carFox;


       
        //phm[Key(typeid(SpaceStation), typeid(Asteroid))] = &stationAsteroid;
        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

bool processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
  return  phf(object1, object2);
}
