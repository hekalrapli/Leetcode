class Solution {
public:
    bool check(vector<int> arr) {
    if(arr.size() == 1) return true;
    int diff = arr[1] - arr[0];
    for(int i = 2 ;i < arr.size(); i++ ) {
        if(arr[i] - arr[i-1] != diff) return false;
    }
    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
         vector<bool> result;

    for(int i = 0; i  < l.size(); i++) {
        vector<int> temp;
        int left = l[i];
        int right = r[i];
        for(int j = left; j <= right; j++) {
            temp.push_back(nums[j]);
        }
        sort(temp.begin(),temp.end());
        result.push_back( check(temp));

    }
    return result;
        
    }
};