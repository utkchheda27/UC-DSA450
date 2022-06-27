#include<iostream>
using namespace std;
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q; //pointer to create array dynamically
};

void create(struct Queue *t,int size){
    t->size=size;
    t->rear=t->front=0;
    t->Q=new Node *[size]; 
    // or t->Q=(struct Node **)malloc(t->size*sizeof(Node *))
}

void enqueueCircular(struct Queue *t,Node *x){
    if(((t->rear)+1)%(t->size)==t->front){
        cout<<"Queue is Full"<<endl;
    }else{
        //modulus operator gives rise to circular working
        t->rear=(t->rear+1)%(t->size);
        t->Q[t->rear]=x;
    }
}


Node* dequeueCircular(struct Queue *t){
    Node* r=NULL;
    if(t->rear==t->front){
        cout<<"Queue is Empty"<<"\n";
    }else{
        t->front=(t->front+1)%(t->size);
        r=t->Q[t->front];
    }
    return r;
}


void DisplayQueue(struct Queue t){
    int i=t.front+1;
    do{
        cout<<t.Q[i]<<endl;
        i=(i+1)%t.size;
    }while(i!=(t.rear+1)%t.size);
}

bool isEmpty(struct Queue t){
    if(t.front==t.rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(struct Queue t){
    if(t.rear==(t.size -1)){
        return true;
    }else{
        return false;
    }
}

//kept root pointer as global
struct Node *root=nullptr;

struct  Node{
   int data;
   struct Node *lchild;
   struct Node *rchild; 
};

//generate tree level by level,first root then  next level

//For generating tree using Linked representation ,
//we need queue data structure

void Tcreate(){
    Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    cout<<"Enter root value"<<endl;
    cin>>x;
    root =new Node;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    enqueueCircular(&q,root);
    while(!isEmpty(q)){
        p=dequeueCircular(&q);
        cout<<"Enter Left Child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueueCircular(&q,t);
        }
        cout<<"Enter Right Child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueueCircular(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void levelorder(struct Node *p){
    struct Queue q;
    create(&q,100);
    cout<<p->data<<" ";
    enqueueCircular(&q,p);
    while(!isEmpty(q)){
        p=dequeueCircular(&q);
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            enqueueCircular(&q,p->lchild);
        }if(p->rchild){
            cout<<p->rchild->data<<" ";
            enqueueCircular(&q,p->rchild);
        }
    }
}

int Height(struct Node *p){
    int x,y=0;
    if(p==NULL){
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }
}

//this is giving vibes of postorder
int count(struct Node* p){
    int x,y;
    if(p!=NULL){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int main()
{
    Tcreate();
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    levelorder(root);
    cout<<"\n";
    cout<<Height(root);
    cout<<"\n";
    cout<<count(root);
    return 0;
}