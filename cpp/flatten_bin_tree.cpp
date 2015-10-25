/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * root)
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        make_flat(root);
    }
    TreeNode* make_flat(TreeNode* root){
        if(!root)
            return NULL;
        TreeNode* rl, *rr, *lf, *rf;
        rl = root->left;
        rr = root->right;
        if(!rl && !rr)
            return root;
        
        lf = make_flat(rl);
        rf = make_flat(rr);
        
        root->left = NULL;
        
        if(lf){
            root->right = lf;
            if(rf){
                TreeNode *s;
                s = lf;
                //step down the left subtree
                while(s->right)
                    s = s->right;
                s->right = rf;
            }
        }
        else if(rf){
            root->right = rf;
        }
        return root;
            
    }
};