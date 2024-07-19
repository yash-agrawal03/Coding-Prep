class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> row,col;
        for(int i=0;i<n;i++)
        {
            int rm= INT_MAX;
            for(int j=0;j<m;j++)
            {
                rm= min(rm,matrix[i][j]);
            }
            row.push_back(rm);
        }
        for(int j=0;j<m;j++)
        {
            int cm= INT_MIN;
            for(int i=0;i<n;i++)
            {
                cm= max(cm,matrix[i][j]);
            }
            col.push_back(cm);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==col[j])
                {
                    ans.push_back(row[i]);
                }
            }
        }

        return ans;


    }
};