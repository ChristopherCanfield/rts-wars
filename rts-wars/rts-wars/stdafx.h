// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <cstdio>

// Standard library headers
#include <string>
#include <iostream>

#include <vector>
#include <unordered_map>

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <memory>

// SFML Headers
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// Poco Headers
#include <Poco/Random.h>
#include <Poco/UUID.h>
#include <Poco/UUIDGenerator.h>

// Utility Helpers
#include "util/make_unique.hpp"
#include "util/Math.hpp"
#include "util/Typedefs.hpp"
#include "util/Observer.hpp"
#include "util/Observable.hpp"
#include "util/UUIDHash.hpp"
#include "util/FileLoadException.hpp"
#include "util/GameLogicException.hpp"

#include "graphics/Graphics.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Sprite.hpp"
#include "graphics/sprites/AbstractSprite.hpp"

#include "app/App.hpp"
#include "app/AppRunner.hpp"
#include "app/Constants.hpp"

#include "ui/GuiEventManager.hpp"
#include "ui/GuiEventObserver.hpp"
#include "ui/DirectGuiEventObserver.hpp"

#include "world/Entity.hpp"
#include "world/World.hpp"

#include "controllers/Controller.hpp"
#include "controllers/CameraController.hpp"