#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last = new Node;

    // write head ka node explicitly as it will be used a bit differently
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last=Head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct Node *h)
{
    do
    {
        cout << h->data << endl;
        h = h->next;
    }while(h!=Head);
}

int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void insert(struct Node *p,int pos,int x){
    struct  Node *t;
    if(pos<0 || pos>Length(p)){
        return;
    }
    if(pos==0){
        t=new Node;
        t->data=x;
    if(Head==NULL){
        Head=t;
        Head->next=Head;
    }else{
        while(p->next!=Head){
          p=p->next; 
        }
        p->next=t;
        t->next=Head;
        Head=t;
    }
    }else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
    
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int x;
    if(index<0 || index>Length(Head)){
        return -1;
    }
    if(index==1){
        while(p->next!=Head){
            p=p->next;
        }
        x=Head->data;
        if(Head==p){
            delete(Head);
            Head=NULL;
        }else{
            p->next=Head->next;
            delete(Head);
            Head=p->next;
        }
    }else{
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete(q);
    }
    return x;
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    display(Head);
    cout<<"\n";
    insert(Head,0,10);
    display(Head);
    cout<<"\n";
    Delete(Head,-2);
    display(Head);
    return 0;
}