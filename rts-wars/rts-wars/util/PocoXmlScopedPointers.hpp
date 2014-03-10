#pragma once

#include <Poco/DOM/NamedNodeMap.h>
#include <Poco/DOM/NodeList.h>

// Christopher D. Canfield
// March 2014
// PocoXmlScopedPointers.hpp


namespace cdc
{
	namespace poco
	{
		// Scoped pointer for Poco::XML::NamedNodeMap
		class ScopedNamedNodeMap
		{
		public:
			ScopedNamedNodeMap(Poco::XML::NamedNodeMap* attributes) :
				att(attributes) {}

			~ScopedNamedNodeMap() {
				att->release();
			}

			Poco::XML::NamedNodeMap* operator->() { 
				return att; 
			}

		private:
			Poco::XML::NamedNodeMap* att;
		};

		// Scoped pointer for Poco::XML::NodeList
		class ScopedNodeList
		{
		public:
			ScopedNodeList(Poco::XML::NodeList* list) :
				nodeList(list) {}

			~ScopedNodeList() {
				nodeList->release();
			}

			Poco::XML::NodeList* operator->() { 
				return nodeList;
			}

		private:
			Poco::XML::NodeList* nodeList;
		};
	}
}