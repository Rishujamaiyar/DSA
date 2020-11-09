"""Merge two sorted Arrays without extra space
better:  start from first compare with first of other swap if needed then sort the other using insert sort (to get O(N) complexity)
optimal: gap algo hai/make necessary swaps then sort both individually"""


//Leetcode solution

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n+m-1;
        int i = m-1;
        int j = n-1;
        while(i>=0 && j>=0){
            if(nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
};
