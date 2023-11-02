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
    int sum=0,count=0,num=0;
    void av(TreeNode* root)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        num++;
        av(root->left);
        av(root->right);
    }
    void dfs(TreeNode* root)
    {
          if(root==NULL)
            return;
            av(root);
        if(sum/num==root->val)
            count++;
        sum=0;num=0;
        dfs(root->left);
        dfs(root->right);
    }
    int averageOfSubtree(TreeNode* root) 
    {
        dfs(root);
        return count;
    }
};