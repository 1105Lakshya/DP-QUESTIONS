/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/

/*
kuch ni kiaa ek map bannaliaaa size ke according fir jo sabse badda haii us se shuruu kiaa ek ek nikal ke dekkhaaa agar nikal ke jo string bachiii wo exist krtii hai toh
recursively uskka answer nikal ne ko bodiaa jab recursively answer dhundd ke laayyeee toh uskkooo store bhii krliiaa takkiii dubarra uske liyee calculate na krna padeee
*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s , int num ,unordered_map<string ,int> mp[]){
        if(num==1)return 1;
        
        if(mp[num][s]!=-1)return mp[num][s];
        mp[num][s]+=2;
        
        for(int i=0 ;i<num;i++){
            string temp=s;
            temp.erase(i,1);
            if(mp[num-1].find(temp)!=mp[num-1].end()){
                mp[num][s]=max(mp[num][s], 1+solve(temp ,num-1 ,mp));
            }
        }
        return mp[num][s];
    }
    
    
    int longestStrChain(vector<string>& words) {
       unordered_map<string ,int> mp[27];
        
        int n=words.size();
        for(int  i=0 ;i<n ;i++){
            int num=words[i].size();
            mp[num].insert({words[i],-1});     //agla integer dikhaaat hai us word se longest chain
        }


        int ans=0;
        for(int i=26 ;i>0;i--){
            for(auto it:mp[i]){
                if(!mp[i].empty()){
                if(it.second==-1){
                    it.second=solve(it.first,i , mp) ;
                } 
                    ans=max(ans, it.second);
            }
        }
        }
        return ans;       
    }
};


int main(){
    
    return 0;
}