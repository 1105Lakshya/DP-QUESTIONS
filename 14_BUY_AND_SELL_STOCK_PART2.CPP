/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.


*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

// ****make a graph of prices and buy at the bottom of the graph and sell at the peak of the graph***


class SolutionAnuj {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cost;
        int selling_price;
        int profit=0;
        for(int i=0;i<n;i++){
            if(  i<n-1 &&  prices[i]<prices[i+1] ){   //jaise hi profit ka chance ho buy krlloooo
                cost=prices[i];
                i++;
            
            while(i<n-1 && prices[i+1]>prices[i] ){   //finding the peak 
                i++;
            }
            selling_price=prices[i];
            profit+=selling_price - cost;
            selling_price=0;
            cost=0;
            }
        }
        return profit ;
    }
};



#include<bits/stdc++.h>
using namespace std;

class SolutionBabbar {
public:
    //SOLVING BY RECURSION
    int solve(int index ,int buy ,vector<int> &prices ,vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit=0;
        if(buy)
         profit= max(-prices[index]+solve(index+1 ,0 ,prices ,dp)  , (solve(index +1 , 1 ,prices ,dp))  );
        else{
            profit=max((+prices[index] +solve(index+1 ,1  ,prices ,dp))  , solve(index+1  , 0 ,prices,dp));
        }
        dp[index][buy]=profit;
        return dp[index][buy];
        
    }
    
    
    int solveTab(vector<int> &prices){
        int n=prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2,0)) ;
        
    for(int index=n-1 ;index>=0;index--){
        for(int buy =0; buy<2;buy++){
         int profit=0;
        if(buy)
         profit= max(-prices[index]+dp[index+1][0 ] , (dp[index +1][1] )  );
        else{
            profit=max((+prices[index] +dp[index+1][1])  , dp[index+1][0] );
        }
        dp[index][buy]=profit;   

            }
        }
    return dp[0][1];
        
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2,-1));
        return solveTab(prices);
    }
};



 //*******************conjusted code***********************

class SolutionShort {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
    int n=prices.size();
    for(int i=0; i<n-1; i++){
        if(prices[i]<prices[i+1]){
            ans+=prices[i+1]-prices[i];
        }
    }
    return ans;
    }
};





int main(){
    
    return 0;
}