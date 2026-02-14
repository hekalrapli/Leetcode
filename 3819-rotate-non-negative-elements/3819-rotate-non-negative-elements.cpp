class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
     map<int,int> idx_neg;
    vector<int> pos_val;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) idx_neg[i]++;
        else pos_val.push_back(nums[i]);
    }
    vector<int> res(pos_val.size(), 0);
    
    
       int n = pos_val.size();
       if(n != 0) {
         k = k % n;
       }
    
    for(int i = 0; i < pos_val.size(); i++) {
        int idx = abs(i-k + n) % pos_val.size();
         res[idx] = pos_val[i];


    }
    vector<int> new_res(nums.size(),0);
    int i = 0;
    while(i < nums.size()) {
        if(idx_neg[i] > 0) {
            new_res[i] = (nums[i]);
        }
        i++;
    }
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(new_res[i] == 0) {
            new_res[i] = res[j];
            j++;
        }
    }
    return new_res;

    }
};