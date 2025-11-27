#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data=x; next=nullptr; }
};

class LinkedList {
    Node* head;
public:
    LinkedList(){ head=nullptr; }

    void insertBegin(int x){
        Node* n=new Node(x);
        n->next=head; head=n;
    }

    void insertEnd(int x){
        Node* n=new Node(x);
        if(!head){ head=n; return; }
        Node* t=head; while(t->next) t=t->next;
        t->next=n;
    }

    void insertBefore(int val,int key){
        if(!head){ cout<<"List empty\n"; return; }
        if(head->data==key){ insertBegin(val); return; }
        Node* t=head;
        while(t->next && t->next->data!=key) t=t->next;
        if(!t->next){ cout<<"Key not found\n"; return; }
        Node* n=new Node(val);
        n->next=t->next; t->next=n;
    }

    void insertAfter(int val,int key){
        Node* t=head;
        while(t && t->data!=key) t=t->next;
        if(!t){ cout<<"Key not found\n"; return; }
        Node* n=new Node(val);
        n->next=t->next; t->next=n;
    }

    void deleteBegin(){
        if(!head){ cout<<"List empty\n"; return; }
        Node* t=head; head=head->next; delete t;
    }

    void deleteEnd(){
        if(!head){ cout<<"List empty\n"; return; }
        if(!head->next){ delete head; head=nullptr; return; }
        Node* t=head;
        while(t->next->next) t=t->next;
        delete t->next; t->next=nullptr;
    }

    void deleteSpecific(int key){
        if(!head){ cout<<"List empty\n"; return; }
        if(head->data==key){ deleteBegin(); return; }
        Node* t=head;
        while(t->next && t->next->data!=key) t=t->next;
        if(!t->next){ cout<<"Key not found\n"; return; }
        Node* del=t->next;
        t->next=del->next;
        delete del;
    }

    void search(int key){
        Node* t=head; int pos=1;
        while(t){ if(t->data==key){ cout<<"Found at position "<<pos<<"\n"; return; } t=t->next; pos++; }
        cout<<"Not found\n";
    }

    void display(){
        if(!head){ cout<<"List empty\n"; return; }
        Node* t=head;
        cout<<"List: ";
        while(t){ cout<<t->data<<" "; t=t->next; }
        cout<<"\n";
    }
};

int main(){
    LinkedList l;
    int ch,val,key;
    while(true){
        cout<<"\n1.InsBeg 2.InsEnd 3.InsBefore 4.InsAfter 5.DelBeg 6.DelEnd 7.DelSpecific 8.Search 9.Display 10.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Val: ";cin>>val; l.insertBegin(val); break;
            case 2: cout<<"Val: ";cin>>val; l.insertEnd(val); break;
            case 3: cout<<"Val,Key: ";cin>>val>>key; l.insertBefore(val,key); break;
            case 4: cout<<"Val,Key: ";cin>>val>>key; l.insertAfter(val,key); break;
            case 5: l.deleteBegin(); break;
            case 6: l.deleteEnd(); break;
            case 7: cout<<"Key: ";cin>>key; l.deleteSpecific(key); break;
            case 8: cout<<"Key: ";cin>>key; l.search(key); break;
            case 9: l.display(); break;
            case 10: return 0;
            default: cout<<"Invalid\n";
        }
    }
}
