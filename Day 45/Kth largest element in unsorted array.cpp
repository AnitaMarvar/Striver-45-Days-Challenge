class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
       //largest --- > minheap
       
       priority_queue<int,vector<int>, greater<int>>minHeap;
       for(int i=0;i<arr.size();i++)
       {
           minHeap.push(arr[i]);
           if(minHeap.size() > k)
           {
               minHeap.pop();
           }
       }
       return minHeap.top();
       
        
    }
};
