class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=INT_MIN;
        unordered_map<int,unordered_map<int,int>> mp;

        for(int i=0;i<n;i++)    
        {
            for(int j=i+1;j<n;j++)
            {
                int diff= nums[j]-nums[i];
                if(mp[diff].find(i)!=mp[diff].end())
                {
                    mp[diff][j]=mp[diff][i]+1;
                }
                else
                {
                    mp[diff][j]=2;
                }
                ans=max(ans,mp[diff][j]);
            }
        }
        
        return ans;
    }
};