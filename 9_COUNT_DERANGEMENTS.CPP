//Question
/*
Derangment is a permutation of n elements such that no element is at its orignal position.
*/
// ALGO 
/*
Lets take first element now we have n-1 options to replavce it with
now there arises two case 
one we exchnge the two elements so remaining elements are n-2 now recursion bhaiyaa will find ans for n-2
or the replaced element should not be placed at first position so now there are n-1 derangements 
find by recursion and then ghusad do dp
*/

// SAMPLE INPUTS
/*
    Sample Input 1:
2
2
3
Sample Output 1:
1
2
Explanation Of Sample Output 1:
In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.

Sample Input 2:
2
1
4
Sample Output 2:
0
9
Explanation Of Sample Output 2:
In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.
*/


#include<bits/stdc++.h>
using namespace std;


#define MOD 1000000007
#include<vector>
//SOLUTION BY RECURSION
int solve(int n){
    // base case
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    int ans=(((n-1)%MOD)*((solve(n-1)%MOD)+(solve(n-2)%MOD)))%MOD;
    return ans;    
}


//RECURSION + MEMOIZATION
long long int solveMem(int n,vector<long long int> &dp){
    // base case
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    if(dp[n]!=-1)return dp[n];
    
    
    
    dp[n]=(((n-1)%MOD)*((solveMem(n-1,dp)%MOD)+(solveMem(n-2,dp)%MOD)))%MOD;
    
    return dp[n];    
}

//BY TABULATION METHOD
long long int solveTab(int n){
    vector<long long int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3; i< n+1;i++){
        long long int first= dp[i-1]%MOD;
        long long int second= dp[i-2]%MOD;
        
        long long int sum=(first + second)%MOD;
        
        long long int ans=((i-1)*sum)%MOD;
        dp[i]=ans;
    }
    return dp[n];
}

//MOST OPTIMIZED
long long int solveTabOptimized(int n){
    vector<long long int> dp(n+1,0);
    long long int prev2=0;
    long long int prev1=1;
    for(int i=3; i< n+1;i++){
        long long int first=prev1%MOD;
        long long int second=prev2%MOD;
        
        long long int sum=(first + second)%MOD;
        
        long long int ans=((i-1)*sum)%MOD;
        
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}



long long int countDerangements(int n) {
//     vector<long long int> &dp(n+1,-1);
//     return solveMem(n,dp);
    
    
    return solveTabOptimized(n);
}




int main(){
    
    return 0;
}