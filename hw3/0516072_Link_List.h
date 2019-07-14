#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template < typename T >

struct Int_Node
{
    T value;
    Int_Node *pre, *next;
};
template < typename T >
class Link_List
{
	friend ostream &operator<<(ostream &output, const Link_List<T> &L){
        Int_Node<T> *p;
        for(p=L.head;p!=NULL;p=p->next){
             output << p->value <<" ";
        }
        return output;
    } 	// print all integers in the list
	friend istream &operator>>(istream &input, Link_List<T> &L){
        int n;
        input>>n;
        L.insert_node(n);
        return input;
    }		// input a value at the back of the list, like insert_node(val);

public:
	Link_List( int =10.0){
        Int_Node<T> *node= new Int_Node<T>;
        node->pre = node->next = NULL;
        node->value=10;
        head = tail = node;
        size=1;
	};										// default constructor
	Link_List(const Link_List<T> &L){
        size=L.size;
        int a[size]={0};
        Int_Node<T> *temp=L.head;
        int i=0;
        for(i=0;i<size;i++){
            a[i]=temp->value;
            temp=temp->next;
        }
        head=new Int_Node<T>;
        head->value=a[0];
        head->next=head->pre=NULL;
        tail=head;
        Int_Node<T> *p=head;
        for(i=1;i<size;i++){
            Int_Node<T> *q=new Int_Node<T>;
            q->value=a[i];
            p->next=q;
            q->pre=p;
            p=p->next;
        }
        tail=p;
        tail->next=NULL;
    }					// copy constructor
	~Link_List(){
        Int_Node<T> *p=head;
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
	int getSize() const{
        return size;
    }

	const Link_List &operator=(const Link_List<T> &L){
        size=L.size;
        ///cout<<  size;
        int a[size]={0};
        Int_Node<T> *temp=L.head;
        int i=0;
        for(i=0;i<size;i++){
            a[i]=temp->value;
            temp=temp->next;
        }
        head=new Int_Node<T>;
        head->value=a[0];
        head->next=head->pre=NULL;
        tail=head;
        Int_Node<T> *p=head;
        for(i=1;i<size;i++){
            Int_Node<T> *q=new Int_Node<T>;
            q->value=a[i];
            p->next=q;
            q->pre=p;
            p=p->next;
        }
        tail=p;
        tail->next=NULL;

        return *this;
    }		// assignment operator
	bool operator==(const Link_List<T>  &L) const{
       Int_Node<T> *p=head;
       Int_Node<T> *q=L.head;
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
    }			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

	T &operator[]( T index){
        Int_Node<T> *p=head;
        int i;
        for(i=0;i<index;i++){
            p=p->next;
        }
        return p->value;
    }						// subscript operator for non-const objects
	T operator[](int index) const{
        Int_Node<T> *p=head;
        int i;
        for(i=1;i<index;i++){
            p=p->next;
        }
        return p->value;
    }				// subscript operator for const objects

	bool insert_node(T v){
        if(tail==NULL) return 0;
        Int_Node<T> *node=new Int_Node<T>;
        node->value=v;
        node->pre=tail;
        tail->next=node;
        node->next=NULL;
        tail=node;

        size++;
        return 1;
    }					// insert an integer at the back of link list
	bool delete_node(){
        if(tail==NULL) return 0;
        if(head==tail) delete tail;
        else{
            tail=tail->pre;
            delete tail->next;
            tail->next=NULL;
        }

        size--;
        return 1;
    }								// delete the last node
    bool insert_node(int index, T v){
        if(index>size) return 0;
        Int_Node<T> *node=new Int_Node<T>;
        Int_Node<T> *p=head;

        int i;
        for(i=1;i<index;i++){
            p=p->next;
        }
        node->value=v;
        node->next=p->next;
        p->next=node;

        size++;
        return 1;
    }			// insert an integer after the i_th position
	bool delete_node(int index){
        if(index>size) return 0;
        if(index==size) return this->delete_node();

        if(index==1){
            head=NULL;
            head=head->next;
            delete  head->pre;
        }
        else{
            Int_Node<T> *p=head,*q=head;
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
    }						// delete the i_th node

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};


#endif // LINK_LIST

