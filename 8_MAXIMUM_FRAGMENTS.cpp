//QUESTION
/*
Given an integer and three integers x y z  we have to break the integer rod into maximum number of fragments such that each fragment is of size x,y,z
if the given rod could not be broken into the segmentss then return 0;
*/

//SAMPLE OUTPUTS
/*

In the first test case, cut it into 2 parts of 5 and 2.

In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 
Sample Input 2:
2
7 3 2 2
8 1 4 4
Sample Output 2:
3
8
Explanation For Sample Input 2:
In the first test case, cut it into 3 parts of 3, 2 and 2.

In the second case, cut it into 8 parts of length 1.
*/


#include<bits/stdc++.h>
using namespace std;


int solve(int n,int x,int y,int z){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    //HERE WHEN WE ARE GIVING FUNCTION CALLS AGAIN WE ARE ONLY CHANGING N THEREFORE ITS A ONE DIMENSIONAL DP QUESTION
    int xused=solve(n-x,x,y,z)+1;
    int yused=solve(n-y,x,y,z)+1;
    int zused=solve(n-z,x,y,z)+1;
    
    return max(xused,max(yused,zused));
}

int solve_with_memo(int n,int x,int y,int z,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1)return dp[n];
    
    int xused=solve_with_memo(n-x,x,y,z,dp)+1;
    int yused=solve_with_memo(n-y,x,y,z,dp)+1;
    int zused=solve_with_memo(n-z,x,y,z,dp)+1;
    
    dp[n]= max(xused,max(yused,zused));
    return dp[n];
}



int solve_by_tabulation(int n,int x ,int z ,int y){
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    
    for(int i=1;i<n+1;i++){
        if(i-x>=0){
        dp[i]=max(dp[i-x]+1,dp[i]);
        }
        if(i-y>=0){
        dp[i]=max(dp[i-y]+1,dp[i]);
        }
        if(i-z>=0){
        dp[i]=max(dp[i-z]+1,dp[i]);
        }
        
    }
    if(dp[n]<0){
        return 0;
    }
    return dp[n];
}




int cutSegments(int n, int x, int y, int z) {
	//CALL FOR RECURSION
    /*
    int ans =solve(n,x,y,z);
    if(ans<0)
        return 0;
    return ans;
    */
    
    //CALL FOR MEMOIZATION
    /*
    vector<int> dp(n+1,-1);
    int ans=solve_with_memo(n,x,y,z,dp);
    if(ans<0){
        return 0;
    }
    return ans;
    */
    
    //CALL FOR SOLVE BY TABULATION
    return solve_by_tabulation(n,x,y,z);
  
}








int main(){
    
    return 0;
}