//QUESTION
/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000
*/


//INTUTION
/*
Iss question mei hummm pehleee to sort krllenngee jo satisfaction wallii array given haii uskoooo kyukkii jiski satisfaction kamm hogiii uskoo sabse pehle cook krenngee or jiskkii jyada hogiii usko badmmeii tabhiii maximum ayyeeggaa ab pangaa ye haiii ki hum konsi dish ko include krreee
or konsiii dish ko exclude kreee kyukkii agar negative dish ko include krnnne se jo decrement huuaa uskkoo jo time mei increment huaa usne aggee jakke cover krlliyyya tohhh isliyyye hum saree possible combination by including and excluding every negative element nikal ke dekhhengeeee  jo maximum hogaa uskoo return krddenngeeee
fir 
*/



//Solution
#include<bits/stdc++.h>
using namespace std;


class Solution {
    
    //RECURSIVE SOLUTION
    /*
    int solve(vector<int> &satisfaction ,int index ,int time){
            int n=satisfaction.size();

        //base case
        if(index==n)return 0;
        
        
        int ans=0;
        if(satisfaction[index]>=0){
           for(int i=index ;i<satisfaction.size();i++){
               ans+=satisfaction[i]*(time++);
           } 
            
            return ans;
        }
        else{
            int include_ans =satisfaction[index]*time;
            include_ans+=solve(satisfaction ,index+1 ,time+1);
            
            
            int exclude_ans=solve(satisfaction ,index+1 ,time);
            
            return max(include_ans ,exclude_ans);
            
            
        }
        
        
    }*/
    
    //RECURSION PLUS MEMOIZATION
    
    /*
    int solveMem(vector<int> &satisfaction ,int index ,int time ,vector<vector<int>> &dp ){
        //base case
            int n=satisfaction.size();
            if(index==n)return 0;
        if(dp[index][time]!=-1)return dp[index][time];
        
        int ans=0;
        int count=0;
        if(satisfaction[index]>=0){
           for(int i=index ;i<satisfaction.size();i++){
               ans+=satisfaction[i]*(time+count++);
           } 
            
            dp[index][time] =ans;
            return dp[index][time];
        }
        else{ 
            int include_ans =satisfaction[index]*time;
            include_ans+=solveMem(satisfaction ,index+1 ,time+1 ,dp);
            
            
            int exclude_ans=solveMem(satisfaction ,index+1 ,time ,dp);
            
            ans= max(include_ans ,exclude_ans);
            dp[index][time]=ans;
            return ans;
            
        }
    }
    */
    
    
    //tabulation method
    /*
    int solveTab(vector<int> &satisfaction){
        int n=satisfaction.size();
        
        vector<vector<int>> dp(n+1 ,vector<int> (n+1 ,0));
        
        for(int index=n-1 ;index>=0 ;index--){
            for(int time=index;time >=0 ;time--){
                int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
                int exclude = dp[index+1][time];
                dp[index][time]=max(include,exclude);
            }
            
        }
        return dp[0][0];
    }
    */
    
    //optimized method
    int solveTabOptimized(vector<int> &satisfaction){
              int n=satisfaction.size();
        
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for(int index=n-1 ;index>=0 ;index--){
            for(int time=index;time >=0 ;time--){
                int include = satisfaction[index]*(time+1) + next[time+1];
                int exclude =next[time];
                curr[time]=max(include,exclude);
            }
           next=curr; 
        }
        return next[0];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        /*
        sort(satisfaction.begin() ,satisfaction.end());
        int n=satisfaction.size();
        
        vector<vector<int>> dp(n+1 ,vector<int> (n+1 ,-1));
        return solveMem(satisfaction ,0 , 1 ,dp);*/
        
        sort(satisfaction.begin() ,satisfaction.end());
        return solveTabOptimized(satisfaction);
    }
};








int main(){
    
    return 0;
}