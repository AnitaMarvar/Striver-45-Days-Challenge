//closest to the given question

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int>ans;
        int n=arr.size();
        
        unordered_map<int,int>mp;
        
        //first window
        for(int i=0;i<k;i++)
        {
            int ele = arr[i];
            mp[ele]++;
        }
        
        ans.push_back(mp.size());
        
        for(int i=k;i<n;i++)
        {
            int removeEle = arr[i-k];
            int addEle = arr[i];
            mp[removeEle]--;
            
            if(mp[removeEle] == 0)
            {
                mp.erase(removeEle);
            }
            mp[addEle]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};
