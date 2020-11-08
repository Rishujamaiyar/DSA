"""Longest Consecutive Sequence
Brute: sort the array then run a loop checking for cons elements
Optimal: create a hashmap/set insert all element in it, run a loop check if arr[i]-1 is 
there in the set if it isnt then its the first element of the series then run a loop 
checking every arr[i]+1 exist in the set ,then ans = max(ans,count)
Return the ans
"""


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set <int> s;
        for(auto x:nums)
            s.insert(x);
        
        for(auto x:nums){
            if(s.find(x-1)==s.end()){
                int j = x;
                while(s.find(j+1)!=s.end())
                    j++;  
                ans = max(ans,j-x+1);
                }      
        }
        
       return ans; 
    }
};
