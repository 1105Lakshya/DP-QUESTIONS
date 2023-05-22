/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
Example 2:

Input: piles = [3,7,2,3]
Output: true
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.

*/




#include<bits/stdc++.h>
using namespace std;


class Solution {

    int  solve(int i, int j  , vector<int>&piles , vector<vector<int>> &dp  ){
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans1=piles[i] + min(solve(i+2,j,piles,dp),solve(i+1 , j-1 , piles,dp));  //curr max plus mini of next two case as bob will always want us to 
        int ans2=piles[j] + min(solve(i,j-2, piles,dp) , solve(i+1, j-1 , piles,dp));

        int ans=max(ans1,ans2);

        dp[i][j]=ans;

        return ans;
    }


    int solveTab(vector<int> &piles){
        int n=piles.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
         for(int i=0 ;i< n;i++){
             dp[i][i]=piles[i];
         }
         for(int i=0 ;i<n-1;i++){
             dp[i][i+1]=max(piles[i],piles[i+1]);
         }

         for(int i=n-3; i>=0 ;i--){
            for(int j=i+2; j<n ;j++){
        int ans1=piles[i] + min(dp[i+2][j],dp[i+1][j-1]);
        int ans2=piles[j] + min(dp[i][j-2] , dp[i+1][j-1]);

        int ans=max(ans1,ans2);

        dp[i][j]=ans;            
            }
         }


         return dp[0][n-1];
    }   
public:
    bool stoneGame(vector<int>& piles) {
        // int n=piles.size();
        // vector<vector<int>> dp(n, vector<int>(n,-1));

        // int max_alice=solve(0,n-1,piles,dp);
        int max_alice=solveTab(piles);

        int total=accumulate(piles.begin() ,piles.end() , 0);

        total/=2;

        if(max_alice> total){
            return true;
        }


        return false;
    }
};



int main(){
    
    return 0;
}




/*
Approach 2: Mathematical
Intuition and Algorithm

Alice clearly always wins the 2 pile game. With some effort, we can see that she always wins the 4 pile game.

If Alice takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

We can extend this idea to N piles. Say the first, third, fifth, seventh, etc. piles are white, and the second, fourth, sixth, eighth, etc. piles are black. Alice can always take either all white piles or all black piles, and one of the colors must have a sum number of stones larger than the other color.

Hence, Alice always wins the game.
*/