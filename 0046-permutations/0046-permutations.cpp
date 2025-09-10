class Solution {
public:
    void solve(vector<int> &nums,vector<int> &temp,vector<vector<int>> &result,int n, int index) {
    if(temp.size() >= n ) result.push_back(temp);

    for(int i = 0; i < n; i++) {
        auto it = std::find(temp.begin(), temp.end(), nums[i]);
        if(it != temp.end()) {
            continue;
        }
        temp.push_back(nums[i]);
        solve(nums,temp,result,n,index+1);
        temp.pop_back();

    }
    


}
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;
     solve(nums,temp,result,nums.size(), 0);
     return result;
    }
};