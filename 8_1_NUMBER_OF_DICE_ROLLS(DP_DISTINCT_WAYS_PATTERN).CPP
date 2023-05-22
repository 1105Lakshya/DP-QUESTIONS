/*
You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
 

Constraints:

1 <= n, k <= 30
1 <= target <= 1000
*/



#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution {
public:
    //solve recursive
    int solve(int dice ,int faces ,int target){
        //base case
        if(target<0)return 0;
        if(dice==0 && target!=0)return 0;
        if(target==0 && dice!=0)return 0;
        if(target==0 && dice==0)return 1;
        
        
        int ans=0;
        for(int i=1 ;i<=faces ;i++){
            ans=ans%MOD+solve(dice-1, faces, target-i)%MOD;
        }
        
        return ans;
    }
    
    //memoization
    int solveMem(int dice ,int faces ,int target ,vector<vector<int>> &dp){
        //base case
        if(target<0)return 0;
        if(dice==0 && target!=0)return 0;
        if(target==0 && dice!=0)return 0;
        if(target==0 && dice==0)return 1;
        
        if(dp[dice][target]!=-1)return dp[dice][target];
        int ans=0;
        for(int i=1 ;i<=faces ;i++){
            ans=ans%MOD+solveMem(dice-1, faces, target-i ,dp)%MOD;
        }
        
        dp[dice][target] = ans%MOD;
        return dp[dice][target];
    }
    //tabualtion method
    int solveTab(int n ,int k ,int target){
        vector<vector<int >> dp(n ,vector<int>(target+1, 0));
        
        for(int i=1 ;i<=target ;i++){
            if(i<=k)
            dp[n-1][i]=1;
        }
        
        for(int i=n-2 ;i>=0;i--){
            for(int j=2 ;j<= target ;j++){
                for(int t=1;t<=k;t++){
                    if(j-t>=0)
                dp[i][j]=((dp[i][j]%MOD)+(dp[i+1][j-t]%MOD))%MOD;
                }
            }
        }

        return dp[0][target]%MOD;
    }
    
    //space optimized method
    int solveOptimized(int n ,int k ,int target){
        vector<int> next(target+1, 0);
        // vector<int> curr(target+1 ,0);
        for(int i=1 ;i<=target ;i++){
            if(i<=k)
            next[i]=1;
        }
        
        for(int i=n-2 ;i>=0;i--){
        vector<int> curr(target+1 ,0);
            for(int j=2 ;j<= target ;j++){
                for(int t=1;t<=k;t++){
                    if(j-t>0)
                curr[j]=((curr[j]%MOD)+(next[j-t]%MOD))%MOD;
                }
            }
            next=curr;
        }

        return next[target]%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1 ,vector<int>(target+1 ,-1));
        return solveOptimized(n, k , target);
    }
};


int main(){
    
    return 0;
}