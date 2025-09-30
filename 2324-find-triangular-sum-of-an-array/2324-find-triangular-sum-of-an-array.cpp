class Solution {
public:
    int triangularSum(vector<int>& nums) {

    vector<int> temp = nums;
    vector<int> result;
    while(temp.size() != 1) {
        for(int i = 0; i < temp.size()-1; i++ ) {
            result.push_back((temp[i] + temp[i+1]) % 10);
        }
        temp = result;
 
      
        result.clear();
    }
    return temp[0];
    }
};