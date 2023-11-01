/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    int max_freq=0;
    void trav(TreeNode* root)
    {
        if(!root) return;
        trav(root->left);
        mp[root->val]++;
        max_freq= max(max_freq,mp[root->val]);
        trav(root->right);
    }
    vector<int> findMode(TreeNode* root) 
    {
        trav(root);
        vector<int> ans;
        for(auto x:mp)
        {
            if(x.second==max_freq)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }

};