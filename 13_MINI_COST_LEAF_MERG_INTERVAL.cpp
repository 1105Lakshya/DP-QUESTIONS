/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
*/


/*
Humnee apnii given array ko  start se lekr end ttak jitte bhii hisso mei divide kiaaa ja saktaa tha kiaaa
in which left part denotes the left subtree
and right part denotes the right subtreee

then use recursion to solve 

and in merge interval pattern just ulttaa the start and end 
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    pair<int,int> solve(int start ,int end , vector<int> &arr ,vector<vector<pair<int,int>>> &dp){
        if(end==start)return {arr[start] ,0};
        
        
        if(dp[start][end] .first!=-1)return dp[start][end];
        
        int ans=INT_MAX;
        int maxi=INT_MIN;
        for(int i=start ; i<end;i++){
             auto p1=solve(start , i , arr ,dp) ;
             auto p2=solve(i+1 ,end , arr ,dp);
            
             int tempans=p1.first*p2.first +p1.second+p2.second;
            int temp=ans;
            ans=min(ans ,tempans);
            if(ans!=temp){
                maxi=max(p1.first ,p2.first);
            }
                           
        }
        
    dp[start][end]= {maxi,ans};
        return dp[start][end];
    }
  
    
int solveTab(vector<int> &arr){
    int n=arr.size();
    vector<vector<pair<int,int>>> dp(n+1 , vector<pair<int,int>>(n+1,{0,0}));
    
    for(int start=0 ;start<n;start++){
        dp[start][start]={arr[start] ,0};
    }
    
    for(int start=n-1; start>=0 ;start--){
        for(int end=start+1; end<n ;end++){
        int ans=INT_MAX;
        int maxi=INT_MIN;
        for(int i=start ; i<end;i++){
             auto p1=dp[start][i] ;
             auto p2=dp[i+1][end];
            
            int tempans=p1.first*p2.first +p1.second+p2.second;
            int temp=ans;
            ans=min(ans ,tempans);
            if(ans!=temp){
                maxi=max(p1.first ,p2.first);
            }
                           
        }
        
    dp[start][end]= {maxi,ans};
        }
    }
    
    return dp[0][n-1].second;
}
public:
    int mctFromLeafValues(vector<int>& arr) {
        // int n=arr.size();
        // vector<vector<pair<int,int>>> dp(n , vector<pair<int,int>>(n ,{-1,-1}));
        // return solve(0 , n-1 , arr ,dp).second;  
        
        
        return  solveTab(arr);
    }
};



int main(){
    
    return 0;
}