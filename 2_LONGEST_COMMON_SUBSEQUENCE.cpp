//QUESTION

/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
    
    int solve(string a ,string b ,int i ,int j , vector<vector<int>> &dp){  //i index of 1  //j index of 2
        int n1=a.size();
        int n2=b.size();
        if(i>=n1 || j >=n2)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        char c1=a[i];
        char c2=b[j];
        
        if(c1==c2){
            dp[i][j]= 1+solve(a,b,i+1,j+1 ,dp);
            return dp[i][j];
        }
        else{
            dp[i][j]= max(solve(a,b,i+1,j ,dp),solve(a , b,i ,j+1 ,dp));
            return dp[i][j];
        }    
        
    }
    
    
    int solveTab(string a, string b ){
        int n1=a.size();
        int n2=b.size();
        vector<vector<int>> dp(n1+1 ,vector<int>(n2+1,0));
        for(int i=n1-1 ; i>=0 ;i--){
            for(int j=n2-1 ; j>=0 ;j--){
        char c1=a[i];
        char c2=b[j];
        
        if(c1==c2){
            dp[i][j]= 1+dp[i+1][j+1];
        }
        else{
            dp[i][j]= max(dp[i+1][j],dp[i][j+1]);

        }
            }
        }
                          
    return dp[0][0]; 
    }
    
    
        int solveOptimized(string a, string b ){
        int n1=a.size();
        int n2=b.size();
        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);   
        for(int i=n1-1 ; i>=0 ;i--){
            for(int j=n2-1 ; j>=0 ;j--){
        char c1=a[i];
        char c2=b[j];
        
        if(c1==c2){          //agar dono equal toh answer mei jodd liaa or agge se answer puchh liaaa
            curr[j]= 1+next[j+1];
        }
        else{
            curr[j]= max(next[j],curr[j+1]);              // dono unequal toh ek ek krke dono ko agge bhadayaa jisne max diaa usko use krlia

        }
            }
        next=curr;
        }
                          
    return curr[0];
    }
    
    
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        // int n=text1.size();
        // int m=text2.size();
        // vector<vector<int>> dp(n ,vector<int>(m,-1));
        return solveOptimized(text1, text2);
    }
};

int main(){
    
    return 0;
}