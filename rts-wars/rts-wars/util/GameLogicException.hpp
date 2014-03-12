#pragma once

// Christopher D. Canfield
// February 2014
// GameLogicException.hpp

#include <string>
#include <stdexcept>

namespace cdc
{
	///<summary>Thrown when a logic error occurs.</summary>
	class GameLogicException :
		public std::logic_error
	{
	public:
		GameLogicException(std::string className, std::string methodName, std::string message);
		virtual ~GameLogicException();

		///<summary>Returns the name of the class that threw the exception.</summary>
		///<returns>The name of the class that threw the exception.</returns>
		const std::string& getClassName() const;

		///<summary>Returns the name of the method that threw the exception.</summary>
		///<returns>The name of the method that threw the exception.</returns>
		const std::string& getMethodName() const;

	private:
		std::string className;
		std::string methodName;
	};
}
