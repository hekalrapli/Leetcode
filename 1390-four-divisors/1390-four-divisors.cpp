class Solution {
public:
    int div(int n ) {
        vector<int> arr;
        int total = 0;
        for(int i  = 1; i *i <=n; i++) {
            if(n % i == 0) {
                arr.push_back(i);
                total += i;
                if(i != n / i) {
                arr.push_back(n/i);
                total += n/i;
    
                }

            }
        }
        if(arr.size() == 4) {
            return total;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        
        for(int  i = 0; i < nums.size(); i++) {
            total += div(nums[i]);
        }
        return total;
    }
};