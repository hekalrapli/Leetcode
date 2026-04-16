class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> table;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            table[nums[i]].push_back(i);
        }
        for(auto x : queries) {
            int el = nums[x];
            if(table[el].size() == 1) {
                res.push_back(-1);
            }else {
                int start = 0;
                int end = table[el].size()-1;
                int target = x;
                const vector<int>& arr = table[el];
                int temp;
                int nearest;
                while(start <= end) {
                    int mid = (start+end)/2;

                    if(target == arr[mid]) {
                        temp = mid;
                        break;
                    }else if(target < arr[mid]) {
                        end = mid-1;
                    }else {
                        start = mid+1;
                    }
                }
                if(temp == 0) {
                     if(arr[temp+1] -x < x + nums.size() - arr[arr.size()-1]) {
                        nearest = arr[temp+1];
                    }else {
                        nearest = arr[arr.size()-1];
                    }
                }else if(temp == table[el].size()-1) {
                    if(x - arr[temp-1] < arr[0] + nums.size() - x) {
                        nearest = arr[temp-1];
                    }else {
                        nearest = arr[0];
                    }
                }else {
                    if(x - arr[temp-1] < arr[temp+1] -x ) {
                        nearest = arr[temp-1];
                    }else {
                        nearest = arr[temp+1];
                    }
                }
                if(abs(x - nearest) > nums.size()/2) {
                    if(x > nearest) {
                    res.push_back(nearest + nums.size() - x);
                    }else {
                    res.push_back(x + nums.size() - nearest);
                    }
                }else {
                    res.push_back(abs(x-nearest));
                }

            }

        }
  
        
        return res;
    }
};

/*

[0,9,1,4,8,7,1]
n = 7
idx = 6 & 2
7-6+1
*/