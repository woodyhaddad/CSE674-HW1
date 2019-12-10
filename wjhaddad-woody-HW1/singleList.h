#ifndef __1__
#define __1__

#include <iostream>
#include <vector>

using namespace std;

struct singleNode
{
	int data;
	singleNode *next;
};

class singleList
{
	singleNode *head, *tail;
public:
	singleList()
	{
		head = NULL;
		tail = NULL;
	}
	void add_node(int);	// this method adds a node to the list
	void transverse();	// this method prints the values of every node in the list
	
	void teamOfFour(singleList*);
	void reverse(singleList*);
	void shuffle(singleList*);



};

#endif