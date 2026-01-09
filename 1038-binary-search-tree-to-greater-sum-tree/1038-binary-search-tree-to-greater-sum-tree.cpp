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

    int sum(TreeNode * root) {
        if(root == NULL) {
            return 0;
        }else {
                return root->val + sum(root->right) + sum(root->left);

        }
    }

    void f(TreeNode *root, vector<int>  &temp) {
        if(root == NULL) {
            return;
        }else {
            temp.push_back(root->val);
            f(root->left, temp);
            f(root->right, temp);
        }
    }

    int cnt(vector<int> temp, int total, int curr) {
        int res = total;
        for(int i = 0; i < temp.size(); i++) {
            if(curr > temp[i]) {
                res -= temp[i];
            }
        }
        return res;
    }

    void changeNode(TreeNode * root, TreeNode * curr, vector<int> temp, int total) {
        if(curr == NULL) return;
        curr->val = cnt(temp,total,curr->val);
        changeNode(root, curr->left, temp, total);
        changeNode(root, curr->right, temp, total);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
     vector<int> temp;
     f(root,temp);
     sort(temp.begin(),temp.end());
     int total = sum(root);
     changeNode(root,root, temp, total);


    return root;
    }

};