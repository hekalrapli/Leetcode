class Solution {
public:

    void invert(string &s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }

  
    char findKthBit(int n, int k) {
        string s = "0";

        for(int i = 1; i < n; i++) {
            string temp = s;
            invert(temp);
            reverse(temp.begin(),temp.end());
            s += '1' + temp;
        }

      
        return s[k-1];
    }
};