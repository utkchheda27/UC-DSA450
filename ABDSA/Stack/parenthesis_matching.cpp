#include<iostream>
#include <string.h>
using namespace std;

struct Stack{
    int size;
    char *S;
    int top;
};
void Create(struct Stack *st){
    cout<<"Enter size"<<endl;
    cin>>st->size;
    cout<<"\n";
    st->top=-1;
    st->S=new char[st->size];
}

void Display(struct Stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.S[i]<<endl;
    }
    cout<<"\n";
}

void Push(struct Stack *st,char x){
    if(st->top==st->size-1){
        cout<<"Stack Overflow"<<"\n";
    }else{
        st->top++;
        st->S[st->top]=x;
    }
}

char Pop(struct Stack *st){
    if(st->top==-1){
        cout<<"Stack Underflow"<<"\n";
        return -1;
    }else{
        char x=st->S[st->top--];
        return x;
    }
    
}

char peek(struct Stack st,int index){
    char x;
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

char stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.S[st.top];
    }else return -1;
}


bool isBalanced(char *exp){
    struct Stack st;
    st.size=strlen(exp);
    st.top=-1;
    st.S=new char[st.size+1];

    //initializing stack
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            Push(&st,exp[i]);
        }else if(exp[i]==')'){
            if(isEmpty(st)){
                return false;
            }else{
                Pop(&st);
            }
        }
        if(isEmpty){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    char *exp="((a+b)*(c-d))";
    isBalanced(exp);
    return 0;
}