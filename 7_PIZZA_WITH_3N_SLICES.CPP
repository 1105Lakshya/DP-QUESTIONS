//QUESTION
/*
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:


Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
 

Constraints:

3 * n == slices.length
1 <= slices.length <= 500
1 <= slices[i] <= 1000
*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //RECURSIVE SOLUTION
    /*
    int solve(int index ,int endIndex,vector<int> &slices ,int size ){
        if(size==0 || index>endIndex){
            return 0;
        }
        
        int take=slices[index]+solve(index+2 ,endIndex,slices ,size-1);
        int nottake=solve(index+1 ,endIndex,slices,size);
        int ans= max(take , nottake);
        return ans;
    }
    */
    
    
    // MEMOIZATION   (ITS A 2d DP PROBLEM AS INDEX AND SIZE BOTH ARE CHANGING)
    /*
    int solveMem(int index ,int endIndex,vector<int> &slices ,int size ,vector<vector<int>>&dp){
        if(size==0 || index>endIndex){
            return 0;
        }
        if(dp[index][size]!=-1)return dp[index][size];
        
        int take=slices[index]+solveMem(index+2 ,endIndex,slices ,size-1,dp);
        int nottake=solveMem(index+1 ,endIndex,slices,size,dp);
        dp[index][size]= max(take , nottake);
        return dp[index][size];
        
        
    }
    */
    
    int solveTab(int start ,int endIndex ,vector<int> &slices){
        int n = slices.size();
        vector<vector<int>> dp(n+1 ,vector<int>(n/3 +1 ,0));
        int col=n/3;
        for(int i=1 ;i<=col;i++){
            dp[endIndex][i]=slices[endIndex];
        }
        
        for(int i=endIndex-1 ;i>=start ; i--){
            for(int size =1 ;size<=col ;size++){ //size if 0 then ans is zero thats why starting from 1
                dp[i][size]=max(dp[i+1][size] , dp[i+2][size-1] +slices[i]);
            }
        }
        
        return dp[start][n/3];
    }
    
    
    int maxSizeSlices(vector<int>& slices) {
//         int k=slices.size();
//         vector<int> dp(k+1 ,0);
//         int case1=solve(0,k-2,slices,k/3 );
//         int case2=solve(1,k-1,slices,k/3 );
        
//         return max(case1 ,case2);
        
        
        
        /*memoization calll code*/
        /*
           int k=slices.size();
        vector<vector<int>> dp(k+1 ,vector<int>(k/3 +1,-1));  
        
      int case1=solveMem(0,k-2,slices,k/3 ,dp);
        vector<vector<int>> dp2(k+1 ,vector<int>(k/3 +1,-1));  
        
        int case2=solveMem(1,k-1,slices,k/3 ,dp2 );
        
        return max(case1 ,case2);
        */
        int k=slices.size();

        int case1=solveTab(0,k-2,slices);
        
        int case2=solveTab(1,k-1,slices );
        return max(case1 ,case2);
        
        
    }
};







int main(){
    
    return 0;
}