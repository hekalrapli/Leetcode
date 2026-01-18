class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      
        vector<int> res;
        
        int m = mat.size();
        int n = mat[0].size();

        int trck = 1;
            for(int i = 0; i < m; i++) {
                int c = 0;
                if(i > 0) {
                    c =n -1;
                }
                for(int j = c; j < n; j++) {
                    vector<int> temp;
                    int x = i;
                    int y = j;
                    while(x < m && y < n && x >= 0 && y >= 0) {
                        temp.push_back(mat[x][y]);
                        x++;
                        y--;
                    }
                    if(trck == 1) {
                        for(int tmp = temp.size()-1; tmp >= 0; tmp--) {
                            res.push_back(temp[tmp]);
                        }
                        trck = 0;
                    }else {
                        for(int tmp = 0; tmp < temp.size(); tmp++) {
                            res.push_back(temp[tmp]);
                        }
                    trck = 1;
                    }
                 
                }
            }

        
    return res;


    }
};