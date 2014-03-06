#include "stdafx.h"
#include "Node.hpp"

// Christopher D. Canfield
// October 2013
// Node.cpp

using cdc::Node;
using cdc::Edge;
using cdc::GridLocation;

using namespace std;


Node::Node(GridLocation location, int pixelX, int pixelY) :
	location(location), 
	pixelX(pixelX), 
	pixelY(pixelY), 
	circle(5)
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
	edges = std::move(other.edges);
}

Node& Node::operator=(const Node&& other)
{
	if (this != &other)
	{
		edges = std::move(other.edges);
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

Node& Node::addEdge(shared_ptr<Edge> edge, bool addEdgeToOppositeNode)
{
	for (auto& e : edges)
	{
		if (edge == e.lock())
		{
			return *this;
		}
	}
	edges.push_back(edge);
	
	if (addEdgeToOppositeNode)
	{
		auto oppNode = edge->getOppositeNode(*this);
		if (oppNode != nullptr)
		{
			oppNode->addEdge(edge, false);
		}
	}

	return *this;
}

void Node::removeEdge(Edge& edge, bool removeEdgeFromOpposite)
{
	for (auto e = edges.begin(); e != edges.end(); ++e)
	{
		if (!e->expired())
		{
			auto dereferencedEdge = *e->lock().get();
			if (dereferencedEdge == edge)
			{
				if (removeEdgeFromOpposite)
				{
					dereferencedEdge.getOppositeNode(*this)->removeEdge(dereferencedEdge, false);
				}
				edges.erase(e);
				return;
			}
		}
	}
}

const std::vector<Edge::WeakPtr>& Node::getEdgeList() const
{
	return edges;
}

Edge& Node::getEdge(uint index) const
{
	// TODO: this needs to be tested, or removed.
	if (index < edges.size())
	{
		return *edges[index].lock().get();
	}
	else
	{
		throw out_of_range("Index provided to Node::getEdge is out of range. Index: " + index);
	}
}

bool Node::edgeExists(Edge& edge) const
{
	for (auto e : edges)
	{
		if (*e.lock().get() == edge)
		{
			return true;
		}
	}
	return false;
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
	return (edges.size() != 0);
}


void Node::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(circle, states);

	for (auto& edge : edges)
	{
		if (!edge.expired())
		{
			target.draw(*edge.lock().get(), states);
		}
	}
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