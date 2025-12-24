class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> temp;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            temp[nums[i]]++;
        }
        for(const auto x : temp ) {
            if(x.second == 2)res.push_back(x.first);
       
        }
        return res;
        
    }
};