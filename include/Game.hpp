#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
	public:
								Game();
		void					run();
		

	private:
		void					processEvents();
		void					update(sf::Time elapsedTime);
		void					render();

		void					updateStatistics(sf::Time elapsedTime);	
		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		

	private:
		static const float		Player1Speed;
		static const float		Player2Speed;
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		sf::Texture				mTexture1;
		sf::Texture				mTexture2;
		sf::Sprite				mPlayer1;
		sf::Sprite				mPlayer2;
		sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;

		std::size_t				mStatisticsNumFrames;
		bool					mIsMovingUp1;
		bool					mIsMovingDown1;
		bool					mIsMovingRight1;
		bool					mIsMovingLeft1;
		bool					mIsMovingUp2;
		bool					mIsMovingDown2;
		bool					mIsMovingRight2;
		bool					mIsMovingLeft2;
};

#endif // BOOK_GAME_HPP
