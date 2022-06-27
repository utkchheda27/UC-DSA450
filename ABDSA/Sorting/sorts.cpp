#include<iostream>
using namespace std;

void Swap(int *x,int *y){
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void BubbleSort(int A[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int flag=0;//flag for checking if already sorted then no need to go for multiple
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                Swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)break;
    }
}

void InsertionSort(int A[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void SelectionSort(int A[],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
            swap(A[i],A[k]);
        }
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10;
    SelectionSort(A,n);
    for(int i=0;i<n-1;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

#include <stdio.h> 
/* c program which implement FIFO, LRU, and optimal page replacement algorithms */ 
int n, pg[30], fr[10]; 
void fifo(); 
void optimal(); 
void lru(); 
void main(){ 
int i, ch; 
printf("\nEnter total number of pages:”); 
scanf("%d", &n); 
printf("\nEnter page references:"); 
for (i = 0; i<n; i++) //accepting sequence 
scanf("%d", &pg[i]); 
do 
printf("\n\t(MENU\n"); 
printf("\n1)FIFO"); 
printf("\n2)OPTIMAL’); 
printf("\n3)LRU"); 
printf("\n4)Exit"); 
printf("\nEnter your choice:"); 
scanf("%d", &ch); 
switch (ch) 
{ 
case 1: fifo(); 
break; 
case 2: optimal(); 
break; 
case 3: lru(); 
break; 
} 
} while (ch != 4); 
getchar(); 
} 
void fifo() 
{ 
int i, f, r, s, count, flag, num, psize;
f=r=s=flag=0;
count = 0; 
printf("\nEnter size of page frame:”); 
scanf("%d", &psize); 
for (i = 0; i<psize; i++) 
{ 
fr[i] = -1; 
} 
while (s<n) 
{ 
flag = 0; 
num = pg[s]; 
check wether the page is already exist 
for (i = 0; i<psize; i++) 
{ 
if (num == fr[i]) 
{ 
s++; 
flag = 1; 
break; 
} 
}
//if page is not already exist 
if (flag == 0) 
{ 
if (r<psize) 
{ 
fr[r] = pg[s]; 
r++; 
s++; 
count++;
} 
else{
if (f<psize) 
{ 
fr[f] = pg[s]; 
s++; 
f++; 
count++;
}else{
    f=0;
}
}
//print the page frame 
printf("\n"); 
for (i = 0; i<psize; i++) 
{ 
printf("%d\t", fr[i]); 
}
}
printf("\nPage Faults=%d", count); 
getchar(); 
} 
void optimal() 
{ 
int count[10], i, j, k, |, m, p, r, fault, fSize, flag, temp, max, tempflag = 0; 
fault = 0; 
k= 0; 
printf("\nEnter frame size:"); 
scanf("%d", &fSize); 
//initilizing frames array 
for (i = 0; i<fSize; i++) 
{ 
count[i] = 0; 
fr[i] = -1; 
} 
/for (i = 0; i<n; i++) 
{ 
flag = 0; 
temp = pg[i]; 
//check wether the page is already exist 
for (j = 0; j<fSize; j++) 
{ 
if (temp == fr[j]) 
{ 
flag = 1; 
break;
}
} 
//if the page is not already exist and frame has empty slot 
if (flag == 0) && (k<fSize)) 
{ 
fault++; 
fr[k] = temp; 
k++; 
//printf("\n Test 0"); 
} 
//if the page is not already exist and frame is full 
else if ((flag == 0) && (k == fSize)) 
{ 
fault++; 
for (l = 0; l<fSize; l++) 
{ 
count[l] = 0; 
} 
//apply optimal replacemnt strategy 
for (m = 0; m<fSize; m++) 
{ 
tempflag = 0; 
for (r =i + 1; r<n; r++) 
{ 
if (fr[m] == pg[r]]) 
{ 
if (count[m] == 0){
count[m] = r;
}
tempflag = 1; 
} 
} 
if (tempflag != 1) 
{ 
count[m] =n +1;
}
}
//find optimal page to replace 
p=0; 
max = count[O]; 
for (l = 0; l<fSize; l++) 
{ 
if (count[l]>max) 
{ 
max = count(l); 
p=l; 
}
}
fr[p] = temp; 
} 
//print the page frame 
printf("\n"); 
for (l= 0; l<fSize; l++) 
{ 
printf("%d\t", fr[l]); 
}
}
printf("\nTotal number of faults=%d", fault); 
getchar(); 
} 
void lru() 
{ 
int count[10], i, j, k, fault, f, flag, temp, current, c, dist, least, m, cnt, p, x; 
fault = 0; 
dist = 0; 
k=0; 
printf("\nEnter frame size:”); 
scanf("%d", &f); 
//initilizing distance and frame array 
for (i = O; i<f; i++) 
{ 
count[i] = 0;//helps to know recently used page 
fr[i] = -1; 
} 
for (i = 0; i<n; i++) 
{ 
flag = 0; 
temp = pg[i];
//check wether the page is already exist or not 
for (j = 0; j<f; j++) 
{ 
if (temp == fr[j]) 
{ 
flag = 1; 
count[j] = i; 
break; 
}
}
//if the page is not already exist and frame has empty slot 
if ((flag == 0) && (k<f)) 
{ 
fault++; 
fr[k] = temp; 
count[k] = i; 
k++;
}
//if the page is not already exist and frame is full 
else if (flag == 0) && (k == f)) 
{ 
fault++; 
//find the least recenlty used page 
least = count[0]; 
for (m = 0; m<f; m++) 
{ 
if (count[m]<least) 
{ 
least = count[m); 
p=m; 
}
}
fr[p] = temp; 
count[p] = i; 
p=0; 
//print the page frame 
printf("\n"); 
for (x = 0; x<f; x++) 
{  
printf("%d\t", fr[x]);
}
}
printf("\nTotal number of faults=%d", fault); 
getchar(); 
}
