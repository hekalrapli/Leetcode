class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,int> table;
        vector<vector<int>> res;
        for(int i = 0; i < groupSizes.size(); i++) {
            table[groupSizes[i]]++;
        }
        for(auto x : table)  {
            int cnt = (x.second/x.first);
            while(cnt--) {
                vector<int> temp(x.first);
                int j = 0;
                for(int i = 0 ; i < groupSizes.size(); i++) {
                    if(groupSizes[i] == x.first && j < temp.size()) {
                        temp[j] = i;
                        groupSizes[i] = 0;
                        j++;
                    }
                }
                res.push_back(temp);
            }

        }
     
        return res;
    }
};