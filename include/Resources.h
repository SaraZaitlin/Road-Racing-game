#pragma once
#include <vector>
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>
//The department is responsible for handling the uploads of photos and songs from the Singleton Department.
class Resources
{
public:
	~Resources()=default;
	sf::SoundBuffer& getSound(std::string sound);
	static Resources& instance();
	sf::Font& getFont();
	std::unique_ptr<sf::Music>& getMusic(std::string music);
	void playSound(std::string sound, float vol=5);
	void stopSound(std::string sound);
	std::map<std::string, std::vector<sf::Texture>> m_image;



private:
	std::map<std::string, sf::SoundBuffer> m_sound;
	std::map<std::string, std::unique_ptr<sf::Music>> m_music;
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources& other) = default;
	void pushTexturInMap();
	void pushMusicInMap();
	sf::Font m_font;

	sf::Sound m_sounds;

};

