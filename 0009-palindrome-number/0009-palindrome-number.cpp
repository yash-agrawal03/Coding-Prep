class Solution {
public:
    bool isPalindrome(int x) 
    {
        int temp=x;
        long long ans=0;
        while(temp>0)
        {
            ans*=10;
            ans+=temp%10;
            temp=temp/10;
        }
        return ans==x;
    }
};