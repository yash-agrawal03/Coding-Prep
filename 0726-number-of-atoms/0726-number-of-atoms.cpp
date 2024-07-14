class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string,int>> st;
        map<string, int> mp;
        int n = formula.size();
        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(mp);
                mp.clear();
                i++;
            } 
            else if (formula[i] == ')') {
                i++;
                int val = 0;
                while (i < n && isdigit(formula[i])) {
                    val = val * 10 + formula[i] - '0';
                    i++;
                }
                if (val == 0) val = 1;
                map<string, int> mp1 = mp;
                mp = st.top();
                st.pop();
                for (auto &p : mp1) mp[p.first] += p.second * val;
            } 
            else {
                string s;
                s.push_back(formula[i++]);
                while (i < n && islower(formula[i])) s+=formula[i++];
                int val = 0;
                while (i < n && isdigit(formula[i])) {
                    val = val * 10 + formula[i] - '0';
                    i++;
                }
                if (val == 0) val = 1;
                mp[s]+=val;
            }
        }
        string ans;
        for (auto &p : mp) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }
        return ans;
    }
};