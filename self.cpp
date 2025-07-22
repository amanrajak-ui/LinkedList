#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this->data=0;
        this->next=NULL;
    }

    Node(int data)
    {
        this->data=data;
        this->next= NULL;   

    }

    ~Node()
    {
        cout<<"data is deleted : "<<this->data;
    }
};

//insert at front
void insertatHead(Node* &head ,Node* &tail, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head= newNode;
        tail=newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        newNode->next=head;
        head= newNode;
    }
}
void insertatTail(Node* &head ,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next=newNode;
        tail=newNode;

    }
}

int findLength(Node* &head)
{
    Node* temp = head;
    int len=0;
    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtposition(Node* &head,Node* &tail,int position , int data)
{
    if(position==0)
    {
        insertatHead(head,tail,data);
        return ;
    }

    int len = findLength(head);
    if(position>=len)
    {
        insertatTail(head,tail,data);
        return ;
    }

    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }
    else
    {
        Node* previous = head;
        int i=1;
        while(i<position)
        {
            previous=previous->next;
            i++;
        }
        Node* current=previous->next;

        Node* newNode = new Node(data);
        newNode->next=current;
        previous->next=newNode;
    }
}
// delete code from head tail andfrom any position 
void deleteNode(Node* &head,Node* &tail,int position)
{
    // case 1 : linkedlist hii empty;
    if(head==NULL)
    {
        cout<<"can not delete coz ll is empty";
        return;
    }

    // agar ll me ek hii element h aur use delete kr rahe h too head aur tail too usii
    // ko point kr raha hai in this case tail ko handle nhi kr payenge
    if(head==tail) 
    {
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return; 

    }

    // delete from head
    int len = findLength(head);
    if(position==1)
    {
        // mean first node ko delete krna hai
        Node* temp = head;
        head= head->next;
        temp->next=NULL;
        delete temp;
    }
    else if(position==len)
    {
        // last ode ko delete kr doo
        // step 1 : find previous
        Node* prev = head;
        while(prev->next!=tail) //jb tak prev ke aage wala node tail naa hoo aage badh tee rahoo
        {
            prev = prev->next;
        }
        //step 2: prev node ka link ko null kro
        prev->next=NULL;

        //tail delete kro
        delete tail;

        //update tail

        tail=prev;


         

    }
    else
    {
        // middle me koi node ko delete krna hai

        //step1 : traverse linked list and find/set prev and curr or curr usko point krega jisko delete krna hai
       Node* prev = NULL;
       Node* curr =head;
       while(position != 1)
       {
        position--;
        prev=curr;
        curr=curr->next;
       }
        
        //step 2 : prev->next me curr ka next node ko add kro
        prev->next = curr->next;

        // step 3 : node ko null kr do 
        curr->next=NULL;
        // step 4 : delete node;
        delete curr;


    }

}
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}
int main()
{
    Node* head=NULL;
    Node* tail = NULL;
    insertatHead(head,tail,50);
    insertatHead(head,tail,40);
     insertatHead(head,tail,30);
    // insertatHead(head,tail,20);   
    // insertatHead(head,tail,10);
    // insertatTail(head,tail,12);
    // insertatTail(head,tail,13);

    // insertAtposition(head,tail,0,1);

    print(head);

    cout<<endl;

  //  cout<<"before tail "<<tail->data<<endl;

    deleteNode(head,tail,1);

    cout<<endl;

   //  cout<<" after tail "<<tail->data<<endl;


    print(head);




}