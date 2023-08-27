#define ll long long
class Solution {
public:
    vector<ll> dijickstra(vector<pair<ll,ll>> adj[], ll n, ll src)
    {
        vector<ll> dist(n,1e18);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            auto x= pq.top(); pq.pop();
            ll wt= x.first;
            ll node= x.second;
            if(dist[node]<wt) continue;
            for(auto y:adj[node])
            {
                ll dis= wt+ y.second;
                if(dis<dist[y.first])
                {
                    dist[y.first]=dis;
                    pq.push({dis,y.first});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<pair<ll,ll>> adj[n],rev[n];
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            rev[x[1]].push_back({x[0],x[2]});
        }
        vector<ll> dist1= dijickstra(adj,n,src1);
        vector<ll> dist2= dijickstra(adj,n,src2);
        vector<ll> dist3= dijickstra(rev,n,dest);
        ll ans=1e18;
        for(int i=0;i<n;i++)
        {
            ans= min(ans,dist1[i]+dist2[i]+dist3[i]);
        }
        if(ans==1e18)
        {
            return -1;
        }
        return ans;
    }
};