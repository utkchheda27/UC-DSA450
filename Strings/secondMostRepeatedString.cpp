// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>m;
        int res=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            res=max(m[arr[i]],res);
        }
        int comp=0;
        string s;
        for(auto i:m){
           if(i.second<res)
           {
               comp=max(i.second,comp);
               if(i.second==comp){
                   s=i.first; }
           }
       }
       if(comp==0){return "";}
       return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends