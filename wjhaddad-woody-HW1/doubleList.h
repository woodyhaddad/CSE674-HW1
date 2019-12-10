#ifndef __2__
#define __2__

#include <iostream>
#include <vector>

using namespace std;

struct doubleNode
{
	int data;
	doubleNode *next;
	doubleNode *prev;

};

class doubleList
{
	doubleNode *head, *tail;
public:
	doubleList()
	{
		head = NULL;
		tail = NULL;
	}
	void add_node(int);	// this method adds a node to the list
	void transverse();	// this method prints the values of every node in the list
	void reverseTransverse();	// this method prints the values of every node in the double list backwards to verify that prev pointers are correct


	void teamOfFour(doubleList*);
	void reverse(doubleList*);
	void shuffle(doubleList*);
	//void insertLists(doubleList*, doubleList*, int);


};

#endif