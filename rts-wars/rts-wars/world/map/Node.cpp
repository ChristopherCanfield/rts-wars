#include "stdafx.h"
#include "Node.hpp"

// Christopher D. Canfield
// March 2014
// Node.cpp

using namespace cdc;
using namespace std;

Node::Node(Terrain&& t) :
	terrain(move(unique_ptr<Terrain>(&t)))
{
}


Node::~Node()
{
}


std::vector<Node::WeakPtr>& Node::getConnections()
{
	return connections;
}

void Node::addConnection(Node::SharedPtr node)
{
	auto nodeWeakPtr = std::weak_ptr<Node>(node);
	connections.push_back(nodeWeakPtr);
}

void Node::removeConnection(Node& node)
{

}

Terrain& Node::getTerrain() const
{
	return *terrain.get();
}