//question is find nCr n given r given gfg


#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;


class Solution{
    
int solve(int n ,int r  ,vector<vector<int>> &dp ){
    if(n<r)return 0;
    if(r==1)return n ;
    if(r==0 || r==n)return 1;
    
    if(dp[n][r]!=-1)return dp[n][r];
    
    int  ans= (solve(n-1, r-1 ,dp )%MOD+ solve(n-1 , r ,dp)%MOD)%MOD;
    dp[n][r]=ans;
    
    return dp[n][r]%MOD;
    // return ans;
}




//VEry NICE WAY TO FIND FACTORIAL


/*
int solve(int n, int r){

    if(r>n)return 0;
    long long  ans=1;
    r=min(r,n-r);
    for(int i=1;i<=r;i++){
        ans*=(n--)%MOD;
        ans%=MOD;
        ans/=i;
    }
    
    return ans;
}
*/




int solveTab(int N ,int R){
    vector<vector<int>> dp(N+2 ,vector<int>(R+2,0));
    for(int i=0;i<=N;i++){

        dp[i][0]=1;

    } 
    
    
    for(int i=1;i<=N;i++){

            for(int j=0;j<=R&& j<=i;j++){

                 if(i==j)dp[i][j]=1;

                else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;;

            }

        }
    return dp[N][R]%MOD;
}

public:
    int nCr(int n, int r){
    // vector<vector<int>> dp(n+1, vector<int>(r+1,-1));
return solveTab(n,r );
    }
};




int main(){
    
    return 0;
}