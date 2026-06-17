class Solution {
public:
    int n;
    bool isPalindrome(string &s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string &s, vector<string>&curr, vector<vector<string>>&res, int ind)
    {
        if(ind == n)
        {
            res.push_back(curr);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(isPalindrome(s, ind, i))
            {
                curr.push_back(s.substr(ind, i-ind+1));
                backtrack(s, curr, res, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.length();

        vector<vector<string>>res;
        vector<string>curr;
        backtrack(s, curr, res, 0);
        return res;
    }
};
