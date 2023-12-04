//Name: Assignment 1
//Author: Ahmed Al-khazraji
//Student numbers: c3277545
//date:16/09/2020
//Course:seng1120

#ifndef AhmedLinked_List
#define AhmedLinked_List
#include <bits/stdc++.h>
#include "Node.h"
#include <cstdlib>
using namespace std;


class LinkedList
{
	typedef string value_type;
		
		public:
			// Constructors
			LinkedList();
			
			// Constructors
			LinkedList(value_type& data); 
			
			// Descructors 
			~LinkedList();	
			
			//member function: adding data to the tail
			//preconditons: valid data
			//postcondition: data stored in tail
			void addToTail(const value_type& data);

			//member function: adding data to the head
			//preconditons: valid data
			//postcondition: data stored in head			
			void addToHead(const value_type& data);
			
			//member function: removing the head
			//preconditons: there has to be head 
			//postcondition: head removed
			void removeHead();
			
			//member function: removing the tail
			//preconditons: there has to be tail
			//postcondition: tail removed
			void removeTail();
			
			//member function: return head
			//preconditons: there has to be head 
			//postcondition: return head
			Node* getHead() const;
			
			//member function: return tail
			//preconditons: there has to be tail
			//postcondition: return tail
			Node* getTail() const;
			
			//member function: return current 
			//preconditons: there has to be carrunt data 
			//postcondition: return current
            Node* getCurrent() const;

			//member function: over loaded operator  
			//preconditons: adds the data between the 2 sets 
			//postcondition: data added
			void operator += (LinkedList const &x);
			
			//member function: adds the strings that specified by the user  
			//preconditons: there is a list and it has to be duoblly liked
			//postcondition: all stings added to nodes in a list
			void add(const value_type data);
			
			//member function: removes the strings that specified by the user   
			//preconditons: there is a list and it has to be duoblly liked 
			//postcondition: strings that specified by the user is removed 
			void remove(const value_type data);
			
			//member function: counts the strings that specified by the user  
			//preconditons: there is a list and it has to be duoblly liked
			//postcondition: number of the strings that specifide 
			int count(const value_type data);
			
			//member function: sorting the list in alphebatical oreder 
			//preconditons: there is a list and it has to be duoblly liked 
			//postcondition: data sorted       <<<<------------------------------ my sorting function isnt working propally :(
			void sort();
		

		private:
			Node* head;     
			Node* tail;     
			Node* current;  
			int length;
			LinkedList* list;
			
};
ostream& operator<<(ostream& os, LinkedList& names);

#endif