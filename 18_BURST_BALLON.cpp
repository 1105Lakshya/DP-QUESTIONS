/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/


//solution kuch aisa hai dost ki tu na striver ki video dekhle is question ke liyee or fir tenu samjh ajjana hai aapee hii fer bhi mai neeche thoda sa dass dangaaaaaa okk baby i love you single forever

//toh game is prakar hai dost ki hum na jaise humen i se j tak ke liye solve karne ko bola toh mai i se lekr  j tak sarre consider karungaa ki iss barii mai ye lera huunn apne ballon burst karne ke liyyee bhai tu video dekhle aise palle ni padegaa badmei akke code dekhliooo


#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    // int solve(int i, int j , vector<int>& nums ,vector<vector<int>> &dp ){
    //     if(i>j){
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1)return dp[i][j];


    //     int pre=1;
    //     if(i!=0){
    //         pre=nums[i-1];
    //     }

    //     int post=1;
    //     if(j!=n-1){
    //         post=nums[j+1];
    //     }

    //     int ans=0;


    //     for(int k=i ;k<=j;k++){
    //     int tempans=solve(i,k-1,nums,dp)+(pre*nums[k]*post)+solve(k+1,j,nums,dp);
            
    //         ans=max(ans,tempans);

    //     }

    //     dp[i][j]=ans;
    //     return ans;
    // }








    int solveTabs(vector<int> &nums){
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){

        int pre=1;
        if(i!=0){
            pre=nums[i-1];
        }

        int post=1;
        if(j!=n-1){
            post=nums[j+1];
        }

        int ans=0;


        for(int k=i ;k<=j;k++){
            int left=0;
            if(k-1>=i){
                left=dp[i][k-1];
            }
            int right=0;
            if(k+1<=j){
                right=dp[k+1][j];
            }
        int tempans=left+(pre*nums[k]*post)+right;
            
            ans=max(ans,tempans);

        }
        dp[i][j]=ans;      

            }
        }


        return dp[0][n-1];
    }

public:





    int maxCoins(vector<int>& nums) {
        n=nums.size();
      

    //   vector<vector<int>> dp(n, vector<int>(n,-1));

    //   return solve(0,n-1,nums,dp);


    return solveTabs(nums);
    }
};




int main(){
    
    return 0;
}