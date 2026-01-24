class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            res.push_back(nums[i] + nums[nums.size()-1-i]);
        }
        sort(res.begin(),res.end());
        return res[res.size()-1];
    }
};

