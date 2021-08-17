#include "Resources.h"

Resources::Resources()
{
	pushTexturInMap();
	pushMusicInMap();
}

void Resources::pushTexturInMap()
{
	sf::Texture texture;
	std::vector<sf::Texture> vec;
	texture.loadFromFile("bg8.png");
	vec.push_back(texture);
	m_image.emplace("background", vec);
	vec.clear();
	
	texture.loadFromFile("bg.png");
	vec.push_back(texture);
	texture.loadFromFile("bg5.png");
	vec.push_back(texture);
	m_image.emplace("bg", vec);
	vec.clear();

	texture.loadFromFile("start.png");
	vec.push_back(texture);
	m_image.emplace("start", vec);
	vec.clear();
	
	texture.loadFromFile("exit.png");
	vec.push_back(texture);
	m_image.emplace("exit", vec);
	vec.clear();

	texture.loadFromFile("bgGame.png");
	vec.push_back(texture);
	m_image.emplace("bgGame", vec);
	vec.clear();

	texture.loadFromFile("tree2.png");
	vec.push_back(texture);
	texture.loadFromFile("tree3.png");
	vec.push_back(texture);
	m_image.emplace("tree", vec);
	vec.clear();

	texture.loadFromFile("car1.png");
	vec.push_back(texture);
	texture.loadFromFile("car2.png");
	vec.push_back(texture);
	texture.loadFromFile("car3.png");
	vec.push_back(texture);
	m_image.emplace("car", vec);
	vec.clear();



	texture.loadFromFile("carEnemy3.png");
	vec.push_back(texture);
	m_image.emplace("carEnemy", vec);
	vec.clear();

	texture.loadFromFile("home.png");
	vec.push_back(texture);
	texture.loadFromFile("ob.png");
	vec.push_back(texture);
	m_image.emplace("home", vec);
	vec.clear();

	
	texture.loadFromFile("coins.png");
	vec.push_back(texture);
	m_image.emplace("coins", vec);
	vec.clear();

	texture.loadFromFile("addingFuel.png");
	vec.push_back(texture);
	m_image.emplace("addingFuel", vec);
	vec.clear();


	
	
	texture.loadFromFile("SumCoins.png");
	vec.push_back(texture);
	texture.loadFromFile("FuelGauge.png");
	vec.push_back(texture);
	m_image.emplace("infu", vec);
	vec.clear();
	
	texture.loadFromFile("stone1.png");
	vec.push_back(texture);
	m_image.emplace("stone", vec);
	vec.clear();

	texture.loadFromFile("bam.png");
	vec.push_back(texture);
	m_image.emplace("bam", vec);
	vec.clear();

	texture.loadFromFile("fox.png");
	vec.push_back(texture);
	m_image.emplace("fox", vec);
	vec.clear();

	texture.loadFromFile("win.jpg");
	vec.push_back(texture);
	texture.loadFromFile("game over.jpg");
	vec.push_back(texture);
	m_image.emplace("howEnd", vec);
	vec.clear();
	

	texture.loadFromFile("song1.png");
	vec.push_back(texture);
	texture.loadFromFile("song2.png");
	vec.push_back(texture);
	m_image.emplace("song", vec);
	vec.clear();

	texture.loadFromFile("choise1.png");
	vec.push_back(texture);
	texture.loadFromFile("choise2.png");
	vec.push_back(texture);
	m_image.emplace("choise", vec);
	vec.clear();
	
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

}

void Resources::pushMusicInMap()
{

	m_music["0"] = std::make_unique< sf::Music >();
	m_music["0"]->openFromFile("song.wav");
	m_music["0"]->setVolume(10);

	m_music["1"] = std::make_unique< sf::Music >();
	m_music["1"]->openFromFile("song2.wav");
	m_music["1"]->setVolume(10);

	m_sound["coins"] = sf::SoundBuffer();
	m_sound["coins"].loadFromFile("coin.wav");

	m_sound["bam"] = sf::SoundBuffer();
	m_sound["bam"].loadFromFile("bam.wav");

}

/*Resources::~Resources()
{
}*/


//---------------------------------------------------------------------
sf::SoundBuffer& Resources::getSound(std::string sound)
{
	return m_sound.find(sound)->second;
}
//-------------------------------------

//---------------------------------------
Resources& Resources::instance()
{
	static Resources instan;
	return instan;
}
//------------------------------------------
sf::Font& Resources::getFont()
{
	return m_font;
}


//---------------------------------------------------------------------
std::unique_ptr<sf::Music>& Resources::getMusic(std::string music)
{
	return m_music.find(music)->second;

}
//---------------------------------------------------------------------
void Resources::playSound(std::string sound, float vol)
{
	m_sounds.setBuffer(m_sound[sound]);
	m_sounds.setVolume(vol);
	m_sounds.play();
}
//---------------------------------------------------------------------
void Resources::stopSound(std::string sound)
{
	m_sounds.setBuffer(m_sound[sound]);
	m_sounds.stop();
}
/*sf::Sound& Resources::getSound(std::string str)
{
	// TODO: insert return statement here
	return m_sound.at(str);
}*/

