class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowels;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'A') {
            vowels.push_back(s[i]);
            s[i] = ' ';
        }
        else if(s[i] == 'i' || s[i] == 'I') {
            vowels.push_back(s[i]);
            s[i] = ' ';
        }
        else if(s[i] == 'u' || s[i] == 'U') {
            vowels.push_back(s[i]);
            s[i] = ' ';
        }
        else if(s[i] == 'e' || s[i] == 'E') {
            vowels.push_back(s[i]);
            s[i] = ' ';
        }
        else if(s[i] == 'o' || s[i] == 'O') {
            vowels.push_back(s[i]);
            s[i] = ' ';
        }
    }

    sort(vowels.begin(),vowels.end());
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            s[i] = vowels[0];
            vowels.erase(vowels.begin());

        }
    }
    return s;
        
    }
};