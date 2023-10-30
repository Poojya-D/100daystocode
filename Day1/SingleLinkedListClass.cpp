/******************************************************************************

                Implement Single LinkedList insertion using class
*******************************************************************************/

#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
class LinkedList
{
    Node * head;
    public:
    void insertatFront(int d);
    void insertatPos(int d,int pos);
    void insertatEnd(int d);
    void display();
    LinkedList()
    {
        this->head = nullptr;
    }
};

void LinkedList::insertatFront(int d)
{
    Node *newNode = new Node(d);
    if(head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void LinkedList::insertatPos(int d,int pos)
{
    int p = pos-1;
    Node *newNode = new Node(d);
    if(head == NULL)
        head = newNode;
    else
    {
        Node * temp = head;
        while(--p)
            temp = temp->next;
            
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void LinkedList::insertatEnd(int d)
{
    Node *newNode = new Node(d);
    if(head == NULL)
        head = newNode;
    else
    {
        Node * temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
            
        temp->next = newNode;
    }
}
void LinkedList::display()
{
    
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main()
{
    LinkedList list;
    list.insertatFront(1);
    list.insertatFront(2);
    list.insertatFront(3);
    list.insertatFront(4);
    list.insertatEnd(5);
    list.insertatEnd(6);
    list.insertatEnd(7);
    list.insertatFront(8);
    list.insertatPos(9,5);
    list.insertatPos(10,3);
    list.display();

    return 0;
}
