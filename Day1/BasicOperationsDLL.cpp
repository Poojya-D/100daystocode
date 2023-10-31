/******************************************************************************

                              Reverse and Insertion in Double Linked List

*******************************************************************************/

#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node *prev,*next;
    Node(int d)
    {
        this->data = d;
        this->prev = this->next = NULL;
    }
};

class DoubleLinkedList
{
  public:
  Node *head;
  DoubleLinkedList()
  {
      this->head = NULL;
  }
  void inseratFront(int d);
  void inseratPos(int pos,int d);
  void reverse();
  void display();
};

void DoubleLinkedList::inseratFront(int d)
{
    Node *newNode = new Node(d);
    if(head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void DoubleLinkedList::inseratPos(int pos,int d)
{
    Node *newNode = new Node(d);
    int p = pos-1;
    if(head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while(--p)
            temp = temp->next;
        
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}
void DoubleLinkedList::reverse()
{
    Node *temp = NULL;
    Node *curr = head;
    while(curr!=NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    head = temp->prev;
}
void DoubleLinkedList::display()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<head<<endl;
}

int main()
{
    DoubleLinkedList dlist;
    dlist.inseratFront(5);
    dlist.inseratFront(4);
    dlist.inseratFront(3);
    dlist.inseratFront(2);
    dlist.inseratFront(1);
    dlist.display();
    cout<<"reverse"<<endl;
    dlist.reverse();
    dlist.display();
    cout<<"insertion"<<endl;
    dlist.inseratPos(4,6);
    dlist.inseratPos(2,8);
    dlist.display();
    cout<<"reverse two "<<endl;
    dlist.reverse();
    dlist.display();
    

    return 0;
}
