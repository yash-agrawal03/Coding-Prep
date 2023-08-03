class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        unordered_map<int,vector<int>> mp;
        int n=routes.size();
        int s;
        for(int i=0;i<n;i++)
        {
            for(auto x:routes[i])
            {
                mp[x].push_back(i);
                s=max(s,x);
            }
        }
        
        int ans=0;
        queue<int> q;
        vector<int> buses(n,0);
        vector<int> stations(s+1,0);
        stations[source]=1;
        q.push(source);
        while(!q.empty())
        {
            int k=q.size();
            ans++;
            while(k--)
            {
                int t=q.front();
                //cout<<t<<endl;
                if(t==target)
                {
                    return ans-1;
                }
                q.pop();
                for(auto x:mp[t])
                {
                    if(!buses[x])
                    {
                        buses[x]=1;
                        for(auto y:routes[x])
                        {
                            //cout<<y<<endl;
                            if(!stations[y])
                            {
                                stations[y]=1;
                                q.push(y);
                            }
                        }
                    }
                    
                }
            }
        }

        return -1;
    }
};
// 