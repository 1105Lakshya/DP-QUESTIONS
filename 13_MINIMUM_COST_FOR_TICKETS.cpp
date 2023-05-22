//QUESTION
/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
 

Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000


*/


//ALGO
/*Har din ke liyeee humee teen callss marrniii hai kyukii hum saree cases banna re haiii toh har din  hum single day 7 day or 30 day wall ticket khariidengee jo kiffattataiiii hogga uskooo return krdeengeeee*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
    
    //RECURSION PLUST MEMOIZATION
    int solve(int n, vector<int>& days, vector<int>& costs,int index,vector<int> &dp){
        if(index>=n){
            return 0; 
        }
        if(dp[index]!=INT_MAX)return dp[index];
        
        // if(dp[index]!=-1)return dp[index];
        //taking one day ticket 
        int onedaycost=costs[0]+solve(n ,days ,costs ,index+1,dp);
        
        //taking seven dat ticket
        int currday=days[index];  //current day toh ayyega hi naa
        int count=1;
        while(index+count<n && currday+7>days[index+count]){
            count++;
        }
        
        int sevendaycost=costs[1]+solve(n,days, costs ,index+count,dp);
        
        //taking thirty days ticket
        count=1;
        while(index+count<n && currday+30>days[index+count]){
            count++;
        }
        
        int thirtydaycost=costs[2]+solve(n,days, costs ,index+count,dp);
        dp[index]= min(onedaycost,min(sevendaycost,thirtydaycost));
        return dp[index];
    }
    
    
    
    
    
    
    //solve by tabulation
    int solveTab(int n ,vector<int> days ,vector<int>&costs){
        vector<int> dp(n,INT_MAX);
        
        dp[n-1]=min(costs[0],costs[1]);
        dp[n-1]=min(dp[n-1] ,costs[2]);
        
        for(int index=n-2 ;index>=0;index--){
        int onedaycost=costs[0]+dp[index+1];
        
        //taking seven dat ticket
        int currday=days[index];  //current day toh ayyega hi naa
        int count=1;
        while(index+count<n && currday+7>days[index+count]){
            count++;
        }
            int sevendaycost=costs[1];
        if(index+count!=n){
         sevendaycost+=dp[index+count];
            
        }
        
        //taking thirty days ticket
        count=1;
        while(index+count<n && currday+30>days[index+count]){
            count++;
        }
            int thirtydaycost=costs[2];
        if(index+count!=n)
         thirtydaycost+=dp[index+count];   
            
            
        dp[index]=min(onedaycost,min(sevendaycost,thirtydaycost));
            
        }
                      
        return dp[0];
        
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        // int n=days.size();
        // // vector<int> dp(n,INT_MAX);
        // // return solve(n,days,costs,0 ,dp);
        
        // return solveTab(n ,days,costs);

    int ans=0;
        
        queue<pair<int,int>> month ,week;      //pair<day,cost> 
        for(int day:days){
            //step 1 remove expired days
        while(!month.empty() && month.front().first+30<=day){
            month.pop();
        }
        while(!week.empty() && week.front().first+7<=day){
            week.pop();
        }
        
            
        //step 2 add cost for current day
        week.push(make_pair(day,ans+costs[1]));
        month.push(make_pair(day,ans+costs[2]));
        
        //step 3 ans updaaatee
        ans=min(ans+costs[0] ,min(week.front().second,month.front().second));
        }
        return ans;



    }
};






int main(){
    
    return 0;
}