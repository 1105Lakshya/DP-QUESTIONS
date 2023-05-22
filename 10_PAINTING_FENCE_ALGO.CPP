//QUESTION
/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since the answer can be large return it modulo 10^9 + 7.




*/



// ALGO 
/*
Here we started with 2 posts  Now number of cases for twoo posts are divided into two cases
when they are same   number of such cases are k
and when they are differrent  number of such cases are k*(k-1)


now for three we have to paint another fence in the end so for case in which in the end last two fence have same color iss   for n=2 the number of cases in which in the end 
we had different colors can be c
hosen otherwise three colors will be adjacent voilating the condition  so in the end just we need to paint with the color in which in the end
the colors were different    so total number of cases for that are k*(k-1)


now we will paint the third such that in the end we have different colors for that we will paint all the two colored fence int such a way that it has different color in the end
for this we will have k-1 choices for each combination of previous one as one color is in the end so reamining k-1 colors will barri barri se ayeengee harr case keee so total number 
such cases are             previous case ke sareee *k-1


similarly recursion buildsss


*/

//SOLVE(N-2,k)*K-1   KA LOGIC YE HAII KE SAME COLOR WALLE WO HI HONGGE JO PICHLE SE PICHLE WALLE MEI DIFFERENT COLORS HONGGEE UNKOOO HI TOH HUM SAME COLOR KR PAYENGE WRNAA TEEN HOJAYYENGE SAME COLOR KEE
#include<bits/stdc++.h>
using namespace std;



#define MOD 1000000007
int add(int a ,int b){
    return (a%MOD+b%MOD)%MOD;
}

long long int mul(int a,int b){
    long long int ans=((a%MOD)*1LL*(b%MOD));//1LL multiply kiyaa takkii humara jo multiply hore hai integer wo long long int mei promote hojaayyee wo calclate hone se pehle promote ni hotte isliye integer overflow deteeee haiiii
//     return ((a%MOD)*(b%MOD)%MOD);
        return ans%MOD;
}




//BY RECURSION
int solve(int n, int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return mul(k,k);           //k+k(k-1)
    }
    
    int ans=add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}

//RECURSION + MEMOIZATION
long long int solveMem(int n, int k , vector<long long int> &dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return mul(k,k);           //k+k(k-1)
    }
    
    if(dp[n]!=-1)return dp[n];
    
   dp[n]=(add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1)))%MOD;
    return dp[n];
}

//SOLVE BY TABULATION METHOD
int solveTab(int n,int k){
    vector<int> dp(n+1,0);
dp[1] =k;
dp[2] =add(k,mul(k,k-1));       //k*(k-1)

for(int i=3;i<=n;i++){
    dp[i]=(add(mul(dp[i-2],k-1),mul(dp[i-1],k-1)))%MOD;
}
    return dp[n];
}


//OPTIMIZED CODE
int solveTabOptimized(int n,int k){
int prev2 =k;
int prev1 =add(k,mul(k,k-1));       //k*(k-1)

for(int i=3;i<=n;i++){
    int ans=(add(mul(prev2,k-1),mul(prev1,k-1)))%MOD;
    
    prev2=prev1;
    prev1=ans;
}
    return prev1;
}


int numberOfWays(int n, int k) {
    return solveTabOptimized(n,k);
}





int main(){
    
    return 0;
}

