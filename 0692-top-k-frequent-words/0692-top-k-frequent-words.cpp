class Solution {
public:


struct comp {
    bool operator()(const pair<int,string> &x, const pair<int,string> &y) const {
        if (x.first != y.first) {
            return x.first < y.first;
        }
 
        return x.second > y.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int> m;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }

        vector<pair<int,string>> vp;

        for(auto e:m) vp.push_back({e.second,e.first});

        sort(vp.begin(),vp.end(),comp());

        vector<string> ans;

        while(k--){
            ans.push_back(vp.back().second);
            vp.pop_back();
        }

        return ans;
        
    }
};