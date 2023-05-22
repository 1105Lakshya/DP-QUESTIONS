/*
Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000
*/

//{ Driver Code Starts


///SEE STRIVER VIEDO


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
     vector<vector<int>> dp(n,vector<int>(m,0));
     int ans=0;
     for(int i=0;i<m;i++){
         if(S1[0]==S2[i]){
         dp[0][i]=1;
        ans=1;
         }
     }
     for(int i=0;i<n;i++){
         if(S1[i]==S2[0]){
             dp[i][0]=1;
             ans=1;
         }
     }
     for(int i=1 ;i<n;i++){
         for(int j=1 ;j<m;j++){
             if(S1[i]==S2[j]){
                 dp[i][j]=1+dp[i-1][j-1];
                 ans=max(ans,dp[i][j]);
             }
         }
     }
     
    //  for(int i=0;i<n;i++){
    //      for(int j=0;j<m;j++){
    //          cout<<dp[i][j]<<" ";
    //      }cout<<endl;
    //  }
     return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends