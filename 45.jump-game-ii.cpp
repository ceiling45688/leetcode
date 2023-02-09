/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
/* Greedy Algorithm:
key: 用尽可能少的步数增加覆盖范围，直到终点，增加了几次覆盖范围就是跳几步

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int cur=0; // curent cover, if cur_cover is finished, start next_cover
        int next=0; // next cover 
        int result=0; // jump count
        for(int i=0; i<nums.size(); i++){
            next = max(next, i+nums[i]); // update next max cover distance
            
            if(i==cur){//end current cover loop
                if(cur != nums.size()-1){
                    result++;
                    cur=next; // update current cover
                    if(cur>=nums.size()-1) break;
                }else{
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

