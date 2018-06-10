/*
 * Application.h
 *
 *  Created on: Jun 5, 2018
 *      Author: lucas
 */

#ifndef INCLUDE_APPLICATION_H_
#define INCLUDE_APPLICATION_H_

class Application {
private:
		static const sf::Time	_timePerFrame;

		sf::RenderWindow		_window;
		TextureHolder			_textures;
	  	FontHolder				_fonts;
		//MusicPlayer				_music;
		SoundPlayer				_sounds;

		KeyBinding				_keyBinding1;
		KeyBinding				_keyBinding2;
		StateStack				_stateStack;

		sf::Text				_statisticsText;
		sf::Time				_statisticsUpdateTime;
		std::size_t				_statisticsNumFrames;
public:
								Application();
		void					run();
};

#endif /* INCLUDE_APPLICATION_H_ */
