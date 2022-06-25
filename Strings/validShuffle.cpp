// Program to Check if a string is a valid shuffle of 
// two distinct strings
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

bool checkShuffle(string main,string s1,string s2){
    if(s1.length()+s2.length()!=main.length()){
        return false;
    }
    map<char,int>m;
    for(int i=0;i<s1.length();i++){
        m[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        m[s2[i]]++;
    }
    for(int i=0;i<main.length();i++){
        if(m[main[i]]==0){
            return false;
        }else{
            m[main[i]]--;
        }
    }
    return true;
}
// Function to print an array
void printArray(int arr[], int size)
{
   int i;
    for (i = 0; i < size; i++)
       cout << arr[i] << " ";
    cout << endl;
}
int main()
{
fastio;
cout<<checkShuffle("1XY2","XY","12");
    
return 0;
    
    
    
//MMI of b w.r.t. m (prime) is binaryExpo(b,m-2,m) i.e. (b^(m-2))%m
//ascii 0-127
//A-Z   65-90
//a-z   97-122
//unset kth bit from n --> (n & ~(1 << (k - 1)))
}