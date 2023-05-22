/*
Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

Example 1:

Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
Example 2:

Input: nums = {3,2,2}, k = 4
Output: 5
Explanation: Given a line can have 4 
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 2
Line number 3: From word no. 3 to 3
Same explaination as above total cost
= (4 - 3)2 + (4 - 2)2 = 5.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function solveWordWrap() which takes nums and k as input paramater and returns the minimized total cost.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ n ≤ 500
1 ≤ nums[i] ≤ 1000
max(nums[i]) ≤ k ≤ 2000
*/


#include<bits/stdc++.h>
using namespace std;




// class Solution {
//     //recursive solutinon
// //1  AGAR LINE EMPTY HAII TOH INCLUDE KRENGE HI KRENGGEEE
// //2  AGAR JAGGA HAII TOH CHECK KRENGE KYA APNA NEXT WORD LINE MEI AA SAKTA HAII
// //3 AGAR AA SAKTA HAI TOH JAGGA KAMM KRKEE ANSWER NIKALNE KO BOLENGGEE
// //4  EK CASE MEI BACHHI HUII JAGGA KO COST MEI INCLUDE KRLLENGEEE  OR RECURSIVELY ANSWER NIKALNE KO BOLENGGEE
// //5 MININMUM RETURN KRDEENGGEEE

//     // int solve(int index ,vector<int> &nums , int k ,int jaga ){
//     //     // cout<<"  index  "<<index<<"  "<<jaga<<endl;
//     //     int n=nums.size();
//     //     if(index==n)return 0;
        
//     //     int ans=INT_MAX;
//     //     // agar possible hai line mei include krnna toh sahii haii nahhii toh bhaii kya kr sakte haii
//     //     if(jaga== k){
//     //         ans=solve(index+1 , nums , k ,jaga- nums[index]-1);
//     //         return ans;
//     //     }
        
        
//     //     if(jaga >= nums[index]){
//     //         ans=solve(index+1 , nums , k ,jaga-nums[index]-1 );
//     //     }
        
 
//     //     jaga++;//JAGA ++ ISLIYYE KYUKI HUMNE LAST CHARACTER KA SPACE BHII INCLUDE KRKE BHEJJI THI JAGA ISLIYE ACTUAL JAGAAA 1 SPACE EXTRA HOGGII
//     //     int cost=jaga*jaga;  //BACHHI HUII JAGAA IS OUT COST 

//     //     ans=min(ans,cost+ solve(index , nums ,k , k));  // NEXT LINE SE ANSWER NIAKL LIYYYAA 
        
//     //     return ans;
//     // }


// MEMOIZATION

class Solution {
public:
    int dp[501][2001];
    int f(int i,int curr,vector<int>&nums, int k)
    {
        if(i == nums.size())
            return 0;
        
        if(dp[i][curr] != -1)
            return dp[i][curr];
            
        int pick = INT_MAX;   
        if(nums[i]<=curr)
        {
            pick = f(i+1,curr-nums[i]-1,nums,k);
        }
        
        int notPick = (curr+1)*(curr+1) + f(i+1,k-nums[i]-1,nums,k);
        
        return dp[i][curr] = min(pick,notPick);
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        //vector<vector<int>>dp(1001,vector<int>(1001,-1));
        memset(dp,-1,sizeof(dp));
        return f(0,k,nums,k);
    } 
};










int main(){
    
    return 0;
}