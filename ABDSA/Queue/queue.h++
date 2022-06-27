struct Queue{
    int size;
    int front;
    int rear;
    int *Q; //pointer to create array dynamically
};

void create(struct Queue *t,int size){
    t->size=size;
    t->rear=t->front=0;
    t->Q=new int[t->size];
}

void enqueueCircular(struct Queue *t,int x){
    if(((t->rear)+1)%(t->size)==t->front){
        cout<<"Queue is Full"<<endl;
    }else{
        //modulus operator gives rise to circular working
        t->rear=(t->rear+1)%(t->size);
        t->Q[t->rear]=x;
    }
}



int dequeueCircular(struct Queue *t){
    int x=-1;
    if(t->rear==t->front){
        cout<<"Queue is Empty"<<"\n";
    }else{
        t->front=(t->front+1)%(t->size);
        x=t->Q[t->front];
    }
    return x;
}


void Display(struct Queue t){
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
