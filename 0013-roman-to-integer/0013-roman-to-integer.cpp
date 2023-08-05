class Solution {
public:
    int getInteger(char c)
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return -1;
        }
    }
    int romanToInt(string s) 
    {
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            if(i==n-1)
            {
                return ans+getInteger(s[i]);
            }
            int curr=getInteger(s[i]),next=getInteger(s[i+1]);
            if(curr>=next)
            {
                ans+=curr;
                i++;
            }
            else
            {
                ans+=(next-curr);
                i+=2;
            }
        }

        return ans;
    }
};