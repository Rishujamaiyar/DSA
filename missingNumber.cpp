"""Repeat and Missing Number
Use map for counting frequency
Use index of the array as map (set value at visited indices negative)
"""






class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int res = nums.size();
    for(int i=0; i<nums.size(); i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}
};
