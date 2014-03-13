#include "stdafx.h"
#include "Events.hpp"

// Christopher D. Canfield
// March 2014
// Events.hpp

using namespace cdc;

std::unique_ptr<Events> Events::instance;

Events& Events::Instance()
{
	if (instance == nullptr)
	{
		instance = std::unique_ptr<Events>(new Events());
	}
	return *instance;
}

Events::Events()
{
}


Events::~Events()
{
}

// Processes GUI events by notifying subscribed observers. This should be
// called once per frame.
void Events::update(const sf::Event& e, const sf::RenderWindow& window)
{
	guiEventManager.update(e, window);
}

// Registers the observer for click events.
void Events::addClickListener(GuiEventObserver& o)
{
	guiEventManager.addClickListener(o);
}
	
// Unregisters the observer for click events.
void Events::removeClickListener(const GuiEventObserver& o)
{
	guiEventManager.removeClickListener(o);
}

// Registers the observer for mouse move events.
void Events::addMouseMoveListener(GuiEventObserver& o)
{
	guiEventManager.addMouseMoveListener(o);
}

// Unregisters the observer for mouse move events.
void Events::removeMouseMoveListener(const GuiEventObserver& o)
{
	guiEventManager.removeMouseMoveListener(o);
}

// Registers the observer for mouse wheel events.
void Events::addMouseWheelListener(GuiEventObserver& o)
{
	guiEventManager.addMouseWheelListener(o);
}

// Unregisters the observer for mouse wheel events.
void Events::removeMouseWheelListener(const GuiEventObserver& o)
{
	guiEventManager.removeMouseWheelListener(o);
}

// Registers the observer for key press events.
void Events::addKeyPressListener(GuiEventObserver& o)
{
	guiEventManager.addKeyPressListener(o);
}

// Unregisters the observer for key press events.
void Events::removeKeyPressListener(const GuiEventObserver& o)
{
	guiEventManager.removeKeyPressListener(o);
}

// Registers the DirectGuiEventObserver for click events that fall within its bounding box.
void Events::addDirectClickListener(DirectGuiEventObserver& o)
{
	guiEventManager.addDirectClickListener(o);
}

// Unregisters the DirectGuiEventObserver for the click events that fall within its bounding box.
void Events::removeDirectClickListener(const DirectGuiEventObserver& o)
{
	guiEventManager.removeDirectClickListener(o);
}

// Registers the DirectGuiEventObserver for mouse move events that fall within its bounding box.
void Events::addDirectMouseMoveListener(DirectGuiEventObserver& o)
{
	guiEventManager.addDirectMouseMoveListener(o);
}

// Unregisters the DirectGuiEventObserver for the mouse move events that fall within its bounding box.
void Events::removeDirectMouseMoveListener(const DirectGuiEventObserver& o)
{
	guiEventManager.removeDirectMouseMoveListener(o);
}