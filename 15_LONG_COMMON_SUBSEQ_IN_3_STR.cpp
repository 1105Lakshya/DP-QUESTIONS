/*
Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:

Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.
â€‹Example 2:

Input: 
A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence
in all the strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.


Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).


Constraints:
1<=n1, n2, n3<=20
*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

// int solve(int i ,int j ,int k , string &A, string &B, string &C  , vector<vector<vector<int>>> &dp ){
//     int n1=A.size();
//     int n2=B.size();
//     int n3=C.size();
    
//     if(i>=n1 || j>=n2 || k>=n3){
//         return 0;
//     }
    
//     if(dp[i][j][k]!=-1)return dp[i][j][k];
    
//     if(A[i]== B[j]){
//         if(A[i]==C[k])
//         {
//         dp[i][j][k]= 1+solve(i+1 ,j+1 ,k+1 ,A, B ,C ,dp );
//         return dp[i][j][k];
//         }
//         else{
//         dp[i][j][k]= max(solve(i+1 ,j+1,k,A,B,C,dp) , solve(i, j, k+1,A,B,C ,dp));
//         return dp[i][j][k];
//         }
//     }
//     if(A[i]== C[k]){
//         dp[i][j][k] = max(solve(i+1 ,j,k+1,A,B,C,dp) , solve(i, j+1, k,A,B,C ,dp));
//         return dp[i][j][k];
//     }
//     if(B[j]== C[k]){
//         dp[i][j][k]= max(solve(i ,j+1,k+1,A,B,C,dp) , solve(i+1, j, k,A,B,C ,dp));
//         return dp[i][j][k];
//     }
    
//     dp[i][j][k]= max(solve(i+1 ,j,k,A,B,C ,dp),max(solve(i ,j+1,k,A,B,C ,dp),solve(i ,j,k+1,A,B,C,dp)));
    
//     return dp[i][j][k];
    
// }




int solveTab(string A, string B, string C, int n1, int n2, int n3){
    vector<vector<vector<int>>> dp(n1+2,vector<vector<int>>(n2+2,vector<int>(n3+2,-1)));
    
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            for(int k=n3-1;k>=0;k--){
    if(A[i]== B[j]){
        if(A[i]==C[k])
        {
        dp[i][j][k]= 1+dp[i+1][j+1][k+1];
        continue;
        }
        else{
        dp[i][j][k]= max(dp[i+1][j+1][k] , dp[i][j][k+1]);
        continue;
        }
    }
    if(A[i]== C[k]){
        dp[i][j][k] = max(dp[i+1][j][k+1] , dp[i][j+1][k]);
        continue;
    }
    if(B[j]== C[k]){
        dp[i][j][k]= max(dp[i][j+1][k+1] , dp[i+1][j][k]);
        continue;
    }
    
    dp[i][j][k]= max(dp[i+1][j][k],max(dp[i][j+1][k],dp[i][j][k+1]));                
            }
        }
    }
    
    
    
    return 1+dp[0][0][0];
}



int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)))
    
    // return solve(0,0,0,A,B,C ,dp);
    
    
    return solveTab(A,B,C,n1,n2,n3);
}