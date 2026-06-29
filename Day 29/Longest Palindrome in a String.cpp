class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;

        for(char ch : s)
        {
            mp[ch]++;
        }
        bool oddFound = false;

        int ans=0;
        for(auto it : mp)
        {
            if(it.second % 2 == 0)
            {
                ans += it.second;
            }
            else{
                oddFound = true;
                ans += it.second-1;
            }
        }
        if(oddFound) ans += 1;
        return ans;
    }
};
