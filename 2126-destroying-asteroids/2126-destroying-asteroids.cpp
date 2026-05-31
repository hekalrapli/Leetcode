class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long temp = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i = 0; i < asteroids.size(); i++) {
            if(temp >= asteroids[i]) {
                temp += asteroids[i];
            }else {
                return false;
            }
        }
        return true;
    }
};