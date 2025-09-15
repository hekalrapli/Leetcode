class Solution {
public:

    bool isEmpty(vector<int> &nums) {
    bool check = true;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) check = false;
    }
    return check;
}
    vector<vector<int>> findMatrix(vector<int>& nums) {
         vector<vector<int>> result;
    
    while(isEmpty(nums) == false) {
        unordered_map<int,int> hash;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(hash[nums[i]] == 0 && nums[i] != 0) {
                temp.push_back(nums[i]);
                hash[nums[i]]++;
                nums[i] = 0;
            }
        }
        result.push_back(temp);
    }
        return result;
    }
};