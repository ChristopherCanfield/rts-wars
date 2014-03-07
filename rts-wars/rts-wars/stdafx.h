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
#include <sstream>

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <cmath>
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

#include <Poco/SAX/ContentHandler.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/SAX/DefaultHandler.h>
#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/SAX/InputSource.h>

// Game Headers
#include "util/make_unique.hpp"
#include "util/Math.hpp"
#include "util/Typedefs.hpp"
#include "util/Observer.hpp"
#include "util/Observable.hpp"
#include "util/UUIDHash.hpp"
#include "util/Vector2fAdapter.hpp"

#include "util/FileLoadException.hpp"
#include "util/GameLogicException.hpp"
#include "util/NavGraphException.hpp"

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
#include "world/map/GameMap.hpp"

#include "world/map/terrain/Terrain.hpp"
#include "world/map/terrain/AbstractTerrain.hpp"
#include "world/map/terrain/Bridge.hpp"
#include "world/map/terrain/Dirt.hpp"
#include "world/map/terrain/Grass.hpp"
#include "world/map/terrain/Road.hpp"
#include "world/map/terrain/Water.hpp"

#include "world/map/nav/Node.hpp"
#include "world/map/nav/Edge.hpp"
#include "world/map/nav/PathKey.hpp"
#include "world/map/nav/GridLocation.hpp"
#include "world/map/nav/PathNode.hpp"
#include "world/map/nav/Search.hpp"

#include "controllers/Controller.hpp"
#include "controllers/CameraController.hpp"