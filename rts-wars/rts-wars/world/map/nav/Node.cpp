#include "stdafx.h"
#include "Node.hpp"

// Christopher D. Canfield
// October 2013
// Node.cpp

using cdc::Node;
using cdc::Terrain;
using cdc::GridLocation;

using namespace std;


Node::Node(GridLocation location, uint index, int pixelX, int pixelY, Terrain::UniquePtr terrain) :
	location(location), 
	index(index),
	pixelX(pixelX), 
	pixelY(pixelY), 
	circle(5),
	terrain(move(terrain))
{
	circle.setOrigin(circle.getLocalBounds().width / 2.f, circle.getLocalBounds().height / 2.f);
	circle.setPosition(Vector2fAdapter(pixelX, pixelY));
	circle.setFillColor(sf::Color::Blue);
}

// Move constructor and move assignment operator from http://msdn.microsoft.com/en-us/library/vstudio/dd293665.aspx

Node::Node(const Node&& other) :
	location(other.location), 
	pixelX(other.pixelX), 
	pixelY(other.pixelY), 
	circle(other.circle)
{
	adjacent = std::move(other.adjacent);
}

Node& Node::operator=(const Node&& other)
{
	if (this != &other)
	{
		adjacent = std::move(other.adjacent);
		pixelX = other.pixelX;
		pixelY = other.pixelY;
		location = other.location;
		circle = other.circle;
	}
	return *this;
}

Node::~Node()
{
}

const std::vector<uint>& Node::getAdjacent() const
{
	return adjacent;
}

uint Node::getIndex() const
{
	return index;
}

sf::Rect<float> Node::getBoundingBox() const
{
	const float width = 6;
	const float height = 6;
	return sf::Rect<float>(pixelX - 3.f, pixelY - 3.f, width, height);
}

uint Node::getRow() const
{
	return location.getRow();
}

uint Node::getColumn() const
{
	return location.getColumn();
}

bool Node::isConnected() const
{
	return (adjacent.size() != 0);
}

Terrain& Node::getTerrain() const
{
	return *terrain.get();
}

float Node::getCost() const
{
	return terrain->getCost();
}


void Node::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(circle, states);

	// TODO (2014-03-07): Update this if you want to draw the lines.
	/*for (auto& edge : edges)
	{
		if (!edge.expired())
		{
			target.draw(*edge.lock().get(), states);
		}
	}*/
}

std::string Node::toString() const
{
	std::stringstream val;
	val << "(" << getRow() << "," << getColumn() << ")";
	return val.str();
}


bool Node::operator==(const Node& other) const
{
	return (getColumn() == other.getColumn() &&
			getRow() == other.getRow());
}

bool Node::operator!=(const Node& other) const
{
	return !(*this == other);
}

std::ostream& operator<< (std::ostream& stream, const Node& node)
{
	stream << "(" << node.getRow() << "," << node.getColumn() << ")";
	return stream;
}