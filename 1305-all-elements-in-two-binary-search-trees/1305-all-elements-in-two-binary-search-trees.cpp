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

    void  pushEl(TreeNode* temp, vector<int> &arr) {
        if(temp == NULL) {
            return;
        }else {
            arr.push_back(temp->val);
            pushEl(temp->left, arr);
            pushEl(temp->right, arr);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        if(root1 == NULL && root2 == NULL) {
            return res;
        }else if(root2  == NULL ) {
            pushEl(root1,res);
            
        }else if(root1 == NULL) {
            pushEl(root2,res);
        }else {
            pushEl(root1,res);
            pushEl(root2,res);

        }
        sort(res.begin(), res.end());
        return res;
    }
};