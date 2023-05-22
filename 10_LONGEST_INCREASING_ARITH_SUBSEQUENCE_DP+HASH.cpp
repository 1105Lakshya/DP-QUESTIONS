//QUESTION
/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Recall that a subsequence of an array nums is a list nums[i1], nums[i2], ..., nums[ik] with 0 <= i1 < i2 < ... < ik <= nums.length - 1, and that a sequence seq is arithmetic if seq[i+1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

 

Example 1:

Input: nums = [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: nums = [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].

*/

//brute force
/*
brute force approach is that we consider two elements and then we assume that these numbers are the last two numbers in my Ap then we traverse back and find that weather any number can be included in the current AP by checking the common difference and then we return the maximum length we obtained in this way
*/

/*
we are first taking two numbers from the array and considering them as the last two numbers of our AP
and fir check kr ke atte haii ki unkka difference kahi pichhe bhi exist krtta hai kyyaa
agar krta hai toh length ko update marr dete haii or ans mei max length ko return kr detee haiii
*/

#include<bits/stdc++.h>
using namespace std;

class RECURSION_PLUS_MEMOIZATION {
public:
    int solve(int index ,int diff,vector<int>& nums ,unordered_map<int,int> dp[]){
        // backward check
        if(index<0)return 0;
        
        if(dp[index].find(diff)!=dp[index].end())return dp[index][diff];
        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(nums[index]-nums[j] == diff){
                ans=max(ans,1+solve(j,diff,nums ,dp));
            }
        }
        
        dp[index][diff]= ans;
        return ans;
    }

    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return n;
        
        int ans=0;
        
        unordered_map<int,int> dp[n+1];    // har index pee bhoot sarre map honnggee har map batayyegga ki agar differece wo haii toh jo index haii us takk maximum length kyya haii uss difference ke sath ap kii
        
        // map<diff ,len>
        
     for(int i=0 ;i<n;i++){
         for(int j=i+1;j<n;j++){
             ans=max(ans,2+solve(i,nums[j]-nums[i] ,nums,dp));
         }
     }
        return ans;
    }
};




class Tabulation {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int ans=0;
        unordered_map<int ,int> dp[n+1];
        for(int i=1 ;i<n;i++){
            for(int j=0 ;j<i;j++){
                int diff=nums[i]-nums[j];
                int count=1;       //ye pichhllee elements  ka count haiii i ke  
                
                //check if already present
                if(dp[j].find(diff)!=dp[j].end()){
                count=dp[j][diff];    // agar jo differeence haii wo exist krta hai toh i ke picche ke elements ye haii
                }
                dp[i][diff]=1+count;  //or ye humnne end meiii i ko joodd diyyaaa
                ans=max(ans,dp[i][diff])  ;
            }
        }
        
        
        return ans;
    }
};

int main(){
    
    return 0;
}