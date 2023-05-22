//QUESTION
/*
Mr x is a professional robber .he went to rob a series of houses that are arranged in a circluar fashion 
If two adjacent houses are robbed then the police comes
help mr X to steal the max sonaaaa
*/


//ALGO
/*
same as previous just here agar pehlaa element included haii toh last ni include hoggaa 
or agar last included hai toh first included hogaaa
toh hum array bhejjdengee jimei ek barri pehla gayab hogga ek barri dussraaa
jo dono se answer return hokke ayyeggaa usmeiii se max return krdeengee bass KHATAMMMM!
*/

#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<int> &nums){
    int n=nums.size();
    
    long long int prev2=nums[0];
    long long int prev1=max(nums[0],nums[1]);
    
    for(int i=2;i<n;i++){
        
       long long int curr=max(prev1,prev2+nums[i]);
       prev2=prev1;
        prev1=curr;
    }
    
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    
    if(n==1){
        return valueInHouse[0];
    }
    vector<int> first, second;
    
    for(int i=0 ;i< n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
        
    }
    
    return max(solve(first),solve(second));
}

int main(){
    
    return 0;
}