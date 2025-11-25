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

    int n(TreeNode *temp) {
        int total = 0;
        if(temp == NULL) {
            return 0;
        }else {
            total += 1 + n(temp->left) + n(temp->right);
        }
    return total;
    }
    int f(TreeNode * temp) {
        int total = 0;
        if(temp == NULL) {
            return 0;
        }else {
            total +=  temp->val + f(temp->left) + f(temp->right);
        }
        return total;
    }
    int averageOfSubtree(TreeNode* root) {
        int total = 0;
        if(root == NULL) {
            return 0;
        }else {
            if(root->val == f(root) / n(root)) {
                total += 1 + averageOfSubtree(root->left) + averageOfSubtree(root->right);
            }else {
                return averageOfSubtree(root->left) + averageOfSubtree(root->right);
            }
        }
        return total;
    }
};