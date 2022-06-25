// Given a binary string str of length N, the task is to
// find the maximum count of consecutive substrings str
// can be divided into such that all the substrings are
// balanced i.e. they have equal number of 0s and 1s. 
// If it is not possible to split str satisfying the 
// conditions then print -1.

#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vec(T) vector<T>
#define p(T1,T2) pair<T1,T2>
#define f first
#define s second
#define mod 998244353
#define MOD 1000000007
using namespace std;

int bruteForce(string s){
    int res=0;
    int count0=0;
    int N=s.length();
    for(int i=0;i<N;i++){

            if(s[i]=='0'){
                count0++;
                
            }else {
                count0--;
                
            }
            if(count0==0){
                res++;
            }
    }
    if(count0==0){
        return res;
    }else {
        return -1;
    }
} 

// Function to print an array
void printArray(int arr[], int size)
{
   int i;
    for (i = 0; i < size; i++)
       cout << arr[i] <<" ";
    cout << endl;
}
int main()
{
fastio;
cout<<bruteForce("0111100010");   
    
return 0;
    
    
    
//MMI of b w.r.t. m (prime) is binaryExpo(b,m-2,m) i.e. (b^(m-2))%m
//ascii 0-127
//A-Z   65-90
//a-z   97-122
//unset kth bit from n --> (n & ~(1 << (k - 1)))
}