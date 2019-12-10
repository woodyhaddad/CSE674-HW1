
#include <iostream>
#include "doubleList.h"

void doubleList::add_node(int value)				// Helper function to add node to tail of list
{
	doubleNode *temp = new doubleNode;
	temp->data = value;
	temp->next = NULL;
	temp->prev = tail;


	if (head == NULL) // list is empty
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		temp = NULL;
	}
}

void doubleList::transverse()						// Prints out the list with items grouped by 4 
{
	doubleNode *tempo = head;
	int i = 0;
	while (tempo != NULL)
	{
		i++;
		if (i % 4 == 0)
		{
			cout << tempo->data;
			if (tempo->next != NULL)
			{
				cout << ", ";
			}
			cout << endl;
		}
		else
		{
			cout << tempo->data;
			cout << ", ";
		}
		tempo = tempo->next;
	}

}

void doubleList::reverseTransverse()						// Prints out the double list backwards with items grouped by 4 
{
	doubleNode *tempo = tail;
	int i = 0;
	while (tempo != NULL)
	{
		i++;
		if (i % 4 == 0)
		{
			cout << tempo->data;
			if (tempo->prev != NULL)
			{
				cout << ", ";
			}
			cout << endl;
		}
		else
		{
			cout << tempo->data;
			cout << ", ";
		}
		tempo = tempo->prev;
	}

}

void doubleList::teamOfFour(doubleList* list)
{
	doubleNode *t0 = list->head;
	doubleNode *t1 = list->head;
	doubleNode *t2 = t1->next;
	doubleNode *t3 = t2->next;
	doubleNode *t4 = t3->next;

	doubleNode *temp, *temp2, *temp3, *t;

	while (true)
	{
		while (!((t1->data <= t2->data) && (t2->data <= t3->data) && (t3->data <= t4->data)))
		{
			//printf("while executes\n");
			//printf("while evaluates to %d\n\n", !((t1->data <= t2->data) && (t2->data <= t3->data) && (t3->data <= t4->data)));

			if (t1->data > t2->data)
			{

				t1->next = t3;
				t3->prev = t1;
				t2->next = t1;
				t1->prev = t2;
				if (t0 != list->head)
				{
					t0->next = t2;
					t2->prev = t0;
				}
				temp = t1;
				t1 = t2;
				t2 = temp;

				
				//printf("t1 is %d, t1->next is %d, t1->next->next is %d, t1->next->next->next is %d\n", t1->data, t1->next->data, t1->next->next->data, t1->next->next->next->data);

			}

			if (t2->data > t3->data)
			{
				t2->next = t4;
				t4->prev = t2;
				t3->next = t2;
				t2->prev = t3;
				t1->next = t3;
				t3->prev = t1;

				temp = t2;
				t2 = t3;
				t3 = temp;
				//printf("t1 is %d, t1->next is %d, t1->next->next is %d, t1->next->next->next is %d\n", t1->data, t1->next->data, t1->next->next->data, t1->next->next->next->data);

			}

			if (t3->data > t4->data)
			{
				//printf("t4->data = %d, t4->next->data = %d\n", t4->data, t4->next->data);
				t3->next = t4->next;
				t4->next = t3;
				t3->prev = t4;
				t2->next = t4;
				t4->prev = t2;

				temp = t3;
				t3 = t4;
				t4 = temp;
				//printf("t1 is %d, t1->next is %d, t1->next->next is %d, t1->next->next->next is %d\n", t1->data, t1->next->data, t1->next->next->data, t1->next->next->next->data);

			}

		}
		if (t0 == head)
		{
			head = t1;
			t1->prev = NULL;
		}
		//printf("t0 is %d, t1 is %d, t2 is %d, t3 is %d, t4 is %d\n", t0->data, t1->data, t2->data, t3->data, t4->data);
		//printf("t1 is %d, t1->next is %d, t1->next->next is %d, t1->next->next->next is %d\n", t1->data, t1->next->data, t1->next->next->data, t1->next->next->next->data);

		if (t4->next == NULL)
		{
			list->tail = t4;
			break;
		}
		if (t3->next == NULL)
		{
			list->tail = t3;
			break;
		}
		if (t2->next == NULL)
		{
			list->tail = t2;
			break;
		}
		if (t1->next == NULL)
		{
			list->tail = t1;
			break;
		}

		t0 = t4;
		t1 = t0->next;
		t2 = t1->next;
		t3 = t2->next;
		t4 = t3->next;
		//printf("t0 is %d, t1 is %d, t2 is %d, t3 is %d, t4 is %d\n", t0->data, t1->data, t2->data, t3->data, t4->data);


	}
	//printf("list->head->data is %d\n", list->head->data);
	//printf("list->tail->data is %d\n", list->tail->data);
}

void doubleList::reverse(doubleList* list)
{
	vector<doubleNode*> vect;				// initialize vector that stores nodes
											//vect.push_back(list.head);
											//cout << vect[0] <<endl;
	doubleNode* node = list->head;

	while (node != NULL)					// this loop stores pointer values from head to tail in reverse order inside the vector
	{
		vect.insert(vect.begin(), 1, node);
		node = node->next;
	}

	//cout << "vector size = ";
	//cout << vect.size() << endl;

	list->head = vect[0];		// reassign the head to the last node
	list->tail = vect[vect.size()-1];		// reassign the tail to the first node

								//cout << "head = ";
								//cout << list.head->data << endl;

	node = list->head;
	int N = vect.size();
	for (int i = 0; i < N; i++)
	{
		if (i != (vect.size() - 1))
		{
			//cout << "node is ";
			//cout << node->data << endl;

			node->next = vect[i + 1];

			if (i != 0)
			{
				node->prev = vect[i - 1];
			}
			else
			{
				node->prev = NULL;
			}
			node = node->next;

		}

		else
		{
			//cout << "node is ";
			//cout << node->data << endl;

			//cout << "i = size-1 \n";
			//cout << node->data<<endl;

			node->next = NULL;
			node->prev = vect[i - 1];

		}


		//cout << "head = ";
		//cout << list.head->data << endl;
	}

}

void doubleList::shuffle(doubleList* list)
{
	vector<doubleNode*> vect;				// initialize vector that stores nodes
											//vect.push_back(list.head);
											//cout << vect[0] <<endl;
	doubleNode* node = list->head;

	while (node != NULL)					// this loop stores pointer values from head to tail in order inside the vector
	{
		vect.push_back(node);
		node = node->next;
	}

	node = list->head;
	int N = vect.size();

	for (int i = 0; i <= (N) / 2 - 1; i++)
	{
		//printf("i is %d \n", i);
		if (i < (N) / 2 - 1)
		{
			//printf("i is %d, vect[i] value is %d \n", i, node->data);

			//cout << "node is ";
			//cout << node->data << endl;

			doubleNode *temp = node->next;
			node->next->prev = vect[N / 2 + i + (N % 2)];
			node->next = vect[N / 2 + i + (N % 2)];
			node->next->prev = node;
			node->next->next = temp;
			node = temp;



		}
		else
		{
			//cout << "node is ";
			//cout << node->data << endl;

			//cout << "i = size-1 \n";
			//cout << node->data<<endl;
			if (N % 2 == 0)
			{
				node->next = tail;
				tail->prev = node;
			}
			else
			{
				node->next = tail;
				tail->next = vect[N / 2];
				tail->next->next = NULL;
				tail = tail->next;
				tail->prev = vect[N - 1];
				tail->prev->prev = vect[(N)/2-1];

			}
		}
	}
}