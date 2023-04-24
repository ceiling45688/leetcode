/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth smallest Element in an Array
 * ************************
 * 
 *  Heap tips:
 * - First:堆的构建和维护操作可以通过数组来实现，其中每个节点的下标可以按照完全二叉树的规律进行编号。
 * 对于一个下标为 i 的节点，
 * 其左子节点的下标为 2i+1，右子节点的下标为 2i+2，
 * 父节点的下标为 (i-1)/2
 * **** attention: 有 n 个节点的完全二叉树，
 * 它的最后一个非叶子节点的下标是 n/2-1。
 * 因此，从这个节点开始往前遍历，对每一个节点进行堆化操作即可将整个数组构建成一个堆。
 * - second:最小堆的每个节点的值都小于或等于其左右子节点的值。
 * - third: 在实际应用中，可以使用 STL 中的 priority_queue 来实现堆。
 * 
 * method: 堆排序 O(nlogn)- 手动实现堆
 * 1.初始化一个小根堆, 遍历数组，将前k个元素插入小根堆中
 * 2. 遍历数组中剩余元素
 * 如果该元素比小根堆的堆顶元素大，就把堆顶元素弹出，将该元素插入小根堆中
 * 3. 返回小根堆的堆顶元素即可，该元素即为第k大的元素
 * 具体实现时，可以使用STL的priority_queue实现小根堆，也可以手动实现堆。
 * 如果手动实现堆，可以使用heapify方法进行堆化操作，
 * 同时也要注意堆的下标从0开始。
 * 
 */
// @lc code=start
class Solution {
public:
    // build heap, recursively find the smallest
    void heapify(vector<int>& nums, int n, int i){
        int smallest = i; // 小根堆，初始化最小值为根节点
        int left = 2*i+1, right = 2*i + 2;
        
        // find the smallest
        if(left<n && nums[left] < nums[smallest]) smallest=left;
        if(right<n && nums[right] < nums[smallest]) smallest = right;

        // if the smallest != root, then swap
        if(smallest != i){
            swap(nums[i], nums[smallest]);
            //recursion
            heapify(nums, n, smallest);
        }
    }
    void heapSort(vector<int>& nums){
        int n = nums.size();
        // init heap
        // 最后一个非叶子节点为n/2-1
        for(int i=n/2-1; i>=0;i--){
            heapify(nums, n, i);
        }
        // heap sort
        // 每次取出堆顶元素，然后将堆底元素放到堆顶，
        // 然后从堆顶开始往下调整，保证每个节点都符合堆的性质。
        for(int i=n-1; i>=0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0); // 保持堆化
        }

    }
    int findKthLargest(vector<int>& nums, int k) {
       heapSort(nums);
       return nums[k-1];
    }

};
// @lc code=end

