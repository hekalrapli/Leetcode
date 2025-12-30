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

    int tinggi(TreeNode * root) {
        if(root == NULL ) {
            return 0;
        }else {
            return 1 + max(tinggi(root->left), tinggi(root->right));
        }
    }

    int JumLevel(TreeNode* root, int n) {
        
        if(root != NULL) {
            if(n ==1) {
                return root->val;
            }else {
                return JumLevel(root->left, n-1) + JumLevel(root->right, n-1);
            }
        }
        
        return 0;
    }
       
    
    int maxLevelSum(TreeNode* root) {
        long long maks = INT_MIN;
        int level_maks = 0;
        for(int i = 1;  i<= tinggi(root); i++) {
            if(JumLevel(root,i) > maks) {
                maks = JumLevel(root,i);
                level_maks = i;
            }
        }
        return level_maks;
      
    }
};