/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    queue<int>  queue1, queue2;
    MyStack() {
        
    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        while(queue1.size()>1){
            queue2.push(queue1.front());
            queue1.pop();
        }
        int top_element = queue1.front();
        queue1.pop(); // stack top element
        while(!queue2.empty()){
            queue1.push(queue2.front());
            queue2.pop(); 
        }
        return top_element;
    }
    
    int top() {
        while(queue1.size()>1){
            queue2.push(queue1.front());
            queue1.pop();
        }
        int top_element = queue1.front();
        queue2.push(queue1.front());
        queue1.pop(); 
        while(!queue2.empty()){
            queue1.push(queue2.front());
            queue2.pop();
        }
        return top_element;
    }
    
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
// methods: queue1 to store the elements,
// queue2 to store the elements while pop() and top()

