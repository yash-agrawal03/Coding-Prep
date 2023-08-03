class Solution {
public:
    int dp[101][2][201];
    int solve(int i,bool a,int m,vector<int>& piles)
    {
        if(i>=piles.size())
        {
            return 0;
        }
        if(dp[i][a][m]!=-1)
        {
            return dp[i][a][m];
        }
    if(a==0)
    {
        int ans=0;
        int sum=0;
        for(int x=1;x<=2*m && i+x-1<piles.size();x++)
        {
            sum+=piles[i+x-1];
            int M=max(m,x);
            ans=max(ans,sum+solve(i+x,1,M,piles));
            
        }  
        return dp[i][a][m]=ans;
    }
    else
    {
        int ans=INT_MAX;
        for(int x=1;x<=2*m;x++)
        {
            int M=max(m,x);
            ans=min(ans,solve(i+x,0,M,piles));
        }
        return dp[i][a][m]=ans;
    }
    }

    int stoneGameII(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,piles);  
    }
};
//***************PLEASE UPVOTE IF FOUND USEFUL************************