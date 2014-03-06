#include "stdafx.h"
#include "Node.hpp"

// Christopher D. Canfield
// March 2014
// Node.cpp

using namespace cdc;


Node::explicit Node(Terrain&& terrain);
{
}


Node::~Node()
{
}


std::vector<Node::WeakPtr>& getConnections() const;

void addConnection(Node& node);

void removeConnection(Node& node);

Terrain& getTerrain() const;