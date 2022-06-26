// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    //Function to check if brackets are balanced or not
    unordered_map<char,int>symbols={{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};
    bool ispar(string x)
    {
        stack<char>st;
        for(char bracket :x){
            if(symbols[bracket]<0){
                st.push(bracket);
            }else{
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                st.pop();
                if((symbols[top]+symbols[bracket])!=0){
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }else{
            return true;
        }
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends