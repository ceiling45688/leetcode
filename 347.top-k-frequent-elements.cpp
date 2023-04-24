/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        // count frequencies of elements
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        // Use a min heap (priority_queue with custom comparator)
        auto cmp  = [](const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp); // 第三个参数用cmp实现降序
        
        // 将键值对插入小根堆minHeap，得到前k个频率（value）的
        for(auto entry : map){
            // entry 为从map遍历得到的键值对
            pq.push(entry);
            if(pq.size() > k){
                pq.pop();
            }
        }
        //
        vector<int> results;
        while(!pq.empty()){
            results.push_back(pq.top().first);
            pq.pop();
        }
        return results;

    }
};
// @lc code=end
// method: hashmap + minHeap

