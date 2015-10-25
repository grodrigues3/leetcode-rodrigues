/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * root)
    
    def make_flat(self, root):
        #flatten the left tree and return a ptr to it
        #flatten the right and return a ptr to it
        if not root:
            return
        rl = root.left
        rr = root.right
        if rl is None and rr is None:
            #leaf's are already flat
            return root
        lf = self.make_flat(root.left)
        rf = self.make_flat(root.right)
        root.left= None
        if lf:
            root.right = lf
            if rf:
                s = lf
                #step down the left subtree
                while s.right is not None:
                    s = s.right
                s.right = rf
        elif rf:
            # no left subtree so just point root's right subtree to flattened
            # right tree
            root.right = rf
        
        return root
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