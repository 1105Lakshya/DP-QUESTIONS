/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

//for cheery pick up 1 shuruatt mei do robot challa do sath meiii  and goo on leetcode and see solution 

//basically ismeii humnee kyaa kiaa ki humnne dono starting se start kardiiyyee of recursion call mei maine send kardiaaa ki  konsi row pe haii kykii donoo same row per honnggeee humeshha and konsi column pe haiii pehla robot and konse column pe hai doosra robot konse pe hai wo send kardiyee agar dono same column pe haii tohh  ek hi add karnna and agar different pe hai toh dono add karna fir next row se answer nikal ke le anna 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m,n;
    int solve(int i,int j1,int j2 ,vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(i==m)return 0;
        if(j1<0 || j1>=n || j2<0 || j2>=n)return 0;
        // cout<<"maraooo"<<endl;

        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

        int ans=0;
        if(j1==j2){
            ans+=grid[i][j1];
        }
        else{
           ans+=grid[i][j1];
           ans+=grid[i][j2]; 
        }
        

            

            int tempans=0;
            for(int k=-1;k<=1;k++){
                for(int t=-1;t<=1;t++){
                    tempans=max(tempans,solve(i+1,j1+k,j2+t,grid,dp));

                }
            }

            ans+=tempans;

            dp[i][j1][j2]=ans;
            return ans;


        
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));

       return  solve(0,0,n-1,grid,dp);
        
    }
};




int main(){
    
    return 0;
}