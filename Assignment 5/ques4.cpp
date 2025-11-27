#include <bits/stdc++.h>
using namespace std;
struct Node{int data;Node*next;Node(int x){data=x;next=NULL;}};

Node* reverseList(Node* head){
    Node*prev=NULL,*cur=head,*next;
    while(cur){ next=cur->next; cur->next=prev; prev=cur; cur=next; }
    return prev;
}

int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    Node*r=reverseList(head);
    while(r){ cout<<r->data<<" "; r=r->next; }
}
