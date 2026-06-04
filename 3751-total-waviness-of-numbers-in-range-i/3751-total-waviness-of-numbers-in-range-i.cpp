class Solution {
public:

    int solve(string s) {
        int total = 0;
        for(int i = 1; i < s.size()-1; i++) {
            int middle = s[i] - '0';
            int left = s[i-1] - '0';
            int right = s[i+1] - '0';

            if( (middle > left && middle > right) || (middle < left && middle < right)) total++;
        }
        return total;
    }
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for(int i = num1 ;i <= num2; i++) {
            int res = solve(to_string(i));
            total += res;
  
        }
        return total;
    }
};


/*
1561
*/