class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int> temp;

        for(int i = 0; i < s.size(); i++) {
            if(temp[s[i]] == 0) {
                temp[s[i]]++;
            }
        }
        return temp.size();
    }
};