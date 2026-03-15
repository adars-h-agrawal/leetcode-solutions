class SmallestInfiniteSet {
private:
    int current;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    set<int> inHeapSet;

public:
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top(); minHeap.pop();
            inHeapSet.erase(smallest);
            return smallest;
        } else {
            return current++;
        }
    }
    
    void addBack(int num) {
        if (num < current && inHeapSet.find(num) == inHeapSet.end()) {
            minHeap.push(num);
            inHeapSet.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */