/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
        int solve(int index1 ,int index2 , string &s1 ,string &s2  ,vector<vector<int>> &dp){
        int n1=s1.size();
        int n2=s2.size();
        int ans1,ans2,ans3;        
        if(index2==n2)return n1-index1;
        if(index1==n1) return n2-index2;
        
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        if(s1[index1]==s2[index2]){
            return solve(index1 +1 , index2+1 , s1 ,s2 ,dp );
        }

        else{
        // case1 insert
         ans1=1+solve(index1 ,index2+1 ,s1 ,s2 ,dp);
        
        //case2 replace
         ans2=1+solve(index1+ 1 ,index2+1 ,s1 ,s2 ,dp);
        
        //case3 delete
         ans3 =1+ solve(index1+1 ,index2 ,s1, s2 ,dp);
        
        }
        dp[index1][index2]=min(ans1 ,min(ans2 ,ans3));
        
        return dp[index1][index2];
        
    }



    int solveTab(string s1 ,string s2){
        int n1=s1.size();
        int n2=s2.size();
        int ans1,ans2,ans3;
        vector<vector<int>> dp(n1+1 ,vector<int>(n2+1,0));
        
        for(int index1=n1 ;index1>=0 ;index1--){
            for(int index2=n2 ; index2>=0 ;index2--){
        if(index2==n2){
            dp[index1][index2]= n1-index1;
            continue;
        }
        if(index1==n1){
            dp[index1][index2]= n2-index2;
            continue;            
        }
        if(s1[index1]==s2[index2]){
            dp[index1][index2]= dp[index1 +1][index2+1]  ;
        }
        else{
        // case1 insert
         ans1=1+dp[index1][index2+1];
        
        //case2 replace
         ans2=1+dp[index1+ 1][index2+1 ] ;
        
        //case3 delete
         ans3 =1+ dp[index1+1][index2] ;
        dp[index1][index2]=min(ans1 ,min(ans2 ,ans3)); 
        }
        }
        }
        return dp[0][0]; 
    }
    
    
    int solveOptimized(string s1 ,string s2){
        int n1=s1.size();
        int n2=s2.size();
        int ans1,ans2,ans3;
        vector<vector<int>> dp(n1+1 ,vector<int>(n2+1,0));
        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);

        
        for(int index1=n1 ;index1>=0 ;index1--){
            for(int index2=n2 ; index2>=0 ;index2--){
        if(index2==n2){
            curr[index2]= n1-index1;
            continue;
        }
        if(index1==n1){
            curr[index2]= n2-index2;
            continue;            
        }
        if(s1[index1]==s2[index2]){
            curr[index2]= next[index2+1]  ;
        }
        else{
        // case1 insert
         ans1=1+curr[index2+1];
        
        //case2 replace
         ans2=1+next[index2+1 ] ;
        
        //case3 delete
         ans3 =1+ next[index2] ;
        curr[index2]=min(ans1 ,min(ans2 ,ans3)); 
        }
        }
            
        next=curr;
        }
        return curr[0]; 
    }
    
    
    int minDistance(string word1, string word2) {
        // int n1=word1.size();
        // int n2=word2.size();
        // vector<vector<int>> dp(n1 ,vector<int>(n2,-1));
        // return solve(0,0,word1 , word2 ,dp);
        return solveOptimized(word1 ,word2);
    }
};











int main(){
    
    return 0;
}