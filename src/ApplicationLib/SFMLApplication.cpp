#include "SFMLApplication.h"



SFMLApplication::SFMLApplication(void)
{
}


SFMLApplication::~SFMLApplication(void)
{
}

bool SFMLApplication::Run( void )
{


	Update();


	return EXIT_SUCCESS;
}

bool SFMLApplication::OnInitilize()
{
	Settings.DepthBits = 24;
	Settings.StencilBits = 8;
	Settings.AntialiasingLevel = 16;

	App.Create(sf::VideoMode(800, 600, 32), "SFML Test", sf::Style::Resize | sf::Style::Close, Settings);
	//App.PreserveOpenGLStates(true);

	InitGL();


	Settings = App.GetSettings();

	return true;
}

bool SFMLApplication::OnTerminate()
{
	return true;
}

void SFMLApplication::InitGL()
{
	// Set color and depth clear value
	glClearDepth(1.f);
	glClearColor(0.3f, 0.3f, 0.3f, 0.f);

	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	// Setup a perspective projection
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 90.f, 1.f, 1.f, 500.f );
	glShadeModel( GL_SMOOTH );
}

void SFMLApplication::OnResize( unsigned int width, unsigned int height )
{
	glViewport(0, 0, width, height);
}

//************************************
// Method:    Update
// FullName:  SFMLApplication::Update
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
// Update-Loop inspired by:
// http://www.koonsolo.com/news/dewitters-gameloop/
//************************************
void SFMLApplication::Update()
{
	static const int LOGIC_TICKS_PER_SECOND = 25;
	static const int TIME_PER_TICK = 1000 / LOGIC_TICKS_PER_SECOND;
	static const int MAX_FRAMESKIP = 5;

	while (App.IsOpened())
	{

		//while ( )
		UpdateLogic();

		UpdateGraphic();


	}
}

void SFMLApplication::UpdateLogic()
{
	UpdateInput();

}

void SFMLApplication::UpdateGraphic()
{
	App.SetActive();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//DrawScene();

	App.Display();
}

void SFMLApplication::UpdateInput()
{
	sf::Event Event;

	if (App.GetEvent(Event))
	{
		if (Event.Type == sf::Event::Closed)
		{
			App.Close();
		}

		if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
		{
			App.Close();
		}

		if (Event.Type == sf::Event::Resized)
		{
			OnResize(Event.Size.Height, Event.Size.Width);

		}
	}
}
