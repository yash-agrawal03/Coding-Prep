class Solution {
public:
    bool isvalid(int i,int j,int n,int m)
    {
        return i>=0 and j>=0 and i<n and j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> dist(n,vector<int> (m));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty())
        {
            auto it= q.front();q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int w=it.second;
            dist[x][y]=w;
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];

                if(isvalid(newx,newy,n,m) and !vis[newx][newy])
                {   
                    vis[newx][newy]=1;
                    q.push({{newx,newy},w+1});
                }
            }
        }

        return dist;
        

    }
};
// 0 1 0
// 0 1 0
// 0 1 0
// 0 1 0
