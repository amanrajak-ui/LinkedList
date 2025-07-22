
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
        this->next=NULL;
    }

    ~Node()
    {
        cout<<"Destructor called for node with data: "<<this->data<<endl;

    }

    
};

// i want to insert a node left at the head of linked list

void insertAtHead(Node* &head,Node* &tail,int data)   // by reference pass hua h kyuki original linked list me change krna chahta hu 
{

    // check for empty linked list
    if(head==NULL)
    {
        // agar head null mean ll empty h too ek new node krne h
        Node* newNode = new Node(data);
        head=newNode;  // ab new node ko hii head man lo aur tail man lo aur return kr doo
        tail=newNode;
        return;

    }
    // step 1 :  create new node 
    Node* newNode = new Node(data);

    //step 2 :

    newNode->next=head;

    //step 3

    head = newNode;


}

// insert a node at right of node of linked list 
void insertAtTail(Node* &head,Node* &tail,int data)
{
      if(head==NULL)
    {
        // agar head null mean ll empty h too ek new node krne h
        Node* newNode = new Node(data);
        head=newNode;  // ab new node ko hii head man lo aur tail man lo aur return kr doo
        tail=newNode;
        return;
        
    }
    // step 1 : create a node

    Node* newNode = new Node(data);

    // step 2 : connect with tail node

    tail->next = newNode;

    //step 3 : update tail
    tail=newNode;



}

// find length
int findLength(Node* &head)
{
    int len =0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

// insert at any position in linked list
void insertAtPosition(Node* &head,Node* &tail,int position,int data) // position bata raha hai ki kis position pe data dalna hai
{
    
    //edge case :

    // 0th position pe insert krne ka mtlb h insert at head
    if(position==0)
    {
        insertAtHead(head,tail,data);
        return;
    }

    //agar mujhe l ke last me dalna h element tooo vb tail me insert krna h too
    int len = findLength(head); 
    if(position>=len)
    {
        insertAtTail(head,tail,data);
        return;
    }
    
    //step 1 : is linkedlist is empty if empty then
    if(head==NULL)
    {
        // 1: create newnode
        Node* newNode = new Node(data);
        // newnode pe hii head or tail dono point krega
        head=newNode;
        tail=newNode;
    }
    else
    {
        //step1 : find the position : prev and current pointer
        int i=1;
        Node* prev =head;
        while(i<position)
        {
            prev = prev->next;
            i++;
        }
        Node* curr = prev->next;

        // step 2 : node creation
        Node* newNode = new Node(data);

        // step 3 :
        newNode->next=curr;
        prev->next=newNode;




    }

}

//deleting nodes 
void deleteNode(Node* &head,Node* &tail,int position)
{
    // case 1 : linkedlist hii empty;
    if(head==NULL)
    {
        cout<<"can not delete coz ll is empty";
        return;
    }
    // delete from head
    if(position==1)
    {
        // mean first node ko delete krna hai
        Node* temp = head;
        head= temp->next;
        temp->next=NULL;
        delete temp;
    }

}

// printing linkedlist data
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
}
// reverse ka code
Node* reverse(Node* &head)
{
    Node* prev=NULL;
    Node* curr = head;
    while(curr!=NULL)
    {
        Node* nextNode = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }

    head=prev;

    return head;
}
// add 1 to a linked list
void addOne(Node* &head)
{
    // phele reverse kr dunga
    head=reverse(head);


    //add kr dunga
    Node* temp=head;
    int carry=1;
    while(temp->next!=NULL)
    {
        int totalSum=temp->data + carry;
        int digit = totalSum %10;
        carry = totalSum/10;

        temp->data=digit;
        temp=temp->next;

        if(carry== 0)
        {
            break;
        }
    }    
       if(carry!=0)
        {
            int totalSum = temp->data + carry;
            int digit = totalSum % 10;
            carry=totalSum/10;

            temp->data=digit;

            if(carry !=0)
            {
                Node* newNode = new Node(carry);
                temp->next=newNode;

            }
            
        }

        // fir reverse kr dunga 

        head = reverse(head);





}


//                                                          lletcode 25






int main()
{
    Node* head = NULL;
    Node* tail =NULL;
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,1);
    // insertAtHead(head,tail,50);
    // insertAtTail(head,tail,10);               
    // insertAtTail(head,tail,5);
    // insertAtTail(head,tail,4);
    // insertAtTail(head,tail,3);
    // insertAtTail(head,tail,2);


//insertAtPosition(head,tail,5,1);

  // print(head);

   //deleteNode(head,tail,1);
 

    cout<<" linked list : "<<endl;
    print(head);
    
    cout<<endl;
    // cout<<"reverse linkedlist : "<<endl;
    // reverse(head);
    // print(head);
     
    cout<<"after adding 1 : "<<endl;
    addOne(head);

    print(head);

    return 0;


}