class Solution {
public:

    int solve(int i,int j, vector<vector<int>> &A,vector<vector<int>> &dp)
    {
        int n=A.size(),m=A[0].size();

        if(i>=n or j>=m) return INT_MIN;

        int ans=0;

        if(i==n-1 and j==m-1) return min(0,ans+A[i][j]);

        if(dp[i][j]!=-1) return dp[i][j];

        ans= min(0, A[i][j]+ max(solve(i+1,j,A,dp),solve(i,j+1,A,dp)));

        return dp[i][j]= ans;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int n=dungeon.size();
        int m=dungeon[0].size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

        return abs(solve(0,0,dungeon,dp)) +1;
    }
};