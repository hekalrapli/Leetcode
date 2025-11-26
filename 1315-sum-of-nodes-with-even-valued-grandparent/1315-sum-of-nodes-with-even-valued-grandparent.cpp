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
    
    int jumlahKan(TreeNode *gp, int total ) {
        if(gp == NULL) {
            return 0;
        }else {
            if(total == 2) {
                return gp->val;
            }else {
                return jumlahKan(gp->left,total+1) + jumlahKan(gp->right,total+1);
            }
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
   
        if(root ==  NULL) {
            return 0;
        }else {
            if(root->val % 2 == 0) {
               return  jumlahKan(root,0) + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
            }else {
                return sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);

            }

        }
       
        
    }
};