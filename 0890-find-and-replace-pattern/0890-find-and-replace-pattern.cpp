class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
 
       
        vector<string> res;
      
        for(auto x : words) {
        unordered_map<char,int> table;
        vector<char> pat_table;
          for(auto x : pattern) {
            table[x]++;
            pat_table.push_back(x);
        }
       
            string str = x;
            unordered_map<char,int> temp;
            vector<char> temp_table;
            for(auto y : str) {
                temp[y]++;
                temp_table.push_back(y);

                
            }
            bool check = true;
            int i = 0;

            while(i < str.size()) {
                if(temp[temp_table[i]] != table[pat_table[i]]) {
                    check = false;
                }else {
                    if(i > 0 && pat_table[i] != pat_table[i-1]) {
                        if(temp_table[i] == temp_table[i-1]) {
                            check = false;
                        }
                    }else if(i > 0 && pat_table[i] == pat_table[i-1]) {
                        if(temp_table[i] != temp_table[i-1]) {
                            check = false;
                        }
                    }
                }
                i++;
            }
            
            if(check)res.push_back(str);
        }
        return res;
    }
};