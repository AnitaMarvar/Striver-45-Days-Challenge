class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double>ans;
        
        //left_max_heap
        priority_queue<int>left_max_heap;
        
        //right min heap
        priority_queue<int, vector<int>, greater<int>>right_min_heap;
        
        for(int x : arr)
        {
            if(left_max_heap.empty() || x <= left_max_heap.top())
            {
                left_max_heap.push(x);
            }
            else{
                right_min_heap.push(x);
            }
            
            if(left_max_heap.size() > right_min_heap.size() + 1)
            {
                right_min_heap.push(left_max_heap.top());
                left_max_heap.pop();
            }
            else if(right_min_heap.size() > left_max_heap.size()){
                left_max_heap.push(right_min_heap.top());
                right_min_heap.pop();
            }
            
            if(right_min_heap.size() == left_max_heap.size())
            {
                ans.push_back((right_min_heap.top() + left_max_heap.top())/2.0);
            }
            else{
                ans.push_back(left_max_heap.top());
            }
        }
        return ans;
        
        
    }
};
