/*Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Example 1:

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.

Your Task:
You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.


Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)


Constraints:
1 <= |str| <= 103
*/

//INTITUTION 
//we cannon have same index walle elements so do string mei longest common subsequence laggannna bas iss constraint ke sathh ke common subseqyence mei jo do corresponding  element haii wo same addreeess ke na ho orignal string meiii 



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution {
    int solve(int index1 ,int index2 ,string str , vector<vector<int>> &dp){
        int n=str.length();
        if(index1==n || index2==n)return 0;
        
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        int ans=0;
        if( index1!=index2 && str[index1]==str[index2]){
             ans= 1+solve(index1+1 ,index2+1 ,str ,dp);
            
        }
        else{
          ans= max(solve(index1+1 ,index2 , str ,dp) , solve(index1 ,index2+1 ,str ,dp));
        }
        dp[index1][index2]=ans;
        return ans;
        
            
    }




    
    
    int solveTab(string str){
		    int n=str.length();
		    vector<vector<int>> dp(n +1,vector<int> (n+1,0));
		    
		    for(int index1=n-1; index1>=0 ;index1--){
		        for(int index2=n-1 ; index2>=0 ;index2--){
		            
		            
		         int ans=0;
        if( index1!=index2 && str[index1]==str[index2]){
             ans= 1+dp[index1+1][index2+1];
            
        }
        else{
          ans= max(dp[index1+1][index2]  ,dp[index1][index2+1 ] );
        }
        dp[index1][index2]=ans; 
        
        
		        }
		    }
	return dp[0][0];  
        
    }
	public:
		int LongestRepeatingSubsequence(string str){
		  //  int n=str.length();
		  //  vector<vector<int>> dp(n,vector<int> (n,-1));
    // 		return solve(0 ,0 ,str ,dp);
    
    return solveTab(str);
		}
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends