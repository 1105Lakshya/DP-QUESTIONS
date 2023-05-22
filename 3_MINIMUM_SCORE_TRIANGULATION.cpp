//QUESTION
/*
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

Example 1:


Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
Example 2:


Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.
Example 3:


Input: values = [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100
*/


//ALGO
/*
algo says tum first or last index wallla uthhaa loo kyuki wo do humeshha adjavcent honggee or fir beeche ke bachhe hue nodes ko use krkee ek triangle bannaoooo or fir jo left or right figure banneegiii ussse recursion se solve krallooo
base case
is do adjacent kabbhii triangle ni bannayeegii so return 0

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    
   //RECURSION + MEMOIZATION 
    int solve(vector<int> &values,int start ,int end ,vector<vector<int>> &dp ){
        //base case
        if(start+1==end)return  0;
        
        
        if(dp[start][end]!=-1)return dp[start][end];
        int ans=INT_MAX;
        
        //k choices between end and start to make the triangle
        for(int i=start+1;i<end;i++){
            
            int current=values[start]*values[end]*values[i];
            int left=solve(values,start,i,dp);
            int right=solve(values,i,end,dp);
            int tempans=current +left +right;
            ans=min(tempans,ans);
            
        }
        dp[start][end]=ans;
        return dp[start][end];
    }
    
    
    int solveTab(vector<int>&values){
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));  //0 bcoz base case
        
        //jcannot start for i as then they will be at same point and no triangle will be formed j cannot be             started form i+1 bcoz two adjacent nodes cannot make triangle that was our base case above
        for(int start=n-3;start>=0;start--){
            for(int end=start+2 ;end<n;end++){  
        int ans=INT_MAX;
        //k choices between end and start to make the triangle
        for(int i=start+1;i<end;i++){
            
            int current=values[start]*values[end]*values[i];
            int left=dp[start][i];
            int right=dp[i][end];
            int tempans=current +left +right;
            ans=min(tempans,ans);
            
        }
        dp[start][end]=ans;
         }
        }
        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        /*
        int start =0 ;
        int end=values.size()-1;
        
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        
        int ans= solve(values, start ,end ,dp);
        return ans;*/
        
        return solveTab(values);
        
    }
};





int main(){
    
    return 0;
}