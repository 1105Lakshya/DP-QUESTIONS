//LONGEST INCREASING SUBSEQUENCE
/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)
*/


//Dp Solution
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //DP WITH BINARY SEARCH
    //time complexity is nlog(n)
    int solve(int n ,int a[]){
        if(n==0 )return 0 ;
        
        vector<int> ans;
        //first elment always there
        ans.push_back(a[0]);
        
        
        for(int i=1 ;i< n;i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just badda element 
                // to find lower bound index complexity is logn
                int index =lower_bound(ans.begin() ,ans.end() ,a[i])-ans.begin() ; //lower_bound finding formula
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    
    //NORMAL DP SOLUTION ALL METHODSSSSSS
    
    //Recursive solution
    int solve(int n ,int a[] ,int curr ,int prev){
        //base case 
        if(curr== n){
            return 0;
        }
        
        //include
        int take=0;
        if(prev==-1 || a[curr]>a[prev]){   //ya toh first element ho ya fir pichlle se badda ho toh include 
            take=1+solve(n ,a , curr+1 ,curr);
        }
        
        //exclude
        int nottake=solve(n ,a ,curr+1 ,prev);
        
        return max(take ,nottake);
    }
    
     
    
    //RECURSION + MEMOIZATION   Nsqr space and time complexity
    int solveMem(int n ,int a[] ,int curr ,int prev ,vector<vector<int>> &dp){
        //base case 
        if(curr== n){
            return 0;
        }
        
        //prev is varying from -1 to n-2 so there are n indexes but -1 is an invalid index so we will store for that in 1+ prev so that all the indexes become valid
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        //include
        int take=0;
        if(prev==-1 || a[curr]>a[prev]){ 
            take=1+solveMem(n ,a , curr+1 ,curr ,dp);
        }
        
        //exclude
        int nottake=solveMem(n ,a , curr+1 ,prev ,dp);
        
        dp[curr][prev+1]= max(take ,nottake);   //prev+1 because it is varying from -1 to n-1 
        return dp[curr][prev+1];
     }   
     
     
     //tabulation
     int solveTab(int n ,int a[]){
          vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0)); 
          
          for(int curr=n-1 ;curr>=0 ;curr--){
              for(int prev =curr-1 ;prev>=-1 ;prev--){
                  //include
                  int take =0 ;
                  if(prev== -1 || a[curr] > a[prev]){
                      take = 1+ dp[curr+1][curr +1];
                  }
                  
                  //exclude
                  int notTake = 0 + dp[curr +1][prev +1];
                  
                  
                  dp[curr][prev+1] = max(take ,notTake);
              }
          }
          
          return dp[0][0];
     }
     
     //space optimized
        int solveTabOptimized(int n ,int a[]){
         
          vector<int> nextRow(n+1,0);
          vector<int> currRow(n+1 , 0);
          
          for(int curr=n-1 ;curr>=0 ;curr--){
              for(int prev =curr-1 ;prev>=-1 ;prev--){
                  //include
                  int take =0 ;
                  if(prev== -1 || a[curr] > a[prev]){
                      take = 1+ nextRow[curr+1];
                  }
                  
                  //exclude
                  int notTake = 0 + nextRow[prev +1];
                  
                  
                  currRow[prev+1] = max(take ,notTake);
              }
             nextRow=currRow;
          }
          
          return currRow[0];
     }
     
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
    // vector<vector<int>> dp(n, vector<int> (n+1 , -1));    //as previous index is variying from -1 to n-1 
    // return solveMem(n ,a , 0 ,-1 ,dp);
    
    return solveTab(n ,a );
    return solveTabOptimized(n ,a );
    
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends














//DP WITH BINARY SEARCH SOLUTION
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int solve(int n ,int a[]){
        if(n==0 )return 0 ;
        
        vector<int> ans;
        //first elment always there
        ans.push_back(a[0]);
        
        for(int i=1 ;i< n;i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just badda element 
                int index =lower_bound(ans.begin() ,ans.end() ,a[i])-ans.begin() ; //lower_bound finding formula
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solve(n ,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends