#include<bits/stdc++.h>
using namespace std;

// T.C  O(n)
// S.C O(n)+O(n)


int fib(int n, vector<int> &dp){
    //base case
    if(n==1 || n==0)
        return n;
    
    //checked if we have already caluclated for nth value
    if(dp[n]!=-1){
        return dp[n];
    }
    
    //saved the calculated value 
    dp[n]=fib(n-1 , dp)+fib(n-2 ,dp);

    //returned the saved value
    return dp[n];
}

int main()
{
   int n;
   cin>> n;
    
    vector<int> dp(n+1,-1);
    
    cout<<fib(n,dp)<<endl;
    return 0;
}