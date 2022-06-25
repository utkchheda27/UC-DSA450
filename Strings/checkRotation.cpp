// Given a string s1 and a string s2, write a snippet to say 
// whether s2 is a rotation of s1? 
// (eg given s1 = ABCD and s2 = CDAB, return true,
//  given s1 = ABCD, and s2 = ACBD , return false)
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

//TC:O(N*N) 
//concatenating and using find()
bool isRotated1(string s1,string s2){
string temp=s1+s1;
  if (s1.length() != s2.length()){
    return false;
  }
if(temp.find(s2)){
    return true;
}else return false;
} 

//TC: O(N1+N2)
//using 2 queue approach
bool isRotated2(string s1,string s2){
    if (s1.length() != s2.length()){
        return false;
    }
    queue<char>q1,q2;
    for(int i=0;i<s1.length();i++){
        q1.push(s1[i]);
    }
    for(int i=0;i<s1.length();i++){
        q2.push(s2[i]);
    }
    int count=0;
    while(q1!=q2 && count<=s1.length()){
        int x=q2.front();
        q2.pop();
        q2.push(x);
        if(q1==q2){
            return true;
        }
        count++;
    }
    return false;
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
string s1,s2;
cin>>s1>>s2;
cout<<isRotated2(s1,s2);
return 0;
    
    
    
//MMI of b w.r.t. m (prime) is binaryExpo(b,m-2,m) i.e. (b^(m-2))%m
//ascii 0-127
//A-Z   65-90
//a-z   97-122
//unset kth bit from n --> (n & ~(1 << (k - 1)))
}