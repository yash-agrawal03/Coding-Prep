class Solution {
public:
    vector<vector<int>> ans;
    void generate(int n) 
    {
        ans.push_back({1});
        if(n>1) ans.push_back({1,1});
        for(int i=2;i<n;i++)
        {
            vector<int> v;
            v.push_back(1);
            for(int j=0;j<ans[i-1].size()-1;j++)
            {
                v.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
    }
    vector<int> getRow(int n) 
    {
        generate(n+1);
        return ans[n];
    }
};