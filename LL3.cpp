#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

int findLength(Node* &first)
{
    Node* temp = first;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}

Node* middleElement(Node* &first)
{
    int n = findLength(first);
    int position = n/2+1;

    //ek temporary pointer banaoo jo first node ko point kre aur wo n/2+1 tak pahuch jaye
    
    Node* temp = first;
    while(position!=1)
    {
        position--;
        temp=temp->next;
    }


    return temp; // kyuki temp waha tak pahuch jayega jo middle element hoga

}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    print(first);
    
    cout<<endl;
    int n = findLength(first);
    cout<<"Length of LL : "<<n;

    cout<<endl;

    Node* middleElementofLL = middleElement(first);
    cout<<"middle element is : "<<middleElementofLL->data;

}