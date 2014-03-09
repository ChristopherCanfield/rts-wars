#pragma once

#include "util/Typedefs.hpp"

#include <string>
#include <vector>
#include <utility>

// Christopher D. Canfield
// March 2014
// TiledMapFileInfo.hpp

namespace cdc
{
	namespace tiled
	{
		/// <summary>Properties for a map image.</summary>
		struct MapImageProperties
		{
			MapImageProperties() :
				imageLeft(0),
				imageTop(0) {}

			std::string fileName;
			uint imageLeft;
			uint imageTop;
		};

		/// <summary>Information about the map file.</summary>
		class TiledMapFileInfo
		{
		public:
			TiledMapFileInfo();
			virtual ~TiledMapFileInfo();

			///<summary>Returns the Tiled TMX file name.</summary>
			const std::string& getTmxFileName() const {
				return fileName;
			}

			///<summary>Returns a reference to the list of map properties.</summary>
			std::vector<MapImageProperties> getProperties() const {
				return properties;
			}

		protected:
			void setFileName(std::string&& fileName) {
				fileName = std::move(fileName);
			}

			void setProperties(std::vector<MapImageProperties>& properties) {
				properties = std::move(properties);
			}

		private:
			std::string fileName;
			std::vector<MapImageProperties> properties;
		};
	}
}
