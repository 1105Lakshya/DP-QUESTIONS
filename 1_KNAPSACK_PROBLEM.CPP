//QUESTION
/*
THERE IS A THIEF WHO WENT FOR A ROBBERY IN A STORE THERE  ARE N ITEMS IN A STORE EACH ITEM HAS CERTAIN WEIGHT AND CERTAIN VALUE IN MARKET THE THIEF CARRIES A BAG IN THAT BAG THE THIEF CAN CARRY ONLY W AMOUNT OF WEIGHT WE HAVE TO ROB IN SUCH A WAY THAT THE THIEF GETS MAXIMUM VALUE OF THE ROBBED MATERIALLLL
*/


#include<bits/stdc++.h>
using namespace std;


//RECURSION SOLUTION
/*
every item has two choices either to get included(if bag has the capacity ) or to excluded  we find all the possible combinations for every item we either exclude it or include it 
the answer which return the maximum 
*/
//here we are going from right to left 
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    //Base case
      //if only one item then steal it for max value provided its weight less than capacity
    if(index==0){
        if(weight[0]<=capacity)
            return value[0];
        else
            return 0;
    }
int include=0;
        if(weight[index]<=capacity){        //checking if particular value can be included
         include=value[index]+solve(weight ,value ,index-1,capacity-weight[index]);      // including the value by decreasing the capacity and finding max value for that capacity
        }  
         int exclude=solve(weight ,value ,index-1,capacity);
        
            
        int maxvalue=max(exclude ,include);
        return maxvalue;
    }



//SOLVE BY MEMOIZATION
int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>> &dp)
{
    //Base case
      //if only one item then steal it for max value provided its weight less than capacity
    if(index==0){
        if(weight[0]<=capacity)
            return value[0];
        else
            return 0;
    }
    
    if(dp[index][capacity]!=-1)
        return dp[index][capacity];
    
    
    
    
int include=0;
    //recursive call marne pe do elements ki value change horii hai so 2D dp
        if(weight[index]<=capacity){
         include=value[index]+solveMem(weight ,value ,index-1,capacity-weight[index],dp);   
        }
    
         int exclude=solveMem(weight ,value ,index-1,capacity,dp);
       
            
        dp[index][capacity]=max(exclude ,include);
        return dp[index][capacity];
        
        
    }

//BY Tabulation method
int solveTab(vector<int> &weight ,vector<int> &value,int n ,int capacity ){
    //setp 1 for tabulation :: create dp 
    vector<vector<int>> dp(n,vector<int>((capacity+1),0));
    
    
    //step 2 :: analysie base case
    //base case says for index=0 perform following now here index represent entire first row so we will apply the logic for entire first row
        if(weight[0]<=capacity)
        {
    for(int w =weight[0]; w<=capacity ;w++){
            dp[0][w]=value[0];
    }
        }   
    
    for(int index=1;index<n;index++){
        for(int w=0 ;w<=capacity;w++){
            int include=0;
            
            if(weight[index]<=w)
                include=value[index]+dp[index-1][w-weight[index]];
            
            
            int exclude=0+dp[index-1][w];
            
            dp[index][w]=max(exclude,include);
        }
    }
    
    return dp[n-1][capacity];
}


//OPTIMIZATION
int solveTabOptimized(vector<int> &weight ,vector<int> &value,int n,int capacity){
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);
    
    if(weight[0]<=capacity){
        for(int w=weight[0] ;w<=capacity ;w++){
            prev[w] =value[0];
        }
    }
    
    for(int index=1;index<n;index++){
        for(int w=0 ;w<=capacity;w++){
            int include=0;
            
            if(weight[index]<=w)
                include=value[index]+prev[w-weight[index]];
            
            int exclude=0+prev[w];
            
            curr[w]=max(exclude,include);
        }
        prev=curr;  //agge shifting
    }
    return prev[capacity];
    
}


//OPTIMIZATION ultra pro max 
int solveTabOptimizedultrapromax(vector<int> &weight ,vector<int> &value,int n,int capacity){
    vector<int> curr(capacity+1,0);
    
    if(weight[0]<=capacity){
        for(int w=weight[0] ;w<=capacity ;w++){
            curr[w] =value[0];
        }
    }
//      hum yahha pe nayyi array mei dallne ke bajaayye ek hi array mei doosri side se bharnaa shurruu kr reeee
    for(int index=1;index<n;index++){
        for(int w=capacity ;w>=0;w--){
            int include=0;
            
            if(weight[index]<=w)
                include=value[index]+curr[w-weight[index]];
            
            int exclude=0+curr[w];
            
            curr[w]=max(exclude,include);
        }
    }
    return curr[capacity];
    
}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
// 	return solve(weight ,value, n-1 ,maxWeight);
    
//     vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    
    return solveTabOptimizedultrapromax(weight ,value ,n,maxWeight );
}


int main(){
    
    return 0;
}