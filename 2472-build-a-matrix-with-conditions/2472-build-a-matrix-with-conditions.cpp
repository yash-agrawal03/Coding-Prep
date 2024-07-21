class Solution {
public:
vector<int> toposort(vector<vector<int>>& adj,int k){
    vector<int> ans,emp;
    queue<int> q;
    vector<int> indegree(k);
    for(auto v:adj){
        for(auto i:v) indegree[i]++;
    }
    for(int i=0;i<k;i++) if(indegree[i]==0) q.push(i);
    while(!q.empty()){
        int node=q.front();q.pop();
        ans.push_back(node);
        for(auto v:adj[node]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return ans.size()==k?ans:emp;
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n=rowConditions.size(),m=colConditions.size();
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<vector<int>> adj1(k),adj2(k);
        for(auto v:rowConditions){
            adj1[v[0]-1].push_back(v[1]-1);
        }
        for(auto v:colConditions){
            adj2[v[0]-1].push_back(v[1]-1);
        }
        vector<int> row=toposort(adj1,k);
        vector<int> col=toposort(adj2,k);
        if(row.size()==0 || col.size()==0) return {};
        vector<pair<int,int>> position(k);
        for(int i=0;i<k;i++){
            position[row[i]].first=i;
            position[col[i]].second=i;
        }
        for(int i=0;i<k;i++){
            int r=position[i].first,c=position[i].second;
            ans[r][c]=i+1;
        }
        return ans;
    }
};