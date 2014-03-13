#pragma once

#include "controllers/inputcontrollers/ui/DirectGuiEventObserver.hpp"
#include "controllers/inputcontrollers/ui/GuiEventManager.hpp"
#include "controllers/inputcontrollers/ui/GuiEventObserver.hpp"

#include <memory>

// Christopher D. Canfield
// March 2014
// Events.hpp

namespace cdc
{
	///<Summary></summary>
	class Events
	{
	public:
		static Events& Instance();

		~Events();

		// Processes GUI events by notifying subscribed observers. This should be
		// called once per frame.
		void update(const sf::Event& e, const sf::RenderWindow& window);
	
		// Registers the observer for click events.
		void addClickListener(GuiEventObserver& o);
	
		// Unregisters the observer for click events.
		void removeClickListener(const GuiEventObserver& o);

		// Registers the observer for mouse move events.
		void addMouseMoveListener(GuiEventObserver& o);

		// Unregisters the observer for mouse move events.
		void removeMouseMoveListener(const GuiEventObserver& o);

		// Registers the observer for mouse wheel events.
		void addMouseWheelListener(GuiEventObserver& o);

		// Unregisters the observer for mouse wheel events.
		void removeMouseWheelListener(const GuiEventObserver& o);

		// Registers the observer for key press events.
		void addKeyPressListener(GuiEventObserver& o);

		// Unregisters the observer for key press events.
		void removeKeyPressListener(const GuiEventObserver& o);

		// Registers the DirectGuiEventObserver for click events that fall within its bounding box.
		void addDirectClickListener(DirectGuiEventObserver& o);

		// Unregisters the DirectGuiEventObserver for the click events that fall within its bounding box.
		void removeDirectClickListener(const DirectGuiEventObserver& o);

		// Registers the DirectGuiEventObserver for mouse move events that fall within its bounding box.
		void addDirectMouseMoveListener(DirectGuiEventObserver& o);

		// Unregisters the DirectGuiEventObserver for the mouse move events that fall within its bounding box.
		void removeDirectMouseMoveListener(const DirectGuiEventObserver& o);

	private:
		Events();

		Events& operator=(const Events&);

		GuiEventManager guiEventManager;

		static std::unique_ptr<Events> instance;
	};
}
