class Solution {
public:
    bool check(vector<int>& nums, int th, int mid)
    {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(ceil((double)nums[i]/mid));
        }
        if(sum<=th)
        {
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n=nums.size();
        int ans=1;
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid= l +(r-l)/2;
           // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(check(nums,threshold,mid))
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
};