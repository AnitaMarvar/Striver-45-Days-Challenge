class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();

        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            //remove out of the window elments
            while(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }

            //remove smaller elements
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            //remaining elemnts in dq
            if(i >= k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
