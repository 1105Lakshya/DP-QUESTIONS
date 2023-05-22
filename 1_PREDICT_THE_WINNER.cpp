//Question
/*
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 107

*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
//recursive approach 

/*THIS FUNCTION RETURNS THE MAXIMUM SCORE THAT PLAYER1 CAN ACHIEVE*/
/*
int solve(int start ,int end , vector<int>&nums){
    //base case
    if(start>end)return 0;
    if(start==end)return nums[start];
    

    // player1 will try  both  the  position of the array and since player2 is playing optimally he will want the player1 score to be minimum for his win  so he will consider both possiblities and will choose the possiblity that will return the least player1 score
    int choice1=(nums[start] +min(solve(start+2 , end ,nums) ,solve(start+1 ,end-1 ,nums)));
    
    
    int choice2=(nums[end] +min(solve(start , end-2 ,nums) ,solve(start+1 ,end-1 ,nums)));
    
    //returning the maximum possible score obtained from both possiblities
    return max(choice1 ,choice2);
}
*/    
  
//RECURSION PLUS MEMOIZATION SOLUTION
    /*
int solveMem(int start ,int end , vector<int>&nums , vector<vector<int>> &dp){
    //base case
    if(start>end)return 0;
    if(start==end)return nums[start];
    
    if(dp[start][end]!=-1)return dp[start][end];    
    // player1 will try  both  the  position of the array and since player2 is playing optimally he will want the player1 score to be minimum for his win  so he will consider both possiblities and will choose the possiblity that will return the least player1 score
    int choice1=(nums[start] +min(solveMem(start+2 , end ,nums ,dp) ,solveMem(start+1 ,end-1 ,nums ,dp)));
    
    
    int choice2=(nums[end] +min(solveMem(start , end-2 ,nums ,dp) ,solveMem(start+1 ,end-1 ,nums ,dp)));
    
    //returning the maximum possible score obtained from both possiblities
 
    dp[start][end]= max(choice1 ,choice2);
    return dp[start][end];
}    
*/
    
int solveTab(vector<int> &nums){
    int n=nums.size();
    
    vector<vector<int>> dp(n+1 ,vector<int>(n+1,0));
    for(int i=0 ;i<n;i++){
        dp[i][i]=nums[i];
    }
    
    for(int start=n-3 ;start>=0;start--){ //end
        for(int end=start+1 ;end<n;end++) //start
        {
            // int choice1=INT_MIN;
            if(end-2<0)continue;
    int choice1=(nums[start] +min(dp[start+2][end]  ,dp[start+1][end-1]));
            // int choice2=INT_MIN;
            // if(end-2>=0 )
     int choice2=(nums[end] +min(dp[start][end-2] ,dp[start+1][end-1]));  
            
                dp[start][end]=max(choice1 ,choice2);
        }
    }   
        

    
}
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        //getting total score
        int total=accumulate(nums.begin() ,nums.end() ,0);
        
        int n=nums.size();
        
        //MEMOIZATION CALL
        /*
        vector<vector<int>> dp(n,vector<int>(n ,-1));
        
        //getting player1 score
        int player1=solveMem(0 ,n-1 ,nums ,dp);
        */
        
        // tabulation call
        int player1=solveTab(nums);
        
        
        
        //obtaining leftout i.e player2's score
        int player2=total-player1;
        
        cout<<player1<<endl;
        cout<<player2<<endl;
        
        return player1>=player2;
        
    }
};


//Recursive solution 
/*
class Solution {
public:
//this function tells if player1 can win  or lose     
    bool solve(int start ,int end ,vector<int> &nums ,int sum1 ,int sum2, int counter){
        //base case if total of player1>player2 then player1 wins
        if(start> end)return sum1>=sum2;
        
        
        //if counter equal to odd then it is the chance of first player so he can choose either first element of the array or the last element of the arrayy  so he will try both possiblitiy if in any possibliity player1 wins he will chose that possibility and will win the gamee
        if(counter&1){
            if(solve(start+1 ,end ,nums ,sum1+nums[start] , sum2 ,counter+1) || solve(start ,end-1 ,nums ,sum1+nums[end] , sum2 ,counter+1)){
                return true;
            }
            else{
                return false;
            }
        }
        
        
//if counter is even then it is player2 turn of choosing he is playing optimallyyy so he will try to winn so he also try's both possibilites  this function returns if player1 can win or not so player1 will only win if for both possiblities  of player2  the functions returns true i.e for both possiblities of player2  player1 is wins . 
//if anyone of the possiblity of player2 would have returned false he would have chosen that possiblity and would have won the game
        else{
            if(solve(start+1 ,end ,nums ,sum1 ,sum2+nums[start],counter+1)&& solve(start ,end-1 ,nums ,sum1,sum2+nums[end] ,counter+1)){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(0 ,nums.size()-1 ,nums ,0 ,0 ,1);
    }
};

*/















int main(){
    
    return 0;
}