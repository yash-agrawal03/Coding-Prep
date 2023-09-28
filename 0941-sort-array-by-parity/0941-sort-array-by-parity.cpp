class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        vector<int> even,odd;
        for(auto x:nums)
        {
            if(x%2) odd.push_back(x);
            else even.push_back(x);
        }
        vector<int> ans;
        for(auto x:even) ans.push_back(x);
        for(auto x:odd) ans.push_back(x);

        return ans;
    }
};