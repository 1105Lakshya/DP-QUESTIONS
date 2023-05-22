//question
/*
initiallyy u are at 0th stair you can take either one step ahead or two step ahead from any stair count the number of ways to reach the nth stair


*/
#include<bits/stdc++.h>
using namespace std;


#define MOD 1000000007

int solve(long long nStairs, long long i){
    //agar nth stair pe pohoch gay iska matlab ek tarika uss raste pr jis rasste pr aap challee appko millgayyaa
    if(i==nStairs)return 1;
    
    if(i>nStairs) return 0;
    
    return (solve(nStairs,i+1)+solve(nStairs,i+2))%MOD;
    // number of ways to reach the nth stair is the sum of number of ways to reach the nth stair from n+1th chair plus the number of ways to reach from n+2th chair
}

int countDistinctWays(int nStairs) {
    int ans =solve(nStairs,0);
    return ans;
}




#define MOD 1000000007

long long solve(long long  i ,vector<long long int> &dp){
    if(i==1 || i==0)return 1;
    
    if(i==2)return 2;
    
    if(dp[i]!=-1)return dp[i];
    
    dp[i] =(solve(i-1,dp)+solve(i-2 ,dp))%MOD;
    
    return dp[i];
}

int countDistinctWays(int nStairs) {
    vector<long long> dp(nStairs+1,-1);
    long long int ans=solve(nStairs,dp)%MOD;
    return (ans%MOD);
}





int main(){
    
    return 0;
}
