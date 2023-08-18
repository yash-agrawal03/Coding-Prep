class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x) {
        // Write your code here
        int l=0,r=n-1,ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]>=x)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
            return ans;
    }
    int upperBound(vector<int> arr, int n, int x) {
        // Write your code here
        int l=0,r=n-1,ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]>x)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
            return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int l= lowerBound(nums,nums.size(),target);
        int r=  upperBound(nums,nums.size(),target);
        if(l==n or nums[l]!=target ) return {-1,-1};
        return {l,r-1};

    }
};