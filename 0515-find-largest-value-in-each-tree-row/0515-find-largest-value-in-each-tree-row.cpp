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

    int Level(TreeNode * root) {
        if(root == NULL) {
            return 0;
        }else {
            return 1 + max(Level(root->left), Level(root->right));
        }
    }

    void add(TreeNode* root, int n, vector<int> &temp) {
        if(root == NULL) {
            return;
        }else {
             if(n == 1) {
            temp.push_back(root->val);
        }else {
            add(root->left,n-1,temp);
            add(root->right,n-1,temp);
        }
        }
       
    }
    vector<int> largestValues(TreeNode* root) {
        int lv = Level(root);
        vector<int> res;
        for(int  i = 1; i <= lv; i++) {
             vector<int> temp;
            add(root, i,temp);
             sort(temp.begin(), temp.end(), greater<int>());
             res.push_back(temp[0]);
        }
        return res;
    }
};