#include<iostream>
#include<string>
#include "0516072_Link_List.h"

using namespace std;


ostream &operator<<(ostream &output, const Link_List &L){
    Int_Node *p;
    for(p=L.head;p!=NULL;p=p->next){
         output << p->value <<" ";
    }
    return output;
}

istream &operator>>(istream &input, Link_List &L){
    int n;
    input>>n;
    L.insert_node(n);
    return input;
}

Link_List::Link_List(const Link_List &L) {
    size=L.size;
    int a[size]={0};
    Int_Node *temp=L.head;
    int i=0;
    for(i=0;i<size;i++){
        a[i]=temp->value;
        temp=temp->next;
    }
    head=new Int_Node;
    head->value=a[0];
    head->next=head->pre=NULL;
    tail=head;
    Int_Node *p=head;
    for(i=1;i<size;i++){
        Int_Node *q=new Int_Node;
        q->value=a[i];
        p->next=q;
        q->pre=p;
        p=p->next;
    }
    tail=p;
    tail->next=NULL;

    /**Int_Node *p=L.head;
    Int_Node *node=new Int_Node;

    node->value =p->value;
    node->pre=p->pre;
    node->next=p->next;
    head=tail=node;
    p=p->next;

    while(p!=NULL){
        node=new Int_Node;
        node->pre=tail;
        tail->next=node;
        tail=tail->next;
        p=p->next;
    }
    size= L.getSize();
    */
}

Link_List::~Link_List(){
    Int_Node *p=head;
    if(size==1){
        delete p;
    }
    else{
        for(;p->next!=NULL;p=p->next){
            delete p->pre;
        }
        delete p;
    }
    size=0;
}

int Link_List::getSize() const{
    return size;
}

const Link_List &Link_List::operator=(const Link_List &L){
    size=L.size;
    ///cout<<  size;
    int a[size]={0};
    Int_Node *temp=L.head;
    int i=0;
    for(i=0;i<size;i++){
        a[i]=temp->value;
        temp=temp->next;
    }
    head=new Int_Node;
    head->value=a[0];
    head->next=head->pre=NULL;
    tail=head;
    Int_Node *p=head;
    for(i=1;i<size;i++){
        Int_Node *q=new Int_Node;
        q->value=a[i];
        p->next=q;
        q->pre=p;
        p=p->next;
    }
    tail=p;
    tail->next=NULL;

    return *this;
}

bool Link_List::operator==(const Link_List &L) const{
   Int_Node *p=head;
   Int_Node *q=L.head;
   while(p->next!=NULL){
    if(p->value!=q->value)
        return 0;
        p=p->next;
        q=q->next;
   }
   if(q->next==NULL){
        return 1;
   }
   else {
    return 0;
   }
}

int &Link_List::operator[](int index){
    Int_Node *p=head;
    int i;
    for(i=0;i<index;i++){
        p=p->next;
    }
    return p->value;
}
int Link_List::operator[](int index) const {
    Int_Node *p=head;
    int i;
    for(i=1;i<index;i++){
        p=p->next;
    }
    return p->value;
}
bool Link_List::insert_node(int v){
    if(tail==NULL) return 0;
    Int_Node *node=new Int_Node;
    node->value=v;
    node->pre=tail;
    tail->next=node;
    node->next=NULL;
    tail=node;

    size++;
    return 1;
}
bool Link_List::delete_node(){
    if(tail==NULL) return 0;
    if(head==tail) delete tail;
    else{
        tail=tail->pre;
        delete tail->next;
        tail->next=NULL;
    }

    size--;
    return 1;
}

bool Link_List::insert_node(int index, int v){
    if(index>size) return 0;
    Int_Node *node=new Int_Node;
    Int_Node *p=head;

    int i;
    for(i=1;i<index;i++){
        p=p->next;
    }
    node->value=v;
    node->next=p->next;
    p->next=node;

    size++;
    return 1;
}
bool Link_List::delete_node(int index){
    if(index>size) return 0;
    if(index==size) return this->delete_node();

    if(index==1){
        head=NULL;
        head=head->next;
        delete  head->pre;
    }
    else{
        Int_Node *p=head,*q=head;
        int i ;
        for(i=1;i<index;i++){
            p=p->next;
        }
        for(i=1;i<index-1;i++){
            q=q->next;
        }
        q->next=p->next;
        p->next->pre=q;
        delete p;
    }
    size--;
    return 1;
}


