class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> st;
        map<char,int> mp;
        char prev=s[0];
        st.push({s[0],1});
        int c=1;
        for(int i=1;i<s.size();i++)
        {
            if(st.size())
            {
                prev=st.top().first;
                c=st.top().second;
            }
            if(s[i]==prev)
            {
                st.push({prev,c+1});
                c++;
            }
            else
            {
                st.push({s[i],1});
            }
            if(c==k)
            {
                while(st.size() and st.top().first==prev)
                {
                    st.pop();
                }
            }
        }
        string ans="";
        while(st.size())
        {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// dd bbb d aa