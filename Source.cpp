#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};

class LinkedList
{
public:
	//Constructor
	LinkedList() 
	{ 
		head = NULL;
	}
	//Destructor
	~LinkedList() 
	{
	}; 
	void addNode(int value);
	void reverseList();
	void display();

	Node* head;
};

// function to add node to a list
void LinkedList::addNode(int value) 
{
	Node* newnode = new Node();
	newnode->data = value;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
	}
	else 
	{
		Node* temp = head; // head is not NULL
		while (temp->next != NULL) 
		{
			temp = temp->next; // go to end of list
		}
		temp->next = newnode; // linking to newnode
	}
	
}

// reverse Linked List
void LinkedList::reverseList()
{
	Node* temp = head;
	Node* nextnode = NULL;
	Node* revnode = NULL;
	while (temp != NULL) 
	{
		head = temp;
		nextnode = temp->next;
		temp->next = revnode;
		revnode = temp;
		temp = nextnode;
	}
}
//to display Linked List
void LinkedList::display()
{
	if (head == NULL) 
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		Node* temp = head;
		while (temp != NULL) 
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

}
int main()
 {
	int a;
	LinkedList* list = new LinkedList();
	cout << "Enter ten integers  into linked list: ";
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		list->addNode(a);
	}
	system("pause");
	system("CLS");
	cout << "Current Linked List\n";
	list->display();
	list->reverseList();
	cout << "Reversed Linked List\n";
	list->display();
	delete list;
	system("pause");
	return 0;
}
