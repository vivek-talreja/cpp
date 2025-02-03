#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int start=0,end=0, minLen=0;
        while(end<s.size()){
            if(map[s[end]]==0){
                map[s[end]]++;
                end++;
                if(end-start>minLen){
                    minLen=end-start;
                }
            }
            else{
                while(map[s[end]]>0){
                    map[s[start]]--;
                    start++;
                }
                map[s[end]]++;
                end++;
            }
        }
        return minLen;
        
    }
};

int main(){
    Solution sol;
    int length=sol.lengthOfLongestSubstring("abcabcbb");
    cout<<"Length of Longest Substring: "<<length<<endl;
    return 0;
}