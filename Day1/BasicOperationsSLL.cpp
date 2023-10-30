/******************************************************************************

                Implement Single LinkedList Basic Operations using class

       Insertion
       Deletion
       Display
       Reverse
       Find Length 

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
    void find(int d);
    void findRecursive(int d)
    {
        findR(head,d);
    }
    void findR(Node *head,int d);
    int length();
    int lengthRecursive()
    {
        return lengthR(head);
    }
    int lengthR(Node *head);
    void reverse();
    
    void deleteatPos(int pos);
    void deleteElement(int d);
    void deleteList();
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
    if(temp==NULL)
    {
        cout<<"List is empty";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void LinkedList::find(int d)
{
    Node * temp = head;
    while(temp->data != d)
        temp = temp->next;
    if(temp->data = d)
        cout<<"YES"<<" ";
    else cout<<"NO"<<" ";
}
void LinkedList::findR(Node *head,int d)
{
    
    if(head == NULL)
    {
        cout<<"NO"<<" ";
        return;
    }
    if(head->data == d)
    {
        cout<<"YES"<<" ";
        return;
    }   
    LinkedList::findR(head->next,d);
}
int LinkedList::length()
{
    Node * temp = head;
    int cnt = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        ++cnt;
    }
    return cnt;
}
int LinkedList::lengthR(Node *head)
{
    
    if(head == NULL)
        return 0;
      
    return 1 + LinkedList::lengthR(head->next);
}
void LinkedList::reverse()
{
    Node * prev,*curr,*next;
    curr = head;
    prev = next = NULL;
    

    while(curr!=NULL)
    {
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next;
    }
    head = prev;
    
}
void LinkedList::deleteElement(int d)
{
    Node * temp = head;
    Node * prev = NULL;
    
    while(temp->data!=d)
        {
            prev = temp;
            temp = temp->next;}
    
    
    prev->next = temp->next;
    
    free(temp);
    
}
void LinkedList::deleteatPos(int pos)
{
    Node * temp = head;
    Node * prev = NULL;
    int p = pos;
    
    while(--pos)
        {
            prev = temp;
            temp = temp->next;}
    
    
    prev->next = temp->next;
    
    free(temp);
    
}
void LinkedList::deleteList()
{
    Node * temp = head;
    Node * next = NULL;
        
    while(temp!=NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
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
    list.find(5);
    list.findRecursive(11);
    cout<<list.length()<<" ";
    cout<<list.lengthRecursive();
    list.reverse();
    
    list.display();
    
    cout<<"delete 1";
    list.deleteElement(1);
    
    list.display();
    cout<<"delete at position 3";
    list.deleteatPos(3);
    
    list.display();
    cout<<"deleting List"<<endl;
    list.deleteList();
    list.display(); 

    return 0;
}
