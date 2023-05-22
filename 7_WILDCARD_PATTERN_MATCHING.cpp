/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.


*/




#include<bits/stdc++.h>
using namespace std;



class Solution {
    /*
    bool solve(int index1 ,int index2 ,string &s ,string &p  ,vector<vector<int>> &dp){
        int slen=s.length();
        int plen=p.length();
        if(index1==slen && index2!=plen){
            for(int k=index2 ;k<plen ;k++){
                if(p[k]!='*')return false;
            }
            
            return true;
        }
        if(index1!=slen && index2==plen)return false;
        if(index1==slen && index2==plen)return true;
        
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        if(s[index1]==p[index2] || p[index2]=='?'){
            dp[index1][index2]= solve(index1+1 ,index2+1 , s ,p ,dp );
            return dp[index1][index2];
        }
        
        if(p[index2]=='*' ){
            bool ans1=solve(index1+1 ,index2 ,s ,p ,dp);
            bool ans2=solve(index1+1 , index2+1 , s ,p ,dp);
            bool ans3=solve(index1 , index2+1 , s ,p ,dp);
        dp[index1][index2]= ( ans1 || ans2  || ans3);
            return dp[index1][index2];
        }

        
        
        dp[index1][index2]= false;
        
        return dp[index1][index2];
        
    }
  */  
    
bool solveTab(string s ,string p){
        int slen=s.length();
        int plen=p.length();
    
        if(slen==0){
                  bool flag=true;
            for(int k=0 ;k<plen ;k++){
                if(p[k]!='*')flag= false;
                
            }
            return flag;
        }
        if(plen==0)return false;
    
    
        vector<vector<bool>> dp(slen +1,vector<bool>(plen+1,false));
    
        dp[slen-1][plen-1]=true;
        
        for(int index1=slen ;index1>=0 ;index1--){
            for(int index2=plen;index2>=0;index2--){
               
                
                
                
    if(index1==slen && index2!=plen){
        bool flag=true;
            for(int k=index2 ;k<plen ;k++){
                if(p[k]!='*')flag= false;
                
            }
            
            dp[index1][index2] =flag;
        continue;
        }

        else if(index1!=slen && index2==plen)dp[index1][index2]= false;
        else  if(index1==slen && index2==plen)dp[index1][index2]= true;
        

        
        else  if(s[index1]==p[index2] || p[index2]=='?'){
            dp[index1][index2]= dp[index1+1][index2+1];
        }
        
        else if(p[index2]=='*' ){
            bool ans1=dp[index1+1][index2] ;
            bool ans2=dp[index1+1][index2+1] ;
            bool ans3=dp[index1][index2+1] ;
        dp[index1][index2]= ( ans1 || ans2  || ans3);
        }
        else{
        dp[index1][index2]= false;     
        }
        
        
                   
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            }
        }
    
    
    
    return dp[0][0];
}
public:
    bool isMatch(string s, string p) {

  return solveTab(s,p);
    }
};





int main(){
    
    return 0;
}