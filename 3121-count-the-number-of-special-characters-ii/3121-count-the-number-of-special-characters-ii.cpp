class Solution {
public:
    int numberOfSpecialChars(string word) {
        int total = 0;
        unordered_map<char, vector<int>> low;
        unordered_map<char, vector<int>> up;
        for(int i = 0; i < word.size(); i++) {
            int ascii = int(word[i]);
            if(ascii >= 97 && ascii <= 122) {
                low[word[i]].push_back(i);
            }else {
                up[word[i]].push_back(i);

            }
        }
        for(auto x : low) {
            bool check = true;
            int ascii = int(x.first);
            int i = 0;
            int j = 0;
            vector<int> temp = x.second;
            vector<int> temp2;
            if(up.contains(char(ascii)-32)) {
                temp2 = up.at(char(ascii)-32);
            }
            while(i < temp.size() && j < temp2.size()) {
                if(temp[i] > temp2[j]) {
                    check = false;
                    break;
                }
                i++;
            }
            if(check && temp2.size() != 0) {
           
                total++;
            }
        }
        // for(auto x : low) {
        //     cout << x.first << " : ";
        //     for(auto y : x.second) cout << y << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
        // for(auto x : up) {
        //     cout << x.first << " : ";
        //     for(auto y : x.second) cout << y << " ";
        //     cout << "\n";
        // }
        return total;
    }
};