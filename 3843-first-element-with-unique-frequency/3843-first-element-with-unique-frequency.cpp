class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
        }
        unordered_map<int,int> freqCount;
        for(auto x : table) {
            freqCount[x.second]++;
        }

            for(auto x : nums) {
                if(freqCount[table[x]] == 1) {
                    return x;
                }
            }
            return -1;
        

     
      
    }
};