class MinStack {
public:
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int32_t val) {
        if (val < min) {
            min = val;
        }

        items.push_back(val);
    }
    
    void pop() {
        if (items.size() == 1) {
            min = INT_MAX;
            items.pop_back();
            return;
        }

        if (items[items.size() - 1] == min) {
            vector<int> temp = items;
            sort(temp.begin(), temp.end() - 1);

            min = temp[0];
        }

        items.pop_back();
    }
    
    int top() {
        return items[items.size() - 1];
    }
    
    int getMin() {
        return min;
    }

private:
    int32_t min;
    vector<int32_t> items;
};

