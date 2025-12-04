class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> temp(n*m);
        if(r*c > n *m || r *c < n *m) {
            return mat;
        }
        int cur = 0;
        vector<vector<int>> res(r, vector<int>(c,0));
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                temp[cur] = (mat[i][j]);
                cur++;
            }
        }
        int x = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = temp[x];
                x++;
            }
        }
        return res;
    }
};