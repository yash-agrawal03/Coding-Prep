class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int sum=0,temp=0;int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                sum=max(sum,temp);
                temp=0;
            }
            else
            {
                temp++;
            }
           // cout<<i<<" "<<temp<<endl;
        }
        sum=max(sum,temp);
        return sum;
    }
};