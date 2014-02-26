// Christopher D. Canfield
// February 2014
// rts-wars.hpp

#include "stdafx.h"

#include "GameApp.hpp"

using namespace cdc;

int main()
{
	cdc::AppRunner runner;
	
	GameApp app;
	runner.execute(app);

	return 0;
}

