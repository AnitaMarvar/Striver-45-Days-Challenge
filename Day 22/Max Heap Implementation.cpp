class maxHeap {
  private:
    // Initialize your data members
    

  public:
    priority_queue<int>maxheap;

    void push(int x) {
       maxheap.push(x);
    }

    void pop() {
        if(!maxheap.empty())
        {
            maxheap.pop();
        }
    }

    int peek() {
        if(!maxheap.empty())
        {
            return maxheap.top();
        }
        return -1;
    }

    int size() {
        return maxheap.size();
    }
};
