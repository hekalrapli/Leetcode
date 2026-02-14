class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp;
  for(int i = 1; i <= 100; i++) {
    vector<double> temp(i,0);
    dp.push_back(temp);
  }

 
  dp[0][0] = poured;
  for(int i = 1; i < 100; i++) {
        for(int j = 0; j < dp[i].size(); j++) {
            if( j-1 >= 0 && j + 1 < dp[i].size()) {
                if(dp[i-1][j-1]-1 > 0 && dp[i-1][j]-1 > 0) {
                    dp[i][j] = ((dp[i-1][j-1]-1)/2) + ((dp[i-1][j]-1)/2); 
                }else if(dp[i-1][j-1]-1 > 0) {
                    dp[i][j] = ((dp[i-1][j-1]-1)/2);
                }else if((dp[i-1][j]-1)/2 > 0){
                    dp[i][j] = ((dp[i-1][j]-1)/2);
                }else {
                    dp[i][j] = 0;
                }
            }
            else if(j-1 >= 0) {
                if(((dp[i-1][j-1]-1)/2) > 0) {
                    dp[i][j] = (dp[i-1][j-1]-1)/2 ;
                }else {
                  dp[i][j] = 0;
                    
                }
 
            }else {
                if((dp[i-1][j]-1)/2 > 0) {
                    dp[i][j] = (dp[i-1][j]-1)/2;
                }else {
                    dp[i][j] = 0;
                }

            }
        }
  }
   
        if(dp[query_row][query_glass] > 1) {
            return 1;
        }else {
        return dp[query_row][query_glass];
        }
    

    }
};