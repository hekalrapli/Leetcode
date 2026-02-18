class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_map<int,int> table;
        vector<string> res;
        for(int i = 0;  i < target.size(); i++) {
            table[target[i]]++;
        }
        for(int i = 1; i <= target[target.size()-1]; i++) {
            if(table[i] > 0 ){
                res.push_back("Push");
            }else {
                res.push_back("Push");
                res.push_back("Pop");
                
            }
        }
        return res;

       

    }
};