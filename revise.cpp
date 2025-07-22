/*#include<iostream>
using namespace std;
class Node
{
    public:
    int data; 
    Node* next;

    // Node()
    // {
    //     this->data=0;
    //     this->next=NULL;
    // } 
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};
void print(Node* &first)
{
    Node* temp=first;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";  
        temp=temp->next;
    }
}
int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    cout<<"printing linkedlist\n";
    print(first);




}*/


#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        int data=0;
        Node* next=NULL;
    }

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    
};

// i want to insert a node right at the head of linked list

void insertAtHead(Node* &head,Node* &tail,int data)   // by reference pass hua h kyuki original linked list me change krna chahta hu 
{
    // step 1 :  create new node 
    Node* newNode = new Node(data);

    //step 2 :

    newNode->next=head;
    
    //first node h too 
    if(head==NULL)         // iska mtlab ll empty tha to first node ab add hoga
    {
        tail=newNode;        //tail ko update kr doo
    }

    //step 3

    head = newNode;


}

// insert a node at right of node of linked list 
void insertAtTail(Node* &head,Node* &tail,int data)
{
    // step 1 : create a node

    Node* newNode = new Node(data);

    // step 2 : connect with tail node

    if(tail==NULL)
    {
        //       first node a add hone wali h

        tail=newNode;
        head=newNode;
    }
    else
    {
          tail->next = newNode;
    }
  

    //step 3 : update tail
    tail=newNode;



}

// printing linkedlist data
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



int main()
{
    Node* head = NULL;
    Node* tail =NULL;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,90);
    //    insertAtTail(head,tail,100);
    //     insertAtTail(head,tail,200);
    //      insertAtTail(head,tail,300);




    print(head);

    return 0;


}