#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "BaseApplication.h"

class SFMLApplication : public BaseApplication
{
protected:
	SFMLApplication(void);

	bool Run(void);

	void Update();

	void UpdateGraphic();

	void UpdateLogic();

	void UpdateInput();

	void OnResize(  unsigned int width, unsigned int height  );

	bool OnTerminate();

	bool OnInitilize();

	void InitGL();

public:
	virtual ~SFMLApplication(void);

private:
	sf::WindowSettings Settings;
	sf::RenderWindow App;
	sf::Clock Clock;

};


