/*

Mobile numeric keypad
MediumAccuracy: 32.6%Submissions: 25K+Points: 4
Lamp
Stand out from the crowd. Prepare with Complete Interview Preparation  

Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button or the current button itself (like 00,11, etc.). You are not allowed to press the bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

Example 1:

Input: 1
Output: 10
Explanation: Number of possible numbers 
would be 10 (0, 1, 2, 3, ., 9)  
Example 2:
Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11,
12, 14, 22, 21, 23, 25 and so on.
If we start with 0, valid numbers 
will be 00, 08 (count: 2)
If we start with 1, valid numbers 
will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers 
will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers 
will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers 
will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers 
will be 55,54,52,56,58 (count: 5) 
and so on..

Your Task:  
You don't need to read input or print anything. Complete the function getCount() which takes N as input parameter and returns the integer value

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 25
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
	    unordered_map<int, vector<int>> mp;
	    mp[0].push_back(8);
	    mp[0].push_back(0);
	    mp[1].push_back(2);
	    mp[1].push_back(1);
	    mp[1].push_back(4);
	    mp[2].push_back(2);
	    mp[2].push_back(1);
	    mp[2].push_back(3);
	    mp[2].push_back(5);
	    mp[3].push_back(3);
	    mp[3].push_back(2);
	    mp[3].push_back(6);
	    mp[4].push_back(4);
	    mp[4].push_back(1);
	    mp[4].push_back(5);
	    mp[4].push_back(7);
	    mp[5].push_back(5);
	    mp[5].push_back(2);
	    mp[5].push_back(4);
	    mp[5].push_back(6);
	    mp[5].push_back(8);
	    mp[6].push_back(6);
	    mp[6].push_back(3);
	    mp[6].push_back(5);
	    mp[6].push_back(9);
	    mp[7].push_back(7);
	    mp[7].push_back(4);
	    mp[7].push_back(8);
	    mp[8].push_back(8);
	    mp[8].push_back(9);
	    mp[8].push_back(0);
	    mp[8].push_back(5);
	    mp[8].push_back(7);
	    mp[9].push_back(9);
	    mp[9].push_back(4);
	    mp[9].push_back(8);
	    
	    
		vector<vector<long long int> > dp(N+1,vector<long long int>(10,0));
		for(int i=0 ;i<10;i++){
		    dp[1][i]=1;
		}
		long long int ans=0;
		
		for(int i=2;i<=N ;i++){
		    for(int j=0 ;j<10 ;j++){
		        for(auto k: mp[j]){
		            dp[i][j]+=dp[i-1][k];
		        }
		        
		    }
		}
		
		
		for(int i=0 ;i< 10; i++){
		    ans+=dp[N][i];
		}
		
		return ans;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends