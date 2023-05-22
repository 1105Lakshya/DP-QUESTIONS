//Question
/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/


//BABBAR BHAIIYA APPROACH
/*
string ko reversse karrooo or fir normal or reversed string mei se longest common subsequece nikaaaldooo
*/



  #include<bits/stdc++.h>
  using namespace std;

    
class Solution {
public:
    
    int solve(int start ,int end , string s ,vector<vector<int>> &dp){
        if(start>end)return 0;
        if(start==end)return 1;
        
        if(dp[start][end]!=-1)return dp[start][end];
        if(s[start]==s[end] ){
            dp[start][end]= 2+solve(start+1 ,end-1 ,s,dp);
        }
        else{
         dp[start][end]= max(solve(start+1 ,end ,s ,dp) , solve(start ,end-1 ,s ,dp));           
        }

        return dp[start][end];
    }
    
    
    
    int solveTab(string s){
        int n=s.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
        
        
        for(int start =n-1 ;start>=0 ;start--){
            for(int end=start  ; end <n ;end++){
        if(start==end){
            dp[start][end]=1;
            continue;
        }
        if(s[start]==s[end] ){
            dp[start][end]= 2+dp[start+1][end-1];
        }
        else{
         dp[start][end]= max(dp[start+1][end] , dp[start][end-1]);           
        }                  
            }
        }
        return dp[0][n-1];
    }
    
  
    int solveOptimized(string s){
        int n=s.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
        vector<int> next(n,0);
        vector<int> curr(n,0);
        
        
        for(int start =n-1 ;start>=0 ;start--){
            for(int end=start  ; end <n ;end++){
        if(start==end){
            curr[end]=1;
            continue;
        }
        if(s[start]==s[end] ){
            curr[end]= 2+next[end-1];
        }
        else{
         curr[end]= max(next[end] , curr[end-1]);           
        }                  
            }
            next=curr;
        }
        return curr[n-1];
    }
    
    
    int longestPalindromeSubseq(string s) {
     return solveOptimized(s);
    }
};






  int main(){
    
    return 0;
  }