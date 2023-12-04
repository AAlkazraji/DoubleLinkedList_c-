//Name: Assignment 1
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//date:16/09/2020
//Course:seng1120

#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;


	typedef string value_type;
	
	// Constructors
	LinkedList::LinkedList()    
    {
		//sets head to null
        head = NULL; 
		// sets tail to null
        tail = NULL; 
		// sets current to null
        current = NULL;
		//sets length to 0
        length = 0;
    }
	
    // Constructors
    LinkedList::LinkedList(value_type& data)
    {
		// make node
        head = new Node(data);
		//sets tail = to head
        tail = head;
		// sets current = tail
        current = tail; 
		// sets length = 0
        length = 1;             
        return;
    }
    // Descructors 
    LinkedList::~LinkedList()
	{
		// while loop breakes when head = null
        while(head != NULL)   
        {
			//temprary varble type node
			Node* temp;
			//sets temprary = head
            temp = head;
			//storing next node to head
            head = head->getNext();
			// if statment works when head is has data
            if (head != NULL)
				{
					// when head is not null sets prevuse node to head
					head->setPrev(NULL);
				}	
            else
				{
					tail = NULL;
				} 
			// deleting temprary to avoid momary leaks
            delete temp; 					
            current = head; 								
        }
		length = 0;												
    }
    
    void LinkedList::addToTail(const value_type& data)
    {
		//if statment works only when length = 0
        if (length == 0)
        {	
            tail = new Node(data); 		
            head = tail;                   
            length = 1;            					
        }
        else
        {
			//making new tail type node
            Node* newTail = new Node(data);
			//sets tail to new node
            tail->setNext(newTail);  
			//sets new tail to prevuse node 
            newTail->setPrev (tail);   			
            tail = newTail; 
			//length increses every time else stament works
            length++;                         	 
            newTail = NULL;                   		
        }
  
    }
	
	
	void LinkedList::addToHead(const value_type& data)
	{
		if (length == 0)
        {
			//assigning tail to node
            tail = new Node(data);
			//assigning head to tail
            head = tail;           
            current = head;        
            length = 1;            									
        }
		else
		{
		    Node* newHead = new Node(data);   						
            head->setPrev(newHead);         						
            newHead->setNext (head);   						
            head = newHead;
            length++;                         						
            newHead = NULL;
		}
	}
	
	void LinkedList::removeHead()
	{
		Node* tempHead = head;
		head = head->getNext();
		if(head != NULL)
		{head->setPrev(NULL);}
		
		else
		{tail = NULL;}
	
		// length decreses every time head removed 
		length --;
		//delete temp head to avoid momary leaks
		delete tempHead;
		
	}
	
	void LinkedList::removeTail()
	{
		
		Node* tempTail = tail;
		tail = tail->getPrev();
		if(tail != NULL)
		{tail->setNext(NULL);}
		
		else
		{head = NULL;}
		// length decreses every time tail removed 
		length --;
		//delete temp tail to avoid momary leaks
		delete tempTail;
		
	}
	
   
    Node* LinkedList::getCurrent() const
        {
            return current;  
        }

    Node* LinkedList::getHead() const
        {
            return head;
        }
		
    Node* LinkedList::getTail() const
        {
            return tail;
        }
		
		
	void LinkedList::operator += (LinkedList const &x)
	{ 
		Node *temp = x.getHead();
		while(temp!=NULL)
		{
			this->addToTail(temp->getData());
			temp = temp->getNext();
		}
	}
	
	void LinkedList::add(const value_type data)
	{
	   //breaks down the sentence into words
	   std::istringstream stringWords(data);
	   do
	   {
		   std::string word;
		   stringWords >> word;

		   if (length == 0)
		   {addToHead(word);}
	   
		   else 
		   {addToTail(word);}
		   
		   length++;

	   }
	   while(stringWords != NULL);
	}

	void LinkedList::remove(const value_type data)
		{
		
		  current = head;
		  
		  while (current != NULL)
		  {
			   
			  if(((data == current->getData())) && (current == head))
			  {
				  this->removeHead();
			  }
			   else if(data == tail->getData())
			  {
				  this->removeTail();
			  }
			   
			  else if (data == current->getData())
			{
				Node* temp;
				temp = current->getPrev();
				temp->setNext(current->getNext());
				temp = current->getNext();
				temp->setPrev(current->getPrev());
				delete current;
				length --;
				current = temp;
			}
			  current = current->getNext();
		  }
		}
	
	int LinkedList::count(const value_type data)
		{ 
			//statrting from the head and compare the data and the returns the number of a string in a list
			current = head;
			int num =0;
			while (current != NULL)
			{
				if (data == current->getData())
				{
					num++;
				}
				current = current->getNext();
			}
			return num;
			
		}
	
	
    void LinkedList::sort()
	
	{	// for loop will execute when the list is over 
		current = head;
		for (int i=0; i<length; i++)
		{
			// if setmante to compare between the nodes if Node A comes befor Node B then start from the next node
			Node* tempC = current;
			if (tempC->getData().compare(tempC->getNext()->getData()) > 0)
				
				{
					// a while loop to keep going through list 
					while (tempC->getNext() != NULL)
					{
						// if setmante to compare between the nodes if Node A comes befor Node B then start from the next node
						if (tempC->getData().compare(tempC->getNext()->getData()) > 0)
						{		
							// switching between the links that link the nodes
							Node* tempNext = tempC->getNext();
							tempC->setNext(tempNext->getNext());
							
							if(tempC->getPrev()!= NULL )
							{
							tempC->getPrev()->setNext(tempNext);
							 tempNext->setPrev(tempC->getPrev());	
							}
							else
							{
								head = tempNext;
							}
							tempC->setPrev(tempNext);
							if( tempNext->getNext()!= NULL)
								{
								 tempNext->getNext()->setPrev(tempC);
								}
							else
							{
								tail= tempC;
							}
							tempNext->setNext(tempC);					 
							
						}
						else{break;}
					}
					
				}
				else
				{tempC = tempC->getNext();}
			
			
		}
		
	}
	
	ostream& operator<<(ostream& os, LinkedList& data) 
	{
     Node *current = data.getHead();
    while(current != NULL)
	{
        os << current->getData();
		os << " ";
		current = current->getNext();
	}
    return os;
	}

	