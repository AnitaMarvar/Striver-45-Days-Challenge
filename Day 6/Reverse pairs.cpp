class Solution {
public:
    int merge(vector<int>& nums, int l, int mid, int r)
    {
        vector<int>temp;
        int left = l;
        int right = mid+1;
        int cnt=0;

        right = mid+1;
        for(int i = l ; i<=mid;i++)
        {
            while(right <= r && (long long)nums[i] > 2LL * nums[right])
            {
                right++;
            }
            cnt += (right - (mid + 1)); 
        }

        left = l;
        right = mid+1;

        while(left <= mid && right <= r)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid)
        {
            temp.push_back(nums[left]);
                left++;
        }
        while(right <= r)
        {
            temp.push_back(nums[right]);
                right++;
        }
        for(int i=l;i<=r;i++)
        {
            nums[i] = temp[i-l];
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int l, int r)
    {
        if(l>=r)
        {
            return 0;
        }
        int mid = l + (r-l)/2;
        int cnt=0;

        cnt += mergeSort(nums,l,mid);
        cnt += mergeSort(nums, mid+1, r);

        cnt += merge(nums, l, mid, r);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);

    }
};
