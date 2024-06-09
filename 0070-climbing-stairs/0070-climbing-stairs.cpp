class Solution {
public:
    int climbStairs(int n) {
        int prev1=1,prev2=2;
        if(n<=2) return n;
        int next;
        for(int i=2;i<n;i++)
        {
            next= prev2+prev1;
            prev1=prev2;
            prev2=next;
        }

        return next;
    }
};