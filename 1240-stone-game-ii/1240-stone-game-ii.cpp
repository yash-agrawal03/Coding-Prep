class Solution {
public:
    int dp[101][201];
    int solve(vector<int> &piles, int start, int m, int total)
    {
        int n=piles.size();
        if(dp[start][m]!=-1) return dp[start][m];
        int mx=0,coins=0;
        for(int j=start ; j< min(start+2*m,n);j++)
        {
            coins+=piles[j];
            mx=max(mx,total-solve(piles,j+1,max(j+1-start,m),total-coins));
        }
        return dp[start][m]=mx;
    }
    int stoneGameII(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int total = accumulate(piles.begin(),piles.end(),0);
        return solve(piles,0,1,total);
    }
};
// dp[start][m]= ans for array starting from start with M = m 