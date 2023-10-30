class Solution {
public:
    int countSetBits(int n)
    {
        // base case
        if (n == 0)
            return 0;
        else
            // if last bit set add 1 else add 0
            return (n & 1) + countSetBits(n >> 1);
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        int n=arr.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            int k= countSetBits(arr[i]);
            mp[k].push_back(arr[i]);
        }
        vector<int> ans;
        for(auto x:mp)
        {
            sort(x.second.begin(),x.second.end());
            for(auto y:x.second)
            {
                ans.push_back(y);
            }
        }

        return ans;
    }
};