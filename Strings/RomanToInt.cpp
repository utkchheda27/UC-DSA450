// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
//     Traverse the string from n-1 to 0.

//     Make the decision the str[i] < str[i+1] :
//      1.if yes then : res -= str[i]→val
//      2.else : res += str[i]→val
     
    unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int romanToDecimal(string &str) {
    int n = str.length();
    int res = m[str[n-1]];
    for(int i = n-2; i>=0; i--) {
        if(m[str[i]] < m[str[i+1]]) {
            res=res-m[str[i]];
        }
        else {
            res =res+m[str[i]];
        }
    }
    return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends