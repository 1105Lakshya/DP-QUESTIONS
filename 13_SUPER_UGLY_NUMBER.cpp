/*
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
Example 2:

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 

Constraints:

1 <= n <= 105
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long int > ugly(n);
        int k=primes.size();
        vector<int> address(k,0 );
        ugly[0]=1;
        priority_queue<pair<long long int ,int>  ,vector<pair<long long int  ,int > > , greater<pair<long long int ,int>>> pq;
        for(int i=0;i< k ;i++){
            pq.push({primes[i]*1 , i});
        }
        
        for(int i=1;i<n;i++){
            pair<long long int ,int> p=pq.top();
            pq.pop();
            ugly[i]=p.first;
            long long int  num=p.first;
            address[p.second]++;
            pq.push({ugly[address[p.second]]*primes[p.second] ,p.second  });
            while(pq.top().first==num){
                auto temp=pq.top();
                pq.pop();
                address[temp.second]++;
                pq.push({ugly[address[temp.second]]*primes[temp.second] ,temp.second  });
            }
            
            
        }
        for(int i=0 ;i<n;i++){
            cout<<ugly[i]<<" "<<endl;
        }
        return ugly[n-1];
    }
};

int main(){
    
    return 0;
}