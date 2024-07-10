class Solution {
public:
    int minOperations(vector<string>& logs) {

        int ops=0;
        int n=logs.size();
        for(int i=0;i<n;i++)
        {
            if(logs[i][1]=='.')
            {
                if(ops>0)
                ops--;
                else
                ops=0;
            }
            else if(logs[i][0]!='.')
            {
                ops++;
            }
        }

        return ops;
    }
};