//question
/*
we have been given a num array and a target we need to find the possible number of combinations in which the array elements can give sum target

*/

/*
Sample Input 1 :
2
3 5
1 2 5
2 3
1 2
Sample Output 1 :
9
3
Explanation For Sample Output 1:
For the first test case, the number of possible ways will be
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)

For the second test case, the number of ways will be
(1,1,1)
(1,2)
(2,1)
Here you can see we have considered (1,2) and (2,1) in 2 different ways.
Sample Input 2 :
2
3 4
12 1 3
2 41
2 34
Sample Output 2 :
3
0
*/

#include<bits/stdc++.h>
using namespace std;
//BY RECURSION 
int  solve(vector<int> &num ,int tar){
    int n=num.size();
    if(tar==0){
        return 1 ;
    }
    if(tar<0){
        return 0;
    }
    
    int ans=0;
    for(int i=0 ;i<n;i++){
       ans+=solve(num ,tar-num[i]);
    }
    
    return ans;
}


//BY MEMOIZATION
int  solve(vector<int> &num ,int tar ,vector<int> &dp){
    int n=num.size();
    if(tar==0){
        return 1 ;
    }
    if(tar<0){
        return 0;
    }
    
    if(dp[tar]!=0)return dp[tar];
    for(int i=0 ;i<n;i++){
       dp[tar]+=solve(num ,tar-num[i],dp);
    }
    
    return dp[tar];
}


//BY Tabulation
int solveTab(vector<int> &num, int tar){
    vector<int> dp(tar+1 ,0);
    dp[0]=1;
    for(int i=1 ;i<=tar;i++){
        for(int j=0 ;j<num.size();j++){
            if(i-num[j]>=0){
            dp[i]+=dp[i-num[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    /*
    vector<int> dp(tar+1 ,0); 
    int ans=solve(num ,tar ,dp );
    return ans;
    */
    
   return solveTab(num, tar);
}
int main(){
    
    return 0;
}