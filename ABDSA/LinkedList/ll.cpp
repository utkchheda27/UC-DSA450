#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *second,*third = NULL;  // global pointer
struct Node *last = NULL;

void create2(int B[], int n)
{
    int i;
    struct Node *t = new Node;

    // write first ka node explicitly as it will be used a bit differently
   second = new Node;
   second->data = B[0];
   second->next = NULL;

    last =second;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t = new Node;

    // write first ka node explicitly as it will be used a bit differently
    first = new Node;
    first->data = A[0];
    first->next = NULL;

    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *head)
{
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

void Rdisplay(struct Node *head)
{
    if (head != NULL)
    {
        cout << head->data << endl;
        Rdisplay(head->next);
    }
}

int count(struct Node *t)
{
    int c = 0;
    while (t)
    {
        c++;
        t = t->next;
    }
    return c;
}
int Rcount(struct Node *t)
{
    int c = 0;
    if (t == 0)
    {
        return 0;
    }
    else
    {
        return Rcount(t->next) + 1;
    }
}

int sum(struct Node *p)
{
    int add = 0;
    while (p)
    {
        add = add + p->data;
        p = p->next;
    }
    return add;
}

int maxLL(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

bool LSearch(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            return true;
        }
        else
        {
            p = p->next;
        }
    }
    return false;
}

Node *improvedSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insertLast(int x)
{
    struct Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void insertSorted(struct Node *p, int x)
{
    struct Node *q = new Node;
    q = NULL;
    p = first;
    struct Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (x > (p->data) && p)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

bool isSorted(struct Node *p){
    int x=INT_MIN;
    p=first;
    while (p)
    {
        if(x<p->data){
            x=p->data;
            p=p->next;
        }else{
            return false;
        }
    }
    return true;
    
}

int Delete(struct Node *p,int pos){
    if(pos<1 || pos>count(p)){
        return -1;
    }
    struct Node *q;
    int x=-1;
    if(pos==1){
    x=first->data;
    p=first;
    first=first->next;
    delete p;
    }else{
        p=first;
        q=NULL;
        for(int i=0;i<pos-1 &&pos;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
 return x;
}

void reverseLL(struct Node *p){
    struct Node *q,*r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void concat(struct Node *p,struct Node *q){
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    q=NULL;
}

void merge(struct  Node *p,struct Node *q){
    if(first->data<second->data){
        third=first;
        last=first;
        first=first->next;
        last->next=NULL;
    }else{
        third=second;
        last=second;
        second=second->next;
        last->next=NULL;
    }

    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
          last->next=first;
          last=first;
          first=first->next;
          last->next=NULL;
        }else{
          last->next=second;
          last=second;
          second=second->next;
          last->next=NULL;
    }
    }
    if(first!=NULL){
        last->next=first;
    }else{
        last->next=second;
    }
}

int main()
{
    struct Node *p;
    p = new Node;
    struct Node *r = new Node;
    struct Node *s = new Node;
    struct Node *q = new Node;
    int A[] = {3, 5, 7, 9, 11, 13};
    int B[] = {16, 18, 20, 22, 24, 26};
    create(A, 6);
    create2(B,6);
    display(first);
    cout << endl;
    insert(first, 2, 6);
    display(first);
    cout << endl;
    insertLast(1648);
    display(first);
    cout << endl;
    insertSorted(first, 8);
    display(first);
    cout << endl;
    cout<<"Deleted element is: "<<Delete(first,5)<<"\n";
    display(first);
    cout<<isSorted(first)<<endl;
    

    return 0;
}