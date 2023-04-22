/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // method1： two pointers
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        // k is from [0, nums.size()-2]
        for(int i = 0; i < nums.size()-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;//
            int target = -nums[i];
            int left = i+1, right = nums.size()-1;
            while (left < right){
               int sum = nums[left]+nums[right];
               if(sum == target){
                result.push_back({nums[i], nums[left], nums[right]});
                do{left++;} while(left < right && nums[left] == nums[left-1]); 
                do{right--;} while(left < right && nums[right] == nums[right+1]);
               }else if(sum < target){
                left++;
               }else{
                right--;
               }
            }
        }
        return result;
        
    }
};
// @lc code=end

