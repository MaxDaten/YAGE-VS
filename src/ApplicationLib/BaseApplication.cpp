#include "BaseApplication.h"

#include <stdlib.h>

BaseApplication::BaseApplication(void)
{
}


BaseApplication::~BaseApplication(void)
{
}

bool BaseApplication::Initilize( void )
{
	return this->OnInitilize();
}

bool BaseApplication::Terminate( void )
{
	return this->OnTerminate();
}

bool BaseApplication::OnInitilize( void )
{
	return true;
}

bool BaseApplication::OnTerminate( void )
{
	return true;
}

int BaseApplication::Main( void )
{
	if (!this->Initilize())
	{
		return EXIT_FAILURE;
	}

	this->Run();

	if (!this->Terminate())
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


