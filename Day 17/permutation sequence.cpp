//tle hora hai
class Solution {
public:
    void solve(string &s, vector<string>&ans, int ind)
    {
        if(ind == s.length())
        {
            ans.push_back(s);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            swap(s[i], s[ind]);
            solve(s, ans, ind+1);
            swap(s[i], s[ind]);
        }
    }
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++)
        {
            s+=(i+'0');
        }
        vector<string>ans;

        solve(s, ans,0);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
