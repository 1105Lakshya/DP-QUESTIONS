//QUESTION
/*
Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).
 

Example 1:

Input: N = 100
Output: 1
Explanation: 10 * 10 = 100
Example 2:

Input: N = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function MinSquares() which takes N as input parameter and returns minimum number of squares needed to make N.
 

Expcted Time Complexity: O(N * sqrt(N) )
Expected Space Complexity: O(N)
 

Constraints:
1 <= N <= 10000


*/


// algo 
/*Kuch ni haii bas wo number nikkalllo jahha tak ke num ka hum square kr sakte haiii fir jo number ayye unke square ka use krke combination sum lagga do*/
//{ Driver Code Starts
//Initial Template for C++
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
	//RECURSION PLUS MEMOIZATION
	    int solve(int num ,int tar,vector<int> &dp){
	        if(tar<0){
	            return INT_MAX;
	        }
	   
	        if(tar==0){
	            return 0;
	        }
	        
	        
	        if(dp[tar]!=INT_MAX)return dp[tar];
	        
	        for(int i=1 ;i<=num;i++){
	            int temp=solve(num,tar-(i*i) ,dp);
	            if(temp!=INT_MAX)
	            dp[tar]=min(dp[tar],1+temp);
	        }
	        return dp[tar];
	    }
	    
//BY TABULATION
    int solveTab(int num ,int tar){
        vector<int> dp(tar+1 ,INT_MAX);
        
        dp[0]=0;
        
        for(int i=1; i<=tar ;i++){
            for(int j=1 ;j<=num ;j++){
                if(i-j*j>=0)
            dp[i]=min(dp[i],1+dp[i-(j*j)]);
            
            }
        }
        
        
        
        return dp[tar];
    }
	    
	int MinSquares(int n)
	{
	    int num=1;
	    while(num*num<=n){
	        num++;
	    }
	    num--;
	    if(num*num==n)return 1;
	   // vector<int> dp(n+1,INT_MAX);
	    
	   // cout<<"Mai num hu "<<num<<endl;
	    
	   // return solve(num ,n,dp);
	   
	   return solveTab(num ,n);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends