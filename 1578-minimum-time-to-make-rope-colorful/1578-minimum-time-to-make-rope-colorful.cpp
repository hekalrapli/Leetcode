class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        vector<int> dp(colors.size());
        for(int i = 0; i < neededTime.size(); i++) {
            dp[i] = neededTime[i];
        }
        int total_time = 0;
        for(int i = 0; i < colors.size()-1; i++) {
            if(colors[i] == colors[i+1]) {
                total_time += min(dp[i],dp[i+1]);
                if(dp[i+1] < dp[i]) {
                    dp[i+1] = dp[i];
                }
            }
        }
        
        return total_time;

    }
};

/*
1 3 2 3 4 1 6 8
a a a b a a a a

4 6 8
a a a





*/