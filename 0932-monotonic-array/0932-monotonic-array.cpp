class Solution {
public:
    bool isMonotonic(vector<int>& a) 
    {
        return(is_sorted(a.begin(), a.end()) || is_sorted(a.rbegin(), a.rend()));
    }
};