#include "Node.h"


Node::Node(int pid) :
	_id(pid)
{
}


Node::~Node()
{
}


void Node::initialize()
{
	// Initialize items
	_itemList.randomInitialization();
}
