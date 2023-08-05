class Solution {
public:
    
    bool isIsomorphic(string s, string t) 
    {
        map<char,char> mp;
        set<int> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                if(mp[s[i]]!=t[i])
                {
                    //cout<<mp[s[i]]<<" "<<t[i]<<endl;
                    return false;
                }
            }
            else
            {
                if(st.find(t[i])==st.end())
                {
                    mp[s[i]]=t[i];
                    st.insert(t[i]);
                }
                else 
                {
                    return false;
                }
            }
        }
        return 1;
    }
};
// b->b
// a->a
// d->b
// 