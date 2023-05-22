//QUESTION
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

*/
#include<bits/stdc++.h>
using namespace std;



//RECURSIVE SOLUTION EXPONENTIAL TIME COMPLEXITY
int solveRec(vector<int> &num , int x){
    //base case
    if(x==0)
        return 0;
    
    if(x<0){
        return INT_MAX;
    }    
        int mini=INT_MAX;
        for(int i=0 ;i< num.size();i++){
            int ans=solveRec(num,x-num[i]);
            if(ans!=INT_MAX)
            mini=min(mini,1+ans); 
            //1 plus becoz we have to include the current coin as well 
        }
     



return mini;
}



//MEMOIZATION METHOD   N*X TIME COMPLEXIY 
int solve_with_memo(vector<int> &num , int x ,vector<int> &dp){
    //base case
    if(x==0)
        return 0;
    
    if(x<0){
        return INT_MAX;
    }    
    
    if(dp[x]!=-1)
        return dp[x];
    
    
        int mini=INT_MAX;
        for(int i=0 ;i< num.size();i++){
            int ans=solve_with_memo(num,x-num[i] ,dp);
            if(ans!=INT_MAX)
            mini=min(mini,1+ans); 
            //1 plus becoz we have to include the current coin as well 
        }
    


dp[x]= mini;
    
return dp[x];
}



//TABULATION METHOD SAME COMPLEXIY AS OF MEMOIZATION` 
int solveTab(vector<int> &num ,int x){
    vector<int> dp(x+1 ,INT_MAX);
    dp[0]=0;
     
    for(int i=1 ;i<=x ;i++){
        //here we are trying to solve for every amount
        for(int j=0 ;j<num.size();j++){
            if(i-num[j] >=0  && dp[i-num[j]]!=INT_MAX){
            dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x]==INT_MAX)
        return -1;
    
    return dp[x];
    
}





int minimumElements(vector<int> &num, int amount)
{
//     int ans=solveRec(num ,x );
//     if(ans==INT_MAX)
//         return -1;
//     return ans;
    
//     vector<int> dp(amount+1 ,-1);
//     int ans=solve_with_memo(num,amount ,dp);
    
//     if(ans==INT_MAX )
//         return -1;
    int ans=solveTab(num,amount);
    
    return ans;
}
















int main(){
    
    return 0;
}