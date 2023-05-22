//QUESTION
/*
Given an array of integers  task is to find maximum sum subsequence such that no two elements of the subsequence are adjacent
*/
//SAMPLE INPUTS
/*
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation To Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24
Explanation To Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

*/


//Algo 
/*
do case hongee ya toh hum kisi bhi element ko include kr sakte hai ya exclude
include krennge toh recursion bhaiiya se puchhenge ki humme max sum dedo i-2 tak ke index ka or usmei hum current element ka sum jodd lengee
exclude ke case mei humme bas i-1 tak ka jo max sum hai wo battaa dooo

jo bhii dono mei max hoggaa wo current element ka max summ hoggaa ussee hum return krdeeengeee

base case mei agar zeroth element hai toh wahha tak ka max sum toh usse include krke hi ayyegga toh usse return krdiyyaa
agar index zero se kamm hogayyaa toh 0 return krddiyyaaa

Bas fir ismeiii dp ghussaddd diiiiii
*/



#include<bits/stdc++.h>
using namespace std;

//Recursion code
int solve(vector<int> &nums,int n){
    //Base case
    if(n<0){
        return 0;
    }
    
    if(n==0){
        return nums[0];
    }
    
    int incl_sum=solve(nums,n-2)+nums[n]; //sum if current element included
    int excl_sum =solve(nums,n-1)+0;//sum if current element excluded
    
    return max(incl_sum,excl_sum);
}






//RECURSION + MEMOIZATION
int solveMemo(vector<int> &nums,int n,vector<int> dp){
    //Base case
    if(n<0){
        return 0;
    }
    
    if(n==0){
        return nums[0];
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
     int incl_sum=solveMemo(nums,n-2,dp)+nums[n]; //sum if current element included
    int excl_sum =solveMemo(nums,n-1,dp)+0;//sum if current element excluded
    
    dp[n]= max(incl_sum,excl_sum);
    return dp[n];
}


//TABULATION METHOD 
int solveTabulation(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1);
    
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    
    for(int i=2;i<n;i++){
       dp[i]=max((dp[i-1]+0),(dp[i-2]+nums[i]));
    }
    
    return dp[n-1];
}


//SPACE OPTIMIZED CODE
int solveTabulationOptimized(vector<int> &nums){
    int n=nums.size();
    
    int prev2=nums[0];
    int prev1=max(nums[0],nums[1]);
    
    for(int i=2;i<n;i++){
        
       int curr=max(prev1,prev2+nums[i]);
       prev2=prev1;
        prev1=curr;
    }
    
    return prev1;
}



//Funciton to return the calculated answer
int maximumNonAdjacentSum(vector<int> &nums){
    //CALLS FOR RECURSIVE SOLUTION
    /*
    int n=nums.size();
    int ans=solve(nums,n-1);
    return ans;
    */
    
    //CALLS OF RECURSION + MEMOIZATION
    /*
    int n=nums.size();
    vector<int> dp(n+1,-1);
    return solveMemo(nums,n-1,dp);
    */
    
    //CALLS FOR TABULATION METHOD(fastest)
    return solveTabulationOptimized(nums);
    
}



int main(){
    
    return 0;
}