#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st){
    cout<<"Enter size"<<endl;
    cin>>st->size;
    cout<<"\n";
    st->top=-1;
    st->S=new int[st->size];
}

void Display(struct Stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.S[i]<<endl;
    }
    cout<<"\n";
}

void Push(struct Stack *st,int x){
    if(st->top==st->size-1){
        cout<<"Stack Overflow"<<"\n";
    }else{
        st->top++;
        st->S[st->top]=x;
    }
}

int Pop(struct Stack *st){
    if(st->top==-1){
        cout<<"Stack Underflow"<<"\n";
        return -1;
    }else{
        int x=st->S[st->top--];
    }
    
}

int peek(struct Stack st,int index){
    int x=-1;
    if(st.top - index +1<0){
        cout<<"Invalid Index"<<"\n";
    }else{
        x=st.S[st.top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st){
    if(st.top==-1){
      return 1;  
    }else {return 0;};
}

int isFull(struct Stack st){
    if(st.top==st.size-1){
      return 1;  
    }else {return 0;};
}

int stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.S[st.top];
    }else return -1;
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,7);
    Push(&st,9);
    Push(&st,11);
    Push(&st,13);
    Display(st);
    cout<<"\n";
    cout<<peek(st,3)<<"\n";
    cout<<stackTop(st)<<"\n";
    cout<<isEmpty(st)<<"\n";
    cout<<isFull(st)<<"\n";

    Display(st);
    return 0;
}