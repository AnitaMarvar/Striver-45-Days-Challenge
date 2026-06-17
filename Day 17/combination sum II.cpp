class Solution {
public:
    void solve(vector<int>& can, int target, vector<vector<int>>&ans, vector<int>&level, int ind, int sum)
    {
        if(sum==target)
        {
            ans.push_back(level);
            return;
        }

        if(ind >= can.size() || sum > target)
            return;


        level.push_back(can[ind]);
        solve(can, target, ans, level, ind+1, sum+can[ind]);
        level.pop_back();

        while(ind+1 < can.size() && can[ind] == can[ind+1])
        {
            ind++;
        }
        solve(can, target, ans, level, ind+1, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        vector<int>level;

        solve(candidates, target, ans, level, 0,0);

        return ans;
    }
};
