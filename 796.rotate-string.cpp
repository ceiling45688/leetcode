/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;
        if(s==goal) return true;
        for(int i = 0; i <n; i++){
            s=s.substr(1)+s[0];
            if(s==goal) return true;
        }
        return false;

        

    }
};
// @lc code=end

