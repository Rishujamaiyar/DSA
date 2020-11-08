"""Find the duplicate in an array of N+1 integers.
Brute:   Sort the array / frequency array
Optimal: fast and slow pointer (if duplicate elements exists there would be a loop in the circular traversal of the array, so
        Start from the first point run till they meet, assign fast to the first pointer then run again till they meet wherever they’ll
        meet would be the duplicate point ,return that point.
Optimal 2: Use the existing array as the frequency array by making the values at the indices 
        negative and then if at any index the value is already negative then that value is duplicate"""




class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      for(int i=0;i < nums.size();i++){
          if(nums[abs(nums[i])]<0)
              return abs(nums[i]);
          else
            nums[abs(nums[i])] = -nums[abs(nums[i])];
      }
        return 1;
      }
};
