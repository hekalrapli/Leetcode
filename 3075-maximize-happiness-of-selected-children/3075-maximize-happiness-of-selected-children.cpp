class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long total = 0;
        int j = 0 ;
        for(int i = 0; i < k; i++) {
            if(i != 0) {
                happiness[i] = happiness[i] - j <= 0 ? 0 : happiness[i]-j;
                if(happiness[i] == 0) return total;
            }
            total += happiness[i];
            j++;
        }
        return total;

    }
};