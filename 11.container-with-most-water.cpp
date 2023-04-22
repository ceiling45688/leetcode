/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        //methond2: two pointers
        // Move the pointer of the smaller height
        int maxArea = 0;
        int left = 0, right = height.size()-1;
        while(left < right) {
            maxArea  = max(maxArea, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};
// @lc code=end

