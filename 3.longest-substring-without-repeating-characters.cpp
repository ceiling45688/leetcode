/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // method: two pointers
        // hashmap to store the last position of each character, default is null
        // if there is repeated character, renew the i pointer, i = max(i, hashmap[s[j]]+1)
        // max_len = max(max_len, j-i+1)
        // renew j in hashmap s[j], hashmap[s[j]] =j 
        // loop until reached the end of the string
        // time complexity is O (n)
        int n = s.length();
        if(n == 0) return 0; //
        int i = 0, j = 0, max_len=0;
        unordered_map<char, int> map;
        while(j<n){
            // if there is a repeated character 
            // && the last position of s[j] is between i and j
            if(map.count(s[j]) && map[s[j]] >= i){
                i = max(i, map[s[j]] + 1);
            }
            map[s[j]] = j;
            max_len = max(max_len, j-i+1);
            j++;
        }
        return max_len;
        
    }
};
// @lc code=end

