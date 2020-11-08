"""Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 

three arrows low(for 0) med(for 1) high(for 2)
if(arr[med] = 0) swap with low, med++,low++
if(arr[med] = 1) med++
if(arr[med] = 2) swap with high,high-- """


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high = nums.size()-1;
        int low = 0;
        int  i = 0;
      while (i <= high)
            if (nums[i] == 0)
                swap(nums[i++], nums[low++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[high--]);
            else
                i++;
    }    
};
