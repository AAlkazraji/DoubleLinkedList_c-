//Name: Assignment 1
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//date:16/09/2020
//Course:seng1120

#ifndef Ahmed_Node
#define Ahmed_Node
#include <cstdlib>
#include <iostream>
using namespace std;

class Node 
{
	typedef string value_type; 
	
	public:
	
		// Constructors
		Node (const value_type dataIn, Node *NextIn, Node *PrevIn);
		
		// Constructors
		Node (const value_type dataIn);
		
		// Descructors 
		~Node();
		
		//member function: a pointer to the next node 
		//preconditons: valid data 
		//postcondition: data set to the next node
		void setNext(const Node* n);
		
		//member function: a pointer to the next node 
		//preconditons: valid data 
		//postcondition: data set to the next node
		void setPrev(const Node* p);
		
		//member function: a fuction to set data
		//preconditons: valid data 
		//postcondition: data stored 
		void setData (const value_type& d);
		
		//member function: returning next pointer
		//preconditons: valid data 
		//postcondition: pointer sent to the next node
		Node* getNext();
		
		//member function: returning prevuse pointer
		//preconditons: valid data 
		//postcondition: pointer sent to the prevuse node
		Node* getPrev();
		
		//member function: returning next pointer
		//preconditons: valid data 
		//postcondition: pointer sent to the next node
		value_type getData();
		
		private:
		value_type data;
		Node* next;
		Node* prev;
};
#endif