/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.

Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500

*/

//see anuj bhaiyya viedo only 20mis

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    //MEMOIZATION SOLUTION
    //pair<number of operations<matrix obtained>>
    pair<int,pair<int,int>> solve(int start ,int end  ,int arr[] ,vector<vector<pair<int,pair<int,int>>>>&dp){
       
        // cout<<"start-> "<< start << "end-> "<<end<<endl;
        if(end-start==1){
            return {0,{arr[start] , arr[end]}};
        }
        
        if(end-start==2){
            return {arr[start]*arr[end]*arr[start+1], {arr[start] ,arr[end]}};
        }
        
        if(dp[start][end].first!=-1)return dp[start][end];
        
        
        pair<int,pair<int,int>> ans ={INT_MAX, {0,0}};

        for(int i=start+1 ;i<end;i++){
            auto p1= solve(start ,i ,arr ,dp);
            auto p2= solve(i,end ,arr ,dp);
            
            int tempans=p1.first+p2.first+p1.second.first*p2.second.second* p1.second.second;
            if(ans.first> tempans){
                ans.first=tempans;
                ans.second.first=p1.second.first ;
                ans.second.second=p2.second.second;
            }
        }
        
    dp[start][end]=ans;
    return ans;
    }
    
    
    
// TABULATION METHOD

int solveTab(int N, int arr[]){
    vector<vector<pair<int,pair<int,int>>>> dp(N,vector<pair<int,pair<int,int>>>(N,{0,{0,0}}));
    
    for(int start=0;start<N-1;start++){
        int end=start+1;
        pair<int,pair<int,int>> temp= {0,{arr[start] , arr[end]}};
        dp[start][end]=temp;
        // cout<<"bhosda  "<<dp[start][end].first<<endl;
    }
    for(int start=0 ;start<N-2;start++){
        int end=start+2;
        
        pair<int,pair<int,int>>temp = {arr[start]*arr[end]*arr[start+1], {arr[start] ,arr[end]}};
        dp[start][end]=temp;
        
    }
    for(int start=N-4;start>=0 ;start--){
        for(int end=start+3;end<N;end++){
        
        // if(dp[start][end].first!=-1)return dp[start][end];
        
        
        pair<int,pair<int,int>> ans ={INT_MAX, {0,0}};

        for(int i=start+1 ;i<end;i++){
            auto p1= dp[start][i];
            auto p2= dp[i][end];
            
            int tempans=p1.first+p2.first+p1.second.first*p2.second.second* p1.second.second;
            if(ans.first> tempans){
                ans.first=tempans;
                ans.second.first=p1.second.first ;
                ans.second.second=p2.second.second;
            }
        }
        
        
    dp[start][end]=ans;
            
        }
    }
    
        for(int i=0;i<N;i++){
            for(int j=0 ;j<N;j++){
            cout<<dp[i][j].first<<" "<<dp[i][j].second.first<<" "<<dp[i][j].second.second<<"      ";
            }cout<<endl;
        }
        cout<<"MATRIX IS ------>"<<dp[0][N-1].second.first<<"X"<<dp[0][N-1].second.second<<endl;

    return dp[0][N-1].first;
}
    
    
public:
    int matrixMultiplication(int N, int arr[])
    {

        return solveTab(N, arr);
        
    }
};

//{ Driver Code Starts.

int main(){
    
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    
    return 0;
}
// } Driver Code Ends



// ABDUL BARI APPROACH
