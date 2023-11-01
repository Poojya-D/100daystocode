/******************************************************************************

              Basic operations inseration and deletion Circular Linked List

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

class CircularLinkedList
{
    public:
    Node* head;
    void insertatFront(int d);
    void insertatEnd(int d);
    void insertatPos(int pos,int d);
    void deleteElement(int d);
    void display();
    CircularLinkedList()
    {
        this->head = NULL;
    }
};

void CircularLinkedList::insertatFront(int d)
{
    Node *newNode = new Node(d);
    if(head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next!=head)
            temp=temp->next;
        
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
}
void CircularLinkedList::insertatPos(int pos,int d)
{
    int p = pos - 1;
    Node *newNode = new Node(d);
    Node *temp = head;
    while(--p)
        temp = temp->next;
        
    newNode->next = temp->next;
    temp->next = newNode;
    
}
void CircularLinkedList::deleteElement(int d)
{
    Node *temp = head;
    Node *prev = NULL;
    while(temp->data != d)
    {
        prev = temp;
        temp=temp->next;
    }
    prev->next = temp->next;
    free(temp);
}
void CircularLinkedList::display()
{
    Node *temp = head;
    
    
    do{
        cout<<temp->data<<" ";
        temp= temp->next;
    }while(temp!=head);
    cout<<endl;
}
int main()
{
    CircularLinkedList list;
    list.insertatFront(1);
    list.insertatFront(2);
    list.insertatFront(3);
    list.insertatFront(4);
    list.insertatFront(5);
    list.insertatPos(3,8);
    
    list.display();
    list.deleteElement(3);
    list.display();

    return 0;
}
