#pragma once


class BaseApplication
{
protected:
	BaseApplication(void);

	virtual bool OnInitilize(void);

	//************************************
	// Method:    Run
	// FullName:  BaseApplication::Run
	// Access:    virtual protected static 
	// Returns:   bool
	// Qualifier:
	// Parameter: void
	//************************************
	// Implement this
	//************************************
	virtual bool Run(void) = 0;

	virtual bool OnTerminate(void);

public:
	virtual ~BaseApplication(void);

	int Main(void);

private:

	bool Initilize(void);

	bool Terminate(void);

};

