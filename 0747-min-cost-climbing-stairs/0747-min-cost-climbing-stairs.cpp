class Solution {
public:
    int dp[1001];
    int recurr(int i,vector<int> &cost)
    {
        if(i<0) return 1e9;
        if(dp[i]!=-1) return dp[i];
        if(i==0 || i==1)
        {
            return dp[i]= cost[i];
        }
       // cout<<i<<endl;
        return dp[i]= min(cost[i]+recurr(i-1,cost),cost[i]+recurr(i-2,cost));

    }

    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(recurr(n-1,cost),recurr(n-2,cost));

    }
};