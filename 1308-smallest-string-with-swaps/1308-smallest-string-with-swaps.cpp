class Solution {
public:
    map<int,int>parent;
    int find(int a){
        if(a==parent[a])return a;
        else return find(parent[a]);
    }
    void Union(int a,int b,map<int,int>&rank){
        int x=find(a),y=find(b);
        if(x==y)return;
        if(rank[x]==rank[y]){
            parent[y]=x;
            rank[x]++;
        }
        else if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else{
            parent[x]=y;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        map<int,int>rank;
        int n=s.size(),m=pairs.size();
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<m;i++){
            Union(pairs[i][0],pairs[i][1],rank);
        }
        map<int,priority_queue<char,vector<char>,greater<char>>>mp;

        for(int i=0;i<n;i++){
            int a=find(i);
            mp[a].push(s[i]);
        }
        string res="";
        for(int i=0;i<n;i++){
            int a=find(i);
            res+=mp[a].top();
            mp[a].pop();
        }
        return res;
    }
};

    // Please Upvote if it helps..Thank You 