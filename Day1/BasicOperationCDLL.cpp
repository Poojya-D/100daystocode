/******************************************************************************

                             Basic Operations insertion and deletion Circular Double Linked List 
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

class CircularDoubleLinkedList
{
    public:
    Node* head;
    void insertatFront(int d);
    void insertatEnd(int d);
    void insertatPos(int pos,int d);
    void deleteElement(int d);
    void display();
    CircularDoubleLinkedList()
    {
        this->head = NULL;
    }
};

void CircularDoubleLinkedList::insertatFront(int d)
{
    Node *newNode = new Node(d);
    if(head == NULL)
    {
        newNode->prev = newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next!=head)
            temp=temp->next;
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        temp->next = head;
    }
}
void CircularDoubleLinkedList::insertatPos(int pos,int d)
{
    int p = pos - 1;
    Node *newNode = new Node(d);
    Node *temp = head;
    while(--p)
        temp = temp->next;
        
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    
}
void CircularDoubleLinkedList::deleteElement(int d)
{
    Node *temp = head;
    while(temp->data != d)
        temp = temp->next;
    //100 200  300    
   // 1   2    3
    //p n p n p n
    //p 200 100 300 200 next
    //p 300  100 n
    temp->prev->next = temp->next;
    temp->next->prev = temp->next;
    
    free(temp);
        
    
    
}

void CircularDoubleLinkedList::display()
{
    Node *temp = head;
    
    
    do{
        cout<<temp->data<<" ";
        temp= temp->next;
    }while(temp!=head);
}
int main()
{
    CircularDoubleLinkedList list;
    list.insertatFront(1);
    list.insertatFront(2);
    list.insertatFront(3);
    list.insertatFront(4);
    list.insertatFront(5);
    //list.display();
    list.insertatPos(3,8);
    list.deleteElement(4);
    
    list.display();
    

    return 0;
}
