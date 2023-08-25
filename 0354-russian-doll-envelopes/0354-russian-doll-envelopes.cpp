 bool cmp(vector<int> v1,vector<int> v2)
{
    if(v1[0]==v2[0])
    {
        return v1[1]>v2[1];
    }
    else
    {
        return v1[0]<v2[0];
    }
}
class Solution {
public:
    int longestCommonSubsequence(vector<int> heights)
    {
        int n=heights.size();
        if(n==0) return 0;
        vector<int> ans;
        ans.push_back(heights[0]);
        for(int i=1;i<n;i++)
        {
            if(heights[i]>ans.back())
            {
                ans.push_back(heights[i]);
            }
            else
            {
                int ind= lower_bound(ans.begin(),ans.end(),heights[i])-ans.begin();
                ans[ind]= heights[i];
            }
        }
        return ans.size();
    }
   
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> temp;
        for(int i=0;i<envelopes.size();i++)
        {
            temp.push_back(envelopes[i][1]);
        }
        return longestCommonSubsequence(temp);
    }
};