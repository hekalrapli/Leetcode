class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long maks =  nums[nums.size()-1];
        long long minim = nums[0];
        return (maks -minim) * k;
    }
};