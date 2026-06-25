class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int,int> table;
            vector<int> temp;
            temp.push_back(nums[i]);
            table[nums[i]]++;
            auto it = table.find(target);
            if(it != table.end()) {
                if(it->second > temp.size()/2 )res++;
            }
            for(int j = i+1; j < nums.size(); j++) {
                table[nums[j]]++;
                temp.push_back(nums[j]);
                auto id = table.find(target);
                if(id != table.end()) {
                    if(id->second > temp.size()/2)res++;
                }
            }
        }
        return res;
    }
};
/*


*/