class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int end_mask=((1<<n)-1);
        set<pair<int,int>> st;
        for(int i=0;i<graph.size();i++)
        {
            int mask= (1<<i);
            q.push({i,{0,mask}});
            st.insert({i,mask});
        }
        while(!q.empty())
        {
            auto top=q.front(); q.pop();
            int node= top.first;
            int dist= top.second.first;
            int mask= top.second.second;

            if(mask==end_mask)
            {
                return dist;
            }
            for(auto x:graph[node])
            {
                int tmp= (1<<x);
                int m= tmp|mask;
                if(st.count({x,m})) continue;
                q.push({x,{dist+1,m}});
                st.insert({x,m});
            }
        }
        return 0;
    }
};