#include "LinkedListType.h"

ostream& operator<<(ostream& out, const LinkedListType& theList)
{
	Node *current = theList.first;

	while (current != nullptr)
	{
		out << current->getInfo() << " ";
		current = current->getLink();
	}

	return out;
}

LinkedListType::LinkedListType() 
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

void LinkedListType::insertLast(int newItem)
{
	Node *newNode = new Node(newItem, 0);
            								
	if(first == nullptr) first = newNode;	
	else last->setLink(newNode);		

	last = newNode;
	++count;
}

void LinkedListType::destroyList()
{
	while(first != nullptr)   
	{
	   Node *temp = first;
	   first = first->getLink();	
	   delete temp;					
	}

	last = nullptr;	                   
 	count = 0;
}

LinkedListType::~LinkedListType() 
{
	destroyList(); 
}




