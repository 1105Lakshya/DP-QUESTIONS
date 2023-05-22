/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/

#include<bits/stdc++.h>
using namespace std;



 //Memoization method 
    int solveMemo(vector<vector<int>>& envelopes ,int curr ,int prev ,vector<vector<int>> &dp){
        int n =envelopes.size();
        
        if(curr >= n){
            return 0;
        }
        if(dp[curr][prev+1 ]!=-1)return dp[curr][prev+1];
        
        int take =0 ;
        
        if((prev==-1) || (envelopes[curr][0]>envelopes[prev][0]  && envelopes[curr][1]>envelopes[prev][1]))
        {
          take = 1+solveMemo(envelopes ,curr +1 ,curr,dp);
        }
         
        int nottake=solveMemo(envelopes ,curr+1 ,prev,dp);
        
        
       dp[curr][prev+1]= max(take ,nottake);
        return dp[curr][prev+1];
    }
    
    
    //Tabulation method 
    
    int solveTab(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        vector<vector<int>> dp(n+1, vector<int> ( n+1 ,0));
        
        for( int curr=n-1 ;curr>=0 ;curr--){
        for( int prev=curr-1 ;prev>=-1 ;prev--){
        int take =0 ;   
        if((prev==-1) || (envelopes[curr][0]>envelopes[prev][0]  && envelopes[curr][1]>envelopes[prev][1]))
        {
          take = 1+dp[curr +1][curr+1];
        }
         
        int nottake=dp[curr+1][prev+1];
        
        
       dp[curr][prev+1]= max(take ,nottake);
            }
        }
        
        
        
        return dp[0][-1+1];
    }

    



class SolutionLIS {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        
        // sorting by height & if we encounter same height
        // sort by descending order of width    //SORTED IN DECRESING ORDER OF HEIGHT AS EK TYPE KI WIDTH MEI HUM EK HI LE SAKTE HAI AGAR ASCENDING MEI SORT KARDIYA TOH LONGEST INCREASING SUBSEQUENCE MEI SAME WIDTH MEI KAIII SARE COUNT HOJAYENGEE  DESENCDING MEI SORT HOGA SAME WIDTH WALO KE LIYE TOH LONGEST COMMON SUBSEQUENCE MEI TOH WOHI INCLUDE HOGA JO USS WIDTH KE LIYE MINIMUM HOGGAAAAAAAAAAAAAAAAAAAA
        sort(env.begin(), env.end(), cmp);
        
        // e.g. -> env => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
        // sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)
        
        // Now, we only need to care about width
        // So, as of now we only need to look upon v[i][1]
        // [ 6, 1, 8, 5, 7, 3, 8 ]
        
        // Now, we can only put envolop a in envolop b another if width of a is
        // less than width of b, or we can say we need an envolop whose width
        // is just greater than envolop a ( height we have already handled )
        // So, we can think of lower_bound and Longest Increasing Subsequence
        
        // because we have sorted all envolopes of a particular height
        // by descending order of width, one envolope will not interfare with 
        // another envolop of same height, if we apply lower_bound
        // i.e. first elem greater than equal to itself in lis
        
        vector<int> lis;
        
        for(int i = 0;i<env.size();i++){
            int ele = env[i][1];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        
        return lis.size();
    }
};


int main(){
    
    return 0;
}