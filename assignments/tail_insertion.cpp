/**
* @ProgramName: Tail Insertion
* @Author: Cory Press
* @Description:
*     This program allows users to create a list and either insert values at the front
*	  or the end of the current list, as well as print out the list.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 10 02 2017
*/


#include <iostream>

struct Node{
	int Data;
	Node *Next;
};

using namespace std;

class List
{
private:
	Node *Head;
	Node *Tail;
public:
	List()

	{
		Head = NULL;
		Tail = NULL;
	}

	void FrontSert(int x)
	{
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (!Head)
		{
			Tail = Temp;
		}

		else
		{
			Temp->Next = Head;
		}

		Head = Temp;

	}


	/**
	* @FunctionName: EndSert
	* @Description:
	*     inserts at integer value at the end of the list
	* @Params:
	*    int x - the value to be inserted at the end of the list
	* @Returns:
	*    void
	*/
	
	void EndSert(int x)
	{
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (!Head)
		{
			Head = Temp;
			Tail = Temp;
		}
		else
		{
			Tail->Next = Temp;
		}

		Tail = Temp;
	}

	void PrintList()
	{
		if (!Head)
		{
			cout << "Empty" << endl;
			return;
		}
		else
		{
			Node *Temp = Head;
			while (Temp != NULL)
			{
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
		}
		system("pause");
	}

};


int main() {
	srand(97097807);
	List L;
	for (int i = 0; i<10; i++)
	{
		L.FrontSert(rand() % 100);
	}
	L.EndSert(8);
	L.FrontSert(3);
	L.EndSert(12);
	L.EndSert(71);

	L.PrintList();
	return 0;
}