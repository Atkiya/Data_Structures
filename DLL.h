#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next,*prev;
    Node(int data){
        this->data=data;
        next=prev=NULL;
    }
};

class DLL{
public:
    Node* head,*tail;
    int len;
    DLL(){
        head=tail=NULL;
        len=0;
    }
    void add(int d){
        Node*n=new Node(d);
        if(isEmpty()==1)head=tail=n;
        else{
            tail->next=n;
            n->prev=tail;
            tail=n;
        }
        len++;
    }
    void addbegin(int d){
        Node* n=new Node(d);
        if(isEmpty()==1)head=tail=n;
        else{
            n->next=head;
            head->prev=n;
            head=n;
        }
        len++;
    }
    void addanypos(int p,int d){
        if(p<0||p>len){
            cout<<"Invalid Input\n";
            return;
        }
        if(p==0)addbegin(d);
        else if(p==len)add(d);
        else{
            Node* n=new Node(d);
            Node* t=head,*t1=NULL;
            for(int i=1;i<p;i++){
                t1=t;
                t=t->next;
            }
            n->next=t;
            n->prev=t1;
            t1->next=n;
            t->prev=n;
            len++;
        }
    }
    bool contains(int d){
        Node* t=head;
        while(t!=NULL){
            if(t->data==d){
                return true;
            }
            t=t->next;
        }
        return false;
    }
    int size(){
        return len;
    }
    int get(int p){
        if(p<0||p>len){
            cout<<"Invalid Input\n";
            return -1;
        }
        Node* t=head;
        for(int i=1;i<p;i++)t=t->next;
        return t->data;
    }
    int indexOf(int d){
        Node* t=head;
        int i=1;
        while(t!=NULL){
            if(t->data==d)return i;
            t=t->next;
            i++;
        }
        return -1;
    }
    void removeFirst(){
        if(isEmpty()==1)return;
        Node*t=head;
        head=head->next;
        if(head!=NULL)head->prev=NULL;
        else tail=NULL;
        delete t;
        len--;
    }
    void removeLast(){
        if(isEmpty()==1)return;
        Node* t=tail;
        tail=tail->prev;
        if(tail!=NULL)tail->next=NULL;
        else head=NULL;
        delete t;
        len--;
    }
    void remove(int p){
        if(p<1||p>len){
            cout<<"Invalid Input\n";
            return;
        }
        if(p==1)removeFirst();
        else if(p==len)removeLast();
        else{
            Node*t=head,*t1=NULL,*t2=NULL;
            for(int i=1;i<p;i++){
                t1=t;
                t=t->next;
            }
            t1->next=t->next;
            t->next->prev=t1;
            delete t;
            len--;
        }
    }
    void reverse(){
        Node* t=head;
        while(t!=NULL){
            Node*t1=t->next;
            t->next=t->prev;
            t->prev=t1;
            t=t1;
        }
        Node*t1=head;
        head=tail;
        tail=t1;
    }
    bool isEmpty(){
        if(len==0)return true;
        return false;
    }
    void sort(){
        if(isEmpty()||len==1)return;
        int swapped;
        Node* t,*t1=NULL;
        do{
            swapped=0;
            t=head;
            while(t->next!=t1){
                if(t->data>t->next->data){
                    int x=t->data;
                    t->data=t->next->data;
                    t->next->data=x;
                    swapped=1;
                }
                t=t->next;
            }
            t1=t;
        }while(swapped);
    }
    void display(){
        Node* t=head;
        while(t!=NULL){
            cout<<t->data<<' ';
            t=t->next;
        }
        cout<<'\n';
    }
    ~DLL(){
        while(!isEmpty()){
            removeFirst();
        }
    }
};
