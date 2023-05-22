/*An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
*/
#include<bits/stdc++.h>
using namespace std;



//APPROACH
//WE have stood three pointers so that they will keep a track of what minimum number will the multiples of 2 3 5 will generate and the minimum of them gets put
//and its pointer is incremented



class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n);
        arr[0]=1;
        int i=0,j=0,k=0;
        for(int a=1;a<n;a++){
            int num1=arr[i]*2;
            int num2=arr[j]*3;
            int num3=arr[k]*5;
            if(num1<=num2 && num1<= num3){
                arr[a]=num1;
                i++;
                if(num1==num2)j++;
                if(num1==num3)k++;
            }
            else if(num2<=num1 && num2<= num3){
                arr[a]=num2;
                j++;
                if(num2==num1)i++;
                if(num2==num3)k++;
            }
            else if(num3<=num2 && num3<= num1){
                arr[a]=num3;
                k++;
                if(num3==num1)i++;
                if(num3==num2)j++;
            }
            
        }
        
        return arr[n-1];
    }
};









int main(){
    
    return 0;
}