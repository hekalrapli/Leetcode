class Solution {
public:

    int section_left(vector<int> &nums, int firstLen, int secondLen) {
        vector<int> prefix_sum(nums.size());
        int n = nums.size();
        prefix_sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix_sum[i] += nums[i] + prefix_sum[i-1];
        }
        int left = -1;
        int right = firstLen-1;
        int maks = INT_MIN;
        while(left < n && right < n) {
            int temp;
            if(left != -1) {
             temp = prefix_sum[right] - prefix_sum[left];
            
            }else {
             temp = prefix_sum[right];
            }
       
            int i = right+1;
            int j = i + secondLen-1;
            while(i < n && j < n) {
                int temp2 = prefix_sum[j] - prefix_sum[i-1];
              
                maks = max(maks, temp+temp2);
                i++;
                j++;
            }
     
            left++;
            right++;

        }
        return maks;
    }
    int section_right(vector<int> &nums, int firstLen, int secondLen) {
        vector<int> prefix_sum(nums.size());
        int n = nums.size();
        prefix_sum[n-1] = nums[n-1];
        for(int i = n-2; i >=  0; i--) {
            prefix_sum[i] += nums[i] + prefix_sum[i+1];
        }
        int left = n;
        int right = n-firstLen;
        int maks = INT_MIN;
        while(left >= 0 && right >= 0) {
            int temp;
            if(left != n) {
             temp = prefix_sum[right] - prefix_sum[left];
            
            }else {
             temp = prefix_sum[right];
            }
      
            int i = right-1;
            int j = i - secondLen+1;
            while(i >= 0 && j >= 0) {
                int temp2 = prefix_sum[j] - prefix_sum[i+1];
         
                maks = max(maks, temp+temp2);
                i--;
                j--;
            }
     
            left--;
            right--;

        }
   
        return maks;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        
  
        return max(section_left(nums,firstLen, secondLen),section_right(nums,firstLen, secondLen));
    }
};

/*
1 2 3 4 5 6
1 3 6 10 15 21

[2,1,5,6,0,9,5,0,3,8]
5 + 0+ 3 =8

2 1 5 6  0  9  5  0  3  8
2 3 8 14 14 23 28 28 31 39

14 + 14 = 28,
14 + 14 = 28
14 + 8 = 22
14 + 11 = 25




*/