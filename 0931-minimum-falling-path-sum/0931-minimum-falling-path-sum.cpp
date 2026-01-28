class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
        for(int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
               if(j-1 >= 0 && j + 1 < n) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j+1], dp[i-1][j])) + matrix[i][j];
               }else if(j+1 < n) {
                dp[i][j] =  min(dp[i-1][j+1], dp[i-1][j]) + matrix[i][j];
               }else if(j-1 >= 0) {
            
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];
               }
            }

        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(dp[n-1][i] < res) res = dp[n-1][i];
        }

        

        return res;
    }
};