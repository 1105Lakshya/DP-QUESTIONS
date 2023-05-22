// Given a string s, return the longest palindromic substring in s.

// A string is called a palindrome string if the reverse of that string is the same as the original string.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        vector<vector<int>> dp(n ,vector<int>(n,0));
        int ans=0;
        int xcor=0;
        int ycor=0;
        
        for(int i=0 ;i<n;i++){
            dp[i][i]=1;
            ans=max(ans,dp[i][i]);
        }
        
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[i+1]){
            dp[i][i+1]=2;    
            ans=max(ans,dp[i][i+1]);
            xcor=i;
            ycor=i+1;
            }
        }
        

        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i+1;j--){
                if(s[i]==s[j])
                    if(dp[i+1][j-1]!=0){
                        dp[i][j]=2+dp[i+1][j-1];
                        int  temp=ans;
                        ans=max(ans,dp[i][j]);
                        if(ans!=temp){
                           xcor=i;
                            ycor=j;
                        }
                    } 
            }
        }
        
        int len=ycor-xcor+1;
        return s.substr(xcor,len);
    }    
};




int main(){
    
    return 0;
}