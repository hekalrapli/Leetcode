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
    int maks_depth(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }else {
            return 1 + max(maks_depth(root->left), maks_depth(root->right));
        }
    }
    int count_depth(TreeNode* root, int curr, int tingkat) {
        int total = 0;
        if(root == NULL) {
            return 0;
        }else if(curr == tingkat) {
            total += root->val;
        }else {
            return count_depth(root->left,curr+1,tingkat) + count_depth(root->right,curr+1,tingkat) ;
        }
        return total;

        
    }
    int deepestLeavesSum(TreeNode* root) {
        TreeNode *temp = root;
        int tingkat = maks_depth(root);
        int total = 0;
        return count_depth(root,1,tingkat);
        
   
    }
};