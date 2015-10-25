/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root == p || root == q)
            return root;
        if(root->left == NULL && root->right == NULL)
            return NULL;
        TreeNode* tmp = lowestCommonAncestor(root->left, p, q);
        TreeNode* tmp2 = lowestCommonAncestor(root->right, p, q);
        if(tmp && tmp2)
            return root;
        else if(tmp)
            return tmp;
        else if(tmp2)
            return tmp2;
    }
};