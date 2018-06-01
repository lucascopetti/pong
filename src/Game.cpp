#include "../include/Game.hpp"
#include "../include/StringHelpers.hpp"


const float Game::Player1Speed = 400.f;
const float Game::Player2Speed = 400.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
, mTexture1()
, mTexture2()
, mPlayer1()
, mPlayer2()
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
, mIsMovingUp1(false)
, mIsMovingDown1(false)
, mIsMovingRight1(false)
, mIsMovingLeft1(false)
, mIsMovingUp2(false)
, mIsMovingDown2(false)
, mIsMovingRight2(false)
, mIsMovingLeft2(false)
{
	if (!mTexture1.loadFromFile("Media/Textures/Player1.png"))
	{
		// Handle loading error
	}

	mPlayer1.setTexture(mTexture1);
	mPlayer1.setPosition(10.f, 300.f);

	if (!mTexture2.loadFromFile("Media/Textures/Player2.png"))
	{
		// Handle loading error
	}

	mPlayer2.setTexture(mTexture2);
	mPlayer2.setPosition(610.f, 300.f);
	
	mFont.loadFromFile("Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement1(0.f, 0.f);
	sf::Vector2f movement2(0.f, 0.f);

	// player 1
	if (mIsMovingUp1)
		movement1.y -= Player1Speed;
	if (mIsMovingDown1)
		movement1.y += Player1Speed;
	//if (mIsMovingLeft1)
		//movement.x -= PlayerSpeed;
	//if (mIsMovingRight1)
		//movement.x += PlayerSpeed;

	mPlayer1.move(movement1 * elapsedTime.asSeconds());

	// player 2
	if (mIsMovingUp2)
		movement2.y -= Player2Speed;
	if (mIsMovingDown2)
		movement2.y += Player2Speed;
	//if (mIsMovingLeft2)
		//movement.x -= PlayerSpeed;
	//if (mIsMovingRight2)
		//movement.x += PlayerSpeed;
		
	mPlayer2.move(movement2 * elapsedTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();	
	mWindow.draw(mPlayer1);
	mWindow.draw(mPlayer2);
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
							 
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::W)
		mIsMovingUp1 = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown1 = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft1 = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight1 = isPressed;

	if (key == sf::Keyboard::Up)
		mIsMovingUp2 = isPressed;
	else if (key == sf::Keyboard::Down)
		mIsMovingDown2 = isPressed;
	else if (key == sf::Keyboard::Left)
		mIsMovingLeft2 = isPressed;
	else if (key == sf::Keyboard::Right)
		mIsMovingRight2 = isPressed;
}
