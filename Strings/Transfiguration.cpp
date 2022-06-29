// Professor McGonagall teaches transfiguration at Hogwarts. She has given 
// Harry the task of changing himself into a cat. She explains that the 
// trick is to analyze your own DNA and change it into the DNA of a cat. 
// The transfigure spell can be used to pick any one character from the 
// DNA string, remove it and insert it in the beginning. 
// Help Harry calculates minimum number of times he needs to use the 
// spell to change himself into a cat.

// Example 1:

// Input: 
// A = "GEEKSFORGEEKS" 
// B = "FORGEEKSGEEKS"
// Output: 3
// Explanation:The conversion can take place 
// in 3 operations:
// 1. Pick 'R' and place it at the front, 
//    A="RGEEKSFOGEEKS"
// 2. Pick 'O' and place it at the front, 
//    A="ORGEEKSFGEEKS"
// 3. Pick 'F' and place it at the front, 
//    A="FORGEEKSGEEKS"


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	if(A.length()!=B.length()){
    	    return -1;
    	}
    	vector<int>Hash(256);//maintaining a Hash Array to store counts
    	
    	for(int i=0;i<A.length();i++){
    	    Hash[A[i]]++;
    	    Hash[B[i]]--;
    	}
    	
    	//determines same characters present or not ,if any absent 
    	//count is non zero hence will return -1
    	for(int i=0;i<256;i++){
    	    if(Hash[i]){
    	        return -1;
    	    }
    	}
    	
    	//traversing strings from behind
    	//this logic is really important
    	int i=A.length(),j=i,ans=0;
    	while(i>=0){
    	    if(A[i]==B[j]){
    	        j--;
    	    }else{
    	        ans++;
    	    }
    	    i--;
    	}
    	return ans;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends