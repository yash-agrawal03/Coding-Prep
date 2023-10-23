class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n<=0) return 0;
        double k= (double)log(n)/(double)log(4);
        cout<<k<<endl;
        long long temp = (long long)k;

        if(temp==k) return 1;
        else return 0;
       // return 0;
    }
};