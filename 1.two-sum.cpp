/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // method3: two pointers
        // sort the array, init the left and right pointers
        // if L+R < target, L++
        // if L+R > target, R++
        // if L+R == target, return l and r,  and repeat this step until l = r
        // ***this algorithm time complexity is O(nlog n) and nlogn is for the sort algorithm
        vector<int> sorted_nums(nums);
        vector<int> result;
        sort(sorted_nums.begin(), sorted_nums.end());
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int sum = sorted_nums[left]+sorted_nums[right];
            //*** if found, need to iterate through the orginal array to find their indexes 
            if(sum == target){
                // find the left index
                for(int i=0; i<nums.size(); i++){
                    if(nums[i] == sorted_nums[left]){
                        result.push_back(i);
                        break;
                    }
                }
                // find the right index
                for(int i=nums.size()-1; i>=0;i--){
                    if(nums[i] == sorted_nums[right]){
                        result.push_back(i);
                        break;
                    }
                }
                break;
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};
// @lc code=end

