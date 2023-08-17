class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count=1;
        int prev_elem=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev_elem)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                prev_elem=nums[i];
                count=1;
            }
        }
        return prev_elem;
    }
};