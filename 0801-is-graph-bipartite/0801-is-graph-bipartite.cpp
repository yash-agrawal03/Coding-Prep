class Solution {
public:

    bool dfs(vector<vector<int>>& graph,vector<int> &col, int c,int i)
    {
        col[i]=c;
        for(auto x:graph[i])
        {
            if(col[x]==-1)
            {
                if(!dfs(graph,col,!c,x))
                {
                    return false;
                }
            }
            else if(col[x]==c)
            {
                return false;
            }
           
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> col(n,-1);

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1 and dfs(graph,col,1,i)==false)
            {
                return false;

            }
        }

        return true;
    }
};