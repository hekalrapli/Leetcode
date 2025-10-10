class Solution {
public:
int temp(vector<int> &energy, int i, int k, vector<int>& dp) {
   
     if(i + k >= energy.size()) return energy[i];
     if(dp[i] != -1) return dp[i];
     
     
     dp[i] = energy[i] + temp(energy, i+k, k,dp);
     return dp[i];
}
    int maximumEnergy(vector<int>& energy, int k) {
         int maks = INT_MIN;
           vector<int> dp(energy.size(),-1);
  for(int i = 0; i < energy.size(); i++) {
    maks = max(maks,temp(energy,i,k,dp));
     // maks = max(maks,temp(energy,i,k));
  }
  return maks;
    }
};