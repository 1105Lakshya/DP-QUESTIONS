/*
Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail
Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the 
optimal choice.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maximumSumRectangle() which takes the number R, C, and the 2D matrix M as input parameters and returns the maximum sum submatrix.


Expected Time Complexity:O(R*R*C)
Expected Auxillary Space:O(R*C)
 

Constraints:
1<=R,C<=500
-1000<=M[i][j]<=1000
*/


#include<bits/stdc++.h>
using namespace std;

//agar samjhh nhii arra toh anuj bhaiya ki viedo dekhhllooo
//waise hummne rows ka sum krrdiia haii barri barrii  and fir unmeii kadane laggaa dii jo max ayya wo return krdiiaaa



class Solution {
    int kadane(vector<int> &arr){
        int maxsum=0;
        int currsum=0;
        int n=arr.size();
        for(int i=0;i<n ;i++){
            currsum+=arr[i];
            if(currsum<0)currsum=0;
            if(maxsum<currsum)maxsum=currsum;
        }
        
        return maxsum;
    }
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> arr) {
        int ans=0;
        int maxi=INT_MIN;
    for(int i=0;i<R;i++){
        for(int j=0;j<C ;j++){
            maxi=max(maxi,arr[i][j]);
            if(i!=0){
            arr[i][j]+=arr[i-1][j];
                }
        }
    }
    
    for(int i=0;i<R;i++){
        int temp=kadane(arr[i]);
        ans=max(ans,temp);
    }
    for(int i=0 ;i<R-1 ;i++){
        for(int j=i+1 ;j<R;j++){
            for(int k=0;k<C;k++){
               arr[j][k]-=arr[i][k]; 
            }
            int temp=kadane(arr[j]);
            ans=max(ans,temp);
        }
    }
    if(ans!=0)
    return ans;
    else
    return maxi;
    }
};






int main(){
    
    return 0;
}