class Solution {
public:
    void solve(vector<int>& can, int target, int sum, vector<vector<int>>&ans, vector<int>&level, int ind)
    {
        if(ind == can.size())
        {
            if(sum == target){
                ans.push_back(level);
            }
            return;
        }
        if(target >= sum + can[ind]){
            level.push_back(can[ind]);
            solve(can, target, sum+can[ind], ans, level,ind);
            level.pop_back();
        }
        solve(can, target, sum, ans, level, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       int sum=0;
        vector<int>level;
       solve(candidates, target, sum, ans, level, 0); 
       return ans;
    }
};
