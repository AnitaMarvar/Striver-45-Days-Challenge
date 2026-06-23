class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //maxheap
        priority_queue<pair<int,int>>pq;

        unordered_map<int,int>mp;
        for(int x : nums)
        {
            mp[x]++;
        }
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        vector<int>ans;
        while(k-- && !pq.empty())
        {
            auto top1 = pq.top();
            ans.push_back(top1.second);
            pq.pop();
        }
        return ans;
    }
};
