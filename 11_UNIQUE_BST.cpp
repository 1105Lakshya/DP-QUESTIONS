//QUESTION

/*

Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can be used to find the number of possibilities of various combinations. 

The nth term in the sequence denoted Cn, is found in the following formula: \frac{(2n)!}{(n + 1)! n!)}   

The first few Catalan numbers for n = 0, 1, 2, 3, … are : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  

Catalan numbers occur in many interesting counting problems like the following.

Count the number of expressions containing n pairs of parentheses that are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
Count the number of possible Binary Search Trees with n keys (See this)
Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
*/


/*
96. Unique Binary Search Trees
Medium

8211

321

Add to List

Share
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
*/





/*

In this we have to find the number of unique Binary tree containing N nodes
So the idea is we will count the number of binary trees with RootNode 1, 2 ,3...N
and then just their addition will give the answer.

Lets understand how will we accomplish the above with the help of an example.

Suppose we want to find the total unique binary trees for N=4;

First we will create a dp array that will store the number of unique binary tree for a particular number

let our dp array be 1 ,2, 5 ,? we have to find for n=4
we will start from 1
we will find the number of elements smaller than 1 i.e=0
number of elements larger than 1 => 4-1==3
so 1 will be the starting node and to the right of 1 we will have a subtree with number of nodes 3 so number of unique binary tree with number of elements 3 will be dp[3] i.e =5
(number of unique binary tree can be taken from dp array because to the right of 1 all the numbers will be consecutive and will have a difference of 1)
total with root node as 1== 5

similarly for n=2
we have number of elements less than 2 => 2-1=1
number of elements greater than 2=> 4-2==2
number of possible left subtree for n=2 ==> dp[1]
number of possible right subtree for n=2 ==> dp[2]
total subtree with rootnode as 2= left * right == 1*2 =2;

similarly for n=3
left subtree = dp[3-1]
right subtree=dp[4-3]
total for n=3 ==> dp[2]* dp[1] ==> 2;

for N=4
its right subtree will be empty;
total for N=4 ==> number of left subtree for root node 4 ==> dp[4-1] ==>5

total ==5+2+2+5==>14

similarly for N=5

BELOW IS THE IMPLEMENTATION OF ABOVE IDEA
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(20,0);

        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(n<=3)return dp[n];
        
        for(int i=4;i<=n;i++){
            int max=i;   // number of elements in right subtree will be max-root
            int min=1;  // number of elements in left subtree will be root-min
			
            for(int temp=1;temp<=i;temp++){    // iterating for all rootNodes
                int num1=dp[temp-min];
                int num2=dp[max-temp];
                dp[i]+=num1*num2;   // by permutation and combination logic
            }
        }

        return dp[n];
    }
};


int main(){
    
    return 0;
}