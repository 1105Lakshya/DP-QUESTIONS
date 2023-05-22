// QUESTION
/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/










#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    bool solveMemo(int index ,vector<int> &nums, int target ,vector<vector<int>> &dp){
        //base case
        int n=nums.size();
        if(target<0 || index>=n){
            return false;
        }
        
        if(target==0)return true;
        if(dp[index][target]!=-1)return dp[index][target];
        
        if(solveMemo(index+1 , nums ,target-nums[index],dp) ||  solveMemo(index+1 ,nums ,target,dp)){
            dp[index][target]=true;
            return true;
        }
        
        dp[index][target]= false;
        return false;
    }
*/    
    
    /*
    bool solveTab(vector<int> &nums ,int target){
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        dp[n-1][0]=true;
        dp[n-1][nums[n-1]]=true;
        for(int i=n-2 ;i >=0 ;i--){
            for(int j=0;j<=target;j++){
                dp[i][j]=(dp[i+1][j] || (j-nums[i]>=0 && dp[i+1][j-nums[i]]) );
            }
        }
        
        return dp[0][target];
        
    }
    */
    
    bool solveOptimized(vector<int> &nums ,int target){
        int n=nums.size();
       vector<bool> next(target+1 ,false);
        vector<bool> curr(target+1, false);
        next[0]=true;
        next[nums[n-1]]=true;
        for(int i=n-2 ;i >=0 ;i--){
            for(int j=0;j<=target;j++){
                curr[j]=(next[j] || (j-nums[i]>=0 && next[j-nums[i]]) );
            }
            next=curr;
        }
        
        return next[target];
        
    }    
    
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum =accumulate(nums.begin() ,nums.end() ,0);
        if(sum&1 || n==1)return false;
        
        int target =sum/2;
        
        //now out maksad is to find a subset with the sum target in the array kyukii baache hue ka sum auotmatically target ke equal hogaa
        return solveOptimized(nums ,target);
        

        
        
        
    }
};


int main(){
    
    return 0;
}