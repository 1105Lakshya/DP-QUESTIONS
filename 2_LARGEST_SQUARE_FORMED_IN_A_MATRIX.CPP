//QUESTION(Largest square formed in a matrix)
/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
Example 2:

Input: n = 2, m = 2
mat = {{0, 0}, 
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxSquare() which takes n, m and mat as input parameters and returns the size of the maximum square sub-matrix of given matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 50
0 ≤ mat[i][j] ≤ 1

*/



// algo
/*
recursive algo says ki mai current element ke right se puchhungaa ki bhaiii tu bata kitnee size ka maximum square bannara haiii tuuuu
ye hii baat mai appnne current element ke neeche walle se puchhunggaaa ki bataa tu kitnne size ka square bannarraaa 
ye hii baat mai apnnne diagonallly downwarrdd walleee se puchhhungggaa ki tu kittnne ka max square bannaraaaa
ab agar mera current element one haiii to wo jo squareee bannnayyegaaa uskkkaa size 1+min(jo uppar wallee teeno return honngge) hogaaaa
maxii bannake chalungaa or answer ajjaayyegaaa fir ismeii dp ghusaaddd dunngaaaaaa


*/



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:

//RECURSIVE SOLUTION
/*
int  solve(int n,int m ,vector<vector<int>> &mat ,int i ,int j ,int &maxi ,vector<vector<bool>> &dp){
    if(i>=n || j>=m){
        return 0;
    }
        int right_square=solve(n ,m, mat ,i+1 ,j ,maxi);
        int diagonal_square=solve(n ,m ,mat ,i+1 ,j+1 ,maxi);
        int down_square=solve(n ,m ,mat ,i ,j +1 ,maxi);
    if(mat[i][j]==0){
        return 0;
    }
    else{
        
        int ans=1+min(right_square,min(diagonal_square,down_square));
        maxi=max(maxi,ans);
        return ans;
    }
}
*/

//RECURSION PLUST MEMOIZATION
/*
int  solveMem(int n,int m ,vector<vector<int>> &mat ,int i ,int j ,int &maxi ,vector<vector<int>> &dp){
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    
    
        int right_square=solveMem(n ,m, mat ,i+1 ,j ,maxi,dp);
        int diagonal_square=solveMem(n ,m ,mat ,i+1 ,j+1 ,maxi,dp);
        int down_square=solveMem(n ,m ,mat ,i ,j +1 ,maxi,dp);
        
        
    if(mat[i][j]==0){
        dp[i][j]= 0;
        return dp[i][j];
    }
    else{
        
        dp[i][j]=1+min(right_square,min(diagonal_square,down_square));
        maxi=max(maxi,dp[i][j]);
        return dp[i][j];
    }
}
*/


//TABULATION METHOD
int solveTab(int n,int m,vector<vector<int>> &mat){
    vector<vector<int>> dp(n,vector<int>(m,0) );
    int maxi=0;
    //border wallee agar zero hongge toh zero size ka square agar 1 toh 1 size ka
    for(int i=0;i<n;i++){
        if(mat[i][m-1]==1){
            dp[i][m-1]=1;
            maxi=1;
        }
    }
    
    for(int i=0 ;i<m;i++){
        if(mat[n-1][i]==1){
        dp[n-1][i]=1;
            maxi=1;
        }
    }
    for(int i=0 ;i<n;i++){
        for(int j=0 ;j<m;j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
    
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
        int rightsq=dp[i][j+1];
        int diagsq=dp[i+1][j+1];
        int downsq=dp[i+1][j];
        
        if(mat[i][j]==1){
        dp[i][j]=1+min(rightsq,min(diagsq,downsq));
        
        }
        maxi=max(maxi,dp[i][j]);
    }
    }
    cout<<"displaying ans"<<endl;
    for(int i=0 ;i<n;i++){
        for(int j=0 ;j<m;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return maxi;
    
}

    int maxSquare(int n, int m, vector<vector<int>> mat){
   /*
   int maxi=0 ;
    int i=0 ;
    int j=0 ;
    // solve(n, m ,mat ,i ,j ,maxi);
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int origin=solveMem(n, m ,mat,i ,j ,maxi ,dp);
    
    return maxi;*/
    
    return solveTab(n ,m ,mat);
    }
    
    
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends