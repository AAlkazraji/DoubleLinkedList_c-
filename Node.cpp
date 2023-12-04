//Name: Assignment 1
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//date:16/09/2020
//Course:seng1120

#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std;

	typedef string value_type; 

	// Constructors
	Node::Node (const value_type dataIn, Node *NextIn, Node *PrevIn)
	{
		data = dataIn;
		next = NextIn;
		prev = PrevIn;	
    }
	
	// Constructors
	Node::Node (const value_type dataIn)
	{
		data = dataIn;
		next = NULL;
		prev = NULL;	
	}
	
	// Descructors 
	Node::~Node()
    {
		next = NULL;
		prev = NULL;
	}

	void Node::setNext(const Node* nextNode)
    {
		next = (Node*) nextNode;
	}
	
	void Node::setPrev(const Node* prevNode)
    {
		prev = (Node*) prevNode;
	}
	
	void Node:: setData (const value_type& d)
    {
		data = d;
	}
	
	Node::value_type Node::getData()
    {
		return data;
	}
	
	Node* Node::getNext()
    {
		return next;
	}
	
	Node* Node::getPrev()
    {
		return prev;
	}
	
	