#include "stdafx.h"
#include "Edge.hpp"

#include <cassert>

// Christopher D. Canfield
// October 2013
// Edge.cpp

using cdc::Edge;
using cdc::Node;
using cdc::PathNode;


Edge::Edge(cdc::Node& startNode) :
	startNode(&startNode),
	endNode(nullptr), 
	cost(999999)
{
	vertices.setPrimitiveType(sf::Lines);
}

Edge::Edge(cdc::Node& startNode, cdc::Node& endNode, float cost) :
	startNode(&startNode),
	endNode(&endNode), 
	cost(cost)
{
	setVertices(startNode, endNode);
}

Edge::Edge(Node& startNode, Node& endNode, int cost) :
	startNode(&startNode),
	endNode(&endNode),
	cost(static_cast<float>(cost))
{
	setVertices(startNode, endNode);
}

void Edge::setVertices(Node& startNode, Node& endNode)
{
	vertices.setPrimitiveType(sf::Lines);

	vertices.append(sf::Vertex(
			Vector2fAdapter(startNode.getPixelX<uint>(), startNode.getPixelY<uint>()), 
			sf::Color(0, 0, 255)));

	vertices.append(sf::Vertex(
			Vector2fAdapter(endNode.getPixelX<uint>(), endNode.getPixelY<uint>()), 
			sf::Color(0, 0, 255)));
}

Node* Edge::getNode1() const
{
	return startNode;
}

Node* Edge::getNode2() const
{
	return endNode;
}

Node* Edge::getOppositeNode(const Node& node) const
{
	if (*startNode == node)
	{
		return endNode;
	}
	else if (*endNode == node)
	{
		return startNode;
	}
	return nullptr;
}

Node* Edge::getOppositeNode(PathNode node) const
{
	return getOppositeNode(node.getNode());
}

float Edge::getCost() const
{
	return cost;
}

void Edge::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (endNode != nullptr)
	{
		target.draw(vertices, states);
	}
}

void Edge::draw(sf::RenderTarget &target, sf::RenderStates states, sf::Color color) const
{
	using namespace sf;

	if (endNode != nullptr)
	{
		VertexArray path;
		path.setPrimitiveType(sf::Lines);

		// TODO: set this on construction, instead of continuously recreating it.
		path.append(Vertex(Vector2f(startNode->getPixelX<float>(), startNode->getPixelY<float>()), color));
		path.append(Vertex(Vector2f(endNode->getPixelX<float>(), endNode->getPixelY<float>()), color));

		target.draw(path, states);
	}
}

bool Edge::operator==(const Edge& other) const
{
	return (this->getCost() == other.getCost() &&
			this->getNode1() == other.getNode1() &&
			this->getNode2() == other.getNode2());
}

bool Edge::operator!=(const Edge& other) const
{
	return !(*this == other);
}