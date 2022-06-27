#include<iostream>
using namespace std;

#define SIZE 10

int Hash(int key){
    return key%SIZE;
}

int probe(int H[],int key){
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0){
        i++;
    }
    return (index+i)%SIZE;
}

void Insert(int H[],int key){
    int index=Hash(key);
    if(H[index]!=0){
        index=probe(H,key);
    }
    H[index]=key;
}

int Search(int H[],int key){
    int index= Hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key){
        i++;
    }
    return (index+i)%SIZE;
}
int main()
{
    int HT[10]={0};
    Insert(HT,10);
    Insert(HT,24);
    Insert(HT,32);
    Insert(HT,42);
    cout<<"Key found at index: "<<Search(HT,34);
    return 0;
}