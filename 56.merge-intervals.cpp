/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //method: two pointers
        // 1. sort intervals
        // 2. move pointers, and check overlapping

        vector<vector<int>> results;
        if(intervals.size() == 0) return results;
        
        sort(intervals.begin(), intervals.end());
        
        int i=0, j=1;
        while(j<intervals.size()) {
            // if overlapping, merge
            if(intervals[i][1]>=intervals[j][0]){
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
            }else{
                results.push_back(intervals[i]);
                i=j;
            }
            j++;
        }
        //add the last interval
        results.push_back(intervals[i]);

        return results;
    }
};
// @lc code=end

