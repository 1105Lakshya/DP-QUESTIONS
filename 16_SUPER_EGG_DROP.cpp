/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
*/

/*We will go in flow
Recursive -> Memoization of recursive Solution -> Optimization of memoized solution ->DP -> :)

Note: We have to find minimum attempts to find the threshold floor in worst case
Threshold floor (tf) -> floor from egg will not break and for (tf+1) -> egg will break

    Here worst case means we have to take both the conditions at every floor that
    egg is broken and egg is not broken and try to achieve highest threshold floor, 
    Since we are talking about worst case so we will take maximum of both this case (as high floor as much possible)
     If floor is high even the number of attempts is greater, then we will consider this because 
     we are getting higher floor.
     And from these maximum return minimum (minimize number of attempts to find highest threshold floor)
Please Note that We have eggs always greater then 0

Base Cases:
i) If number of floor is 0 then we will attempt 0 times
ii) If number of floor is 1 then we will attempt 1 times
iii) If we have only 1 egg then we will try from floor 1 to floor n , So , here we done n attempts
Due to worst case we will try every floor and drop the egg

A) Recursive solution: It will give TLE but for better understanding do step by step
*/

#include<bits/stdc++.h>
using namespace std;


 class Solution {
public:
    int find(int k,int n)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        int ans=1000000;
        for(int i=1;i<=n;i++)  // try from 1 to n floor , drop every floor and find minimum
        { 
          int temp=1+max(find(k-1,i-1),find(k,n-i)) ;  //maximum for worst case
          ans=min(ans,temp);                                     //minimum attempts from maximum temp
        }
        
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i(included) floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
      */
        return ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor 
        return find(K,N);
         
    }
};
// Time Complexity: O(n * (2^min(n,k))
// Space Complexity: O(1) , If we ignore space taken by stack frame

// B) Memoization of Recursive solution : Still giving TLE

// Suggestion , Please see recursive solution for this

class Solution {
public:
    int find(int k,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1) return memo[k][n];
        int ans=1000000;
        for(int i=1;i<=n;i++)  // try from 1 to n floor , drop every floor and find minimum
        { 
          int temp=1+max(find(k-1,i-1,memo),find(k,n-i,memo)) ;  //maximum for worst case
          ans=min(ans,temp);                                     //minimum attempts from maximum temp
        }
        
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
      */
        return memo[k][n]=ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor
        vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
         
    }
};
// Time Complexity: O((n^2) * k)
// Space Complexity: O(k * n)

// C) Optimization of Memoization solution

// Runtime: 124 ms , Memory Usage: 29.6 MB
// Suggestion , Please see recursive and memoised solution for this

// We will use binary search instead linear serach

class Solution {
public:
    int find(int k,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n;  //if no. of floor 0 , 1 return n:
        if(k==1) return n;        // if 1 egg return number of floor   
        if(memo[k][n]!=-1) return memo[k][n];
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=find(k-1,mid-1,memo);   //egg broken check for down floors of mid
            int right=find(k,n-mid,memo) ;   // not broken check for up floors of mid
            temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
      */
        return memo[k][n]=ans;
     
    }
    int superEggDrop(int K, int N) {
        //K -> egg , N -> floor
        vector<vector<int>> memo(K+1,vector<int> (N+1,-1));
        return find(K,N,memo);
         
    }
};
// Time Complexity: O((n * k) * logn )
// Space Complexity: O(n * k)

// D) Finally Wait Over : DP just look memoized solution and you will see that no change in memoized and DP , minor changes

// Runtime: 1120 ms Memory Usage: 29.6 MB
// Suggestion , Please see recursive and memoised solution for this

class Solution {
public:
    
    int superEggDrop(int K, int N) {
        if(N==0||N==1) return N;     //Think for base case
        if(K==1) return N;
        
        vector<vector<int>> dp(K+1,vector<int> (N+1,0));
      for(int i=0;i<=K;i++)
        dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
      for(int i=0;i<=N;i++)
        dp[0][i]=0,dp[1][i]=i;   //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)
        
        for(int i=2;i<K+1;i++)
        {
            for(int j=2;j<N+1;j++)
            {    int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                    int right= dp[i][j-mid];  // not broken check for up floors of mid
                    temp=1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[K][N];
         
    }
};
// Time Complexity: O((n * k) * logn)
// Space Complexity: O(n * k)


int main(){

    return 0;
}