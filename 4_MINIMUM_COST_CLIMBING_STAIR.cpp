//QUESTION
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/



//INTITUTION
/*
Nth  STAIR PE MINIMUM COST MEI PAHUCHNE KA TARIKKAA YE HAII KI TUM US SE N-1 STAIR TAK MINIMUM PAHUCHNE KI COST NIKALLOOO OR N-2th STAIR TAK MINIMUM PAHUCHNE KI COST NIKALL LOO KYUKII TUMHEE AGGE BHII BHADNA
HAIII TOH RETURN KARRDOOO MIN(N-1 ,N-2) +COST OF N

AGAR DESTINATION PE POHOCHHH GAYYEEE TOH WAHHA SE TOH AGGE NI BHADDNNA TOH BAS N-1 OR N-2 TAK POHOCHNE MEI HO MINIMUM HOGIII USKKOO RETURN KRDEENNGEEEE

BAS ISMEI DP LAGGADENGEE FOR OPTIMAL TAKKII BARR BARR HUM MINIMUM NA NIKALNEE JAYYEE HAR STAIR KE LIYYEE AGAR EK BAARII NIKAL LIYAAA TOH USKO SAVE KRLLLLEEEE
*/


#include<bits/stdc++.h>
using namespace std;


//TOP DOWN APPROACH
class Solution {

//TOP DOWN APPROACH   RECURION PLUS MEMOIZATION
    int solve(int stair,vector<int> &cost ,vector<int> &dp){
        if(stair==0){
            return cost[0];
        }
        if(stair==1){
            return cost[1];
        }
        
        if(dp[stair]!=-1){
            return dp[stair];
        }
        
        dp[stair]= (min(solve(stair-1,cost,dp),solve(stair-2,cost,dp))+cost[stair]);  // IS WALLI STAIR PE YA TOH IS SE PICHE WALLI STAIR SE AYYA HOGAA YA USS SE BHI PICHLE SO IS TAK PAHOCHNE KA MINIMUM TIME IS SE PICHLI DO PE JISPE JALDI PAHUCH GAYYAA HOGGAAA 
        return dp[stair];
    }


//BOTTOM UP APPROACH  TABULATION
   int  solve2(int n, vector<int> &cost ){
        // step0
        vector<int> dp(n);
        
        // step 1
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        // step 3
        for(int i=2;i<n;i++){
            dp[i]= min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]) ;
        
    }



//MEMORY OPTIMIZATION
  int solve4(vector<int> &cost, int n){
        int prev2=cost[0];
        int prev1=cost[1];
        
        //3rd step
        for(int i=2 ;i<n;i++){
            int currmin;
            currmin=min(prev2,prev1)+cost[i];
            prev2=prev1;
            prev1=currmin;
        }
        return min(prev1,prev2);
    }




public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int ans =min(solve(n-1, cost ,dp),solve(n-2,cost,dp));
        return ans;
    }
};

int main(){
    
    return 0;
}