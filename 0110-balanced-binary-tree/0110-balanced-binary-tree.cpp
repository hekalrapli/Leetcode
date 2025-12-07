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

    int nbElm(TreeNode * temp) {
        if(temp == NULL) {
            return 0;
        } 
        return 1 +  max(nbElm(temp->left),nbElm(temp->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }else {
            if(abs(nbElm(root->left) - nbElm(root->right)) > 1) {
                return false;
            }else {
                return isBalanced(root->left) && isBalanced(root->right);
            }


        }
    }
};