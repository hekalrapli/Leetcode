class Solution {
public:
    int numSub(string s) {
      const int mods = 1000000007;
        long long total = 0;
        long long curr = 0;
        for(int i = 0 ; i  < s.length(); i++) {
            if(s[i] == '1' ) {
                curr++;
            }else if(s[i] == '0' ){
                total += ((curr + 1) * curr) / 2;
                curr = 0;
            }
               
            
        }
        
        total += ((curr + 1) * curr) / 2;
        return total % mods;
    }
    
};