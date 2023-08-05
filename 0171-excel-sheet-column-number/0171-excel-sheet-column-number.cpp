class Solution {
public:
    map<char,int> mp;
    void initialize()
    {
        char c='A';
        for(int i=1;i<27;i++)
        {
            mp[c]=i;
            c++;
        }
    }
    int titleToNumber(string columnTitle) 
    {
        initialize();
        int ans=0;
        int n=columnTitle.size();
        for(int i=n-1;i>=0;i--)
        {
            //cout<<pow(26,(n-1)-i)<<endl;
            ans+=pow(26,(n-1)-i)*mp[columnTitle[i]];
        }
        return ans;
    }
};