#include "stdafx.h"

#include "AppRunner.hpp"

// Christopher D. Canfield
// October 2013
// AppRunner.cpp


using cdc::AppRunner;
using cdc::App;


void AppRunner::execute(App& app)
{
	try 
	{
		app.setup();

		// Loop until app.run() returns false.
		while (app.run()) {}

		app.teardown();
	}
	catch (const std::exception& e)
	{
		std::cerr << "An exception has occurred:\n";
		std::cerr << e.what() << std::endl;

		#ifdef _DEBUG
			system("PAUSE");
		#endif
	}
}
