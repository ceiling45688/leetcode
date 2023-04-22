/*Question: roll the string
description:Given a string S and an array roll where roll[i] represents rolling first roll[i] characters in the string, 
the task is to apply every roll[i] on the string and output the final string. 
Rolling means increasing the ASCII value of character, like rolling ‘z’ would result in ‘a’, rolling ‘b’ would result in ‘c’, etc.
----------------------------------------------------------------------------------------------------------
Example 1:

Input: s = "bca"
roll[] = {1, 2, 3} 
Output: eeb
Explanation: arr[0] = 1 means roll 
first character of string -> cca
arr[1] = 2 means roll 
first two characters of string -> dda
arr[2] = 3 means roll
first three characters of string -> eeb
So final ans is "eeb".
----------------------------------------------------------------------------------------------------------
Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. 
You just need to complete the function findRollOut() that takes String S, array roll, and integer N as parameters and returns the modified string.

Note- The length of the array roll and length of the string are equal.

 

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(N).

 

Constraints:
1 ≤ N ≤ 107

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	string findRollOut(string s, long long arr[], int n)
	{
	    // Your code goes here
	    int count[n]={0};
        for(int i=0;i<n;i++){
            for(int j=0; j<arr[i];j++){
            count[j]++; //
            }
            //cout<<count[arr[i]]<<endl;
        }
        for(int i=0;i<n;i++){
            s[i] = ((s[i]-'a') + count[i])%26 +'a';
        }
        return s;
	}
};
	  


//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        string s;
        cin>>s;
        long long roll[n];
        
        for(int i=0;i<n;i++){
            cin>>roll[i];
        }
        cout<<"bug"<<endl;
    
        Solution ob;

        string res = ob.findRollOut(s, roll, n);
        cout << res;
		

        
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends