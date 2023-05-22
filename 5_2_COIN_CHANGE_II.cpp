/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/



#include<bits/stdc++.h>
using namespace std;


//basically in this main thing was that if we have included 1 once then next we will be doing without one thats how we will prevent repetition se subset 2 problem 

class Solution {
    int n;

    int solve(int amount,int index ,vector<int> &coins, vector<vector<int>> &dp){
        if(amount==0)return 1;
        if(amount<0)return 0;
       

        if(dp[index][amount]!=-1)return dp[index][amount];


        int ans=0;
        for(int i=index;i<n;i++){
            ans+=solve(amount-coins[i],i,coins,dp);
        }

        dp[index][amount]=ans;

        return ans;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        n=coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return solve(amount,0,coins,dp);
        
    }
};


class Tabulation {

public:
    int change(int amnt, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>> dp(n,vector<int>(amnt+1,0));


        for(int i=0;i<n;i++){
        dp[i][0]=1; 
        }
        

        for(int index=n-1;index>=0;index--){
            for(int amount=1;amount<=amnt;amount++){

        int ans=0;
        for(int i=index;i<n;i++){
            if(amount-coins[i]>=0){
            ans+=dp[i][amount-coins[i]];    
            }
            
        }

        dp[index][amount]=ans;


            }
        }

        // for(auto vec:dp){
        //     for(auto num:vec){
        //         cout<<num<<",";
        //     }cout<<endl;
        // }

        return dp[0][amnt];
        
    }
};



int main(){
    
    return 0;
}