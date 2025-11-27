#include <bits/stdc++.h>
using namespace std;
struct Node{int data;Node*next;Node(int x){data=x;next=NULL;}};

void countDelete(Node*&head,int key){
    int cnt=0; Node*cur=head,*prev=nullptr;
    while(cur){
        if(cur->data==key){
            cnt++;
            if(prev) prev->next=cur->next;
            else head=cur->next;
            Node*tmp=cur; cur=cur->next; delete tmp;
        }else{ prev=cur; cur=cur->next; }
    }
    cout<<"Count: "<<cnt<<"\nUpdated list: ";
    cur=head; while(cur){cout<<cur->data<<" ";cur=cur->next;}
}

int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(1);
    head->next->next->next=new Node(2);
    head->next->next->next->next=new Node(1);
    head->next->next->next->next->next=new Node(3);
    head->next->next->next->next->next->next=new Node(1);
    countDelete(head,1);
}
