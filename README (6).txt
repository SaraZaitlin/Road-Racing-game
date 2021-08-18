Submission of a second semester project in the second year of an object-oriented programming course and game development:
Serves:
Sarah Zeitlin: 209181874
Shira Alfasi: 208175737


About the program:
A desktop app of the Road Running game,  developed in C++ by using the principles of OOP. GUI development using the SFML library. The game has several levels with difficulties that increased.
In the game we have a car that travels only in one direction, and all the time enemies, gifts, etc. come in front of it, the car can move left and right inside the lane.
In her mishaps with a stone-type enemy - she drops coins.
In her mishaps with a car-type enemy, she loses fuel.
In her mishap with a fox she drops fuel and coins and is in stage 2.
The car moves on to the next stage only after collecting all the coins, and without running out of fuel ....
Some of the enemies are moving towards the player ...

The departments of the year:
AddingCoins: This class is responsible for adding coins to the player, and inherits from the Gift class.
AddingFuel: This class is responsible for adding fuel to the player, and inherits from the Gift class.
BackgroundGame: This department is responsible for all board building.
Car: This department handles all matters related to the car and heir, from the Dynamic department.
CarEnemy: This department handles cars coming in front of our player.
Close: This class is responsible for the EXIT login button, and inherits from the Command class.
Coins: This class is responsible for the coins that go to the board, and inherits from the Static class.
UnknownCollision: This is a class that handles conflict, and inherits from the runtime_error class.
Command: This is a base class, from which all the buttons are inherited.
CONST this class and converted us all constants and also ENUM which we use for the buttons ...
Controller: This department manages the entire game, and from it all the departments that run the game are called.
Dynamic: A class that handles all dynamic objects, inherits from the GameObject class.
Factory: This department is responsible for the production of temporary objects with which we collide like stone coins and enemies.
Fox: This class deals with a fox-type enemy, and inherits from the Static class.
GameObject: This class is responsible for the various objects.
Gift: Responsible for the various gifts, heiress from the Static department.
InformationDisplay: This department is responsible for displaying information, inherited from the Observer department.
Level: Responsible for phase handling and we have the RunLevel function that runs the phase, this class inherits from the Observer class.
Line: This department is responsible for building a line on the board.
Open: This class is responsible for the game entry button, inherited from the Command class.
Observer: The department is responsible for updating everyone who registers with our game, everyone who registers for the register
Resources: This department is responsible for all uploading the various photos and songs.
Static: This class handles all static objects, and inherits from the GameObject class.
Stone: This department is responsible for the stones that go out to the player, an heir from the STATIC department.
TypeCars: This class handles the type of vehicle the user chooses, and inherits from the Command class.
TypeSongs: This class handles the type of music the user selects, and inherits from the Command class.
