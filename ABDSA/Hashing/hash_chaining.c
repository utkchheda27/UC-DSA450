#include<stdio.h>
#include "chains.h"

int Hash(int key)
{
return key%10;
}
void InsertHT(struct Node *H[],int key)
{
int index=Hash(key);
SortedInsert(&H[index],key);
}

int main()
{
    struct Node *HT[10];
    for(int i=0;i<10;i++){
        HT[i]=NULL;
    }
    InsertHT(HT,12);
    InsertHT(HT,22);
    InsertHT(HT,42);
    struct Node *t=Search(HT[Hash(22)],22);
    printf("%d ",t->data);
    return 0;
}