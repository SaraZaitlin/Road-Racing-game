#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include"Command.h"
#include "Level.h"
class car;
class Controller
{
public:
	Controller(std::unique_ptr<Command> c1, std::unique_ptr<Command> c2, std::unique_ptr<Command> c3, std::unique_ptr<Command> c4);

	~Controller();
	void run();
private:
	void draw();
	void drawMenuCar();
	void drawMenuSong();
	int bouttonPressed(int buttonNum, sf::Vector2f position);
	sf::Vector2f hendlMouse();
	sf::Sprite setTextur(std::string name, int index)const;
	
	sf::Vector2f m_location;
	sf::RenderWindow m_window;
	sf::Sprite m_sprite;
	std::vector<std::unique_ptr<Command>> m_command;
	
};

