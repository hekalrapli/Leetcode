class Solution {
public:
    int longestBalanced(vector<int>& nums) {
         int maks = 0;
    for(int i = 0; i < nums.size(); i++) {
        int curr = 0;
        map<int,int> table;
        int odd = 0;
        int even = 0;
        table[nums[i]]++;
        if(nums[i] % 2 == 0) even++;
        else odd++;
        for(int j = i+1; j < nums.size(); j++) {
            if(table[nums[j]] == 0) {
                table[nums[j]]++;
                if(nums[j] % 2 == 0)even++;
                else odd++;
            }
            if(even == odd ) curr = j-i +1;
            maks = max(maks,curr);
        }
    }
    return maks;
    }
};