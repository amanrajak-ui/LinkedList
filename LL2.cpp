//                ================== ================ Doubly linked lst ============================ ==================
#include<iostream>
using namespace std;

//      ================================================= Node creation =====================================================
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        this->prev=NULL;
        this->next=NULL;

    }
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;  
    }

    ~Node()
    {
        cout<<"data deleted : "<<this->data;
    }

};

// ====================================================  printing linked list ======================================================
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

// ===============================================================find length of linked list============================================
int  findLength(Node* &head)
{
    Node* temp = head;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }

    return len;
}

// ==================================================== mujhe head pe insert karna hai ==============================================
void insertAtHead(Node* &head,Node* &tail,int data)
{

    // case 1 :  linkedlist is empty
    if(head==NULL)
    {
         Node* newNode = new Node(data);
         head=newNode;
         tail=newNode;

    }
    else
    {
        // case 2 : linked list is non empty 
        Node* newNode = new Node(data);
        head->prev=newNode;
        newNode->next=head;
        head=newNode;

    }




}

// ========================================= insert at tail =================================================
void insertAtTail(Node* &head,Node* &tail,int data)
{
    //case 1: ll is empty in this case newnode create kro aur usse pe head and tail point krega
    if(head==NULL)
    {
        Node* newNode =new Node(data);
        head=newNode;
        tail=newNode;
    }
    else                       //case 2 : ll is non empty 
    {     
        Node* newNode = new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;            

    }
    
}

// =====================================insert at any position =====================================================
void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    //case 1 :ll is empty
    if(head==NULL)
    {
        //create a new node with data
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;

    } 
    // case 2 : ll is non empty
    int length = findLength(head);
    if(position<=1)                         //position 1 ka mtlab head me lagana hai node 
    {
        insertAtHead(head,tail,data);
    }
    else if(position>length)                // position is greater than length mean node ko tail me lagana hai
    {
        insertAtTail(head,tail,data);
    }
    else
    {                                       // node kahi pr v laga hoo tb
        //1. create new node
        Node* newNode = new Node(data);
        //2. find prev ao curr node
        Node* previous=NULL;
        Node* current=head;                    // curr point krega us place ko jis position pe data dalna hai
        while(position!=1)
        {
            previous=current;
            current=current->next;
            position--;
        }
        //3.
        previous->next=newNode;
        newNode->prev=previous;
        newNode->next=current;
        current->prev=newNode;
        

    }
}

// ========================================  delete nodes from head ,tail and any position=============================================
void deleteNode(Node* &head,Node* &tail,int position)
{
     // phele length nikal lo last se delete krne me len ka need h
     int length = findLength(head);

    // case 1 : ll is empty
    if(head==NULL)
    {
        cout<<"can not delete bcz ll is empty";
        return;
    }

    if(head==tail)
    {
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    
    if(position==1)  // mean head wala  data delete kro 
    {
        Node* temp = head;
        head=head->next;  // head ko sift kro kyuki head ko delete krna h naa
        temp->next=NULL;
        head->prev=NULL;
        delete temp;      // hmne dynamically constructor banaya h too delete keyword use kr ke data ko delete krenge joki destructor ko call krega



    }
    else if(position==length)  //   tail wal data delete krna hai
    {
        // ek temporay pointer banayenge jo ki sbse phele head ko point krega
        // Node* previousNode = head;
        // while(previousNode!=tail)
        // {
        //     previousNode=previousNode->next;
        // }

        Node* previousNode = tail->prev;

        previousNode->next=NULL;
        tail->prev=NULL;
        delete tail;      // phele tail ko delete kro tb tail update kro previous node pe le jaoo aur  iis sequence ko hii follow kro
        tail=previousNode; 

    }
    else                           // delete from in  middle 
    {
        Node* previousNode = NULL;
        Node* currentNode =  head;
        while(position!=1)
        {
            previousNode=currentNode;     // prev aur curr ko badate raho jb tak sahi pos pe na paunch jaye
            currentNode=currentNode->next;
            position--;
        }
        Node* nextNode=currentNode->next;
        previousNode->next=nextNode;
        currentNode->prev=NULL;
        currentNode->next=NULL;
        nextNode->prev=previousNode;
        delete currentNode;

    }


}
int main()   
{
   // Node* head = new Node(10); 
   Node* head = NULL;
   Node* tail = NULL;

   // insertAtHead(head,tail,40);
  //  insertAtHead(head,tail,30);
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);

    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    // insertAtTail(head,tail,70);
    // insertAtTail(head,tail,80);

   // insertAtPosition(head,tail,2,5);
    



    cout<<"My  LinkedList"<<endl;
    print(head);

    cout<<endl;

    deleteNode(head,tail,3);

    cout<<endl;
    
    cout<<"doubly linked list after deletion \n";
    print(head);


    cout<<endl;




    int length = findLength(head);
    cout<<"length of linked list is : "<<length;

}