class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n= nums.size()-1;
    map<int, int> temp;
    for(auto x : nums) {
     temp[x]++;
        }
    vector<int> arr;
    for(auto x : temp) {
        arr.push_back(x.first);
    }
    vector<int> dp(arr.size(),0);
    sort(arr.begin(),arr.end());
    if(arr.size() == 1) {
        return temp[arr[0]] * arr[0];
    }
    dp[0] = temp[arr[0]] * arr[0];
    if(arr[1]-1 == arr[0] ) {
        dp[1] = max(dp[0], temp[arr[1]] * arr[1]);
        
    }else {
        dp[1] = max(dp[0], temp[arr[1]] * arr[1] + dp[0]);
        
    }
    for(int i = 2; i < arr.size(); i++) {
        if(arr[i]-1 == arr[i-1]) {
            dp[i] = max(dp[i-1], temp[arr[i]] * arr[i] + dp[i-2]);
        }else {
            dp[i] = max(dp[i-1], temp[arr[i]] * arr[i] + dp[i-1]);
            
        }
    }
    return dp[dp.size()-1];

    

    }
};