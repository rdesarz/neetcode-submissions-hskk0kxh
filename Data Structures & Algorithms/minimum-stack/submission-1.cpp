class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);

        if(mins.empty() || val<=mins.back()) mins.push_back(val);
    }
    
    void pop() {
        if(mins.back() == arr.back()) mins.pop_back();

        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return mins.back();
    }
private:
    std::vector<int> arr;
    std::vector<int> mins;
};
