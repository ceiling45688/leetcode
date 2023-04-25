/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    // stack1 to store 
    stack<int> stack1, stack2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        while(stack1.size()>1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int top_element = stack1.top();
        stack1.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return top_element;
    }
    
    int peek() {
        // return the front element of the queue
        while(stack1.size()>1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int top_element = stack1.top();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return top_element;
    }
    
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

