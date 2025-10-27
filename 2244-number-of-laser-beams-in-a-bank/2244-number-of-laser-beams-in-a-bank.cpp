class Solution {
public:
    bool check(string row) {
    bool temp = false;
    int i = 0;
    while(i < row.size() && !temp) {
            if(row[i] == '1') temp = true;
            i++;
    }
    return temp;
}

int count(string row) {
    int total = 0;
    for(int i = 0; i < row.size(); i++) {
        if(row[i] == '1') total++;
    }
    return total;
}
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
for(int i = 0; i < bank.size(); i++) {
    for(int j = i+1; j < bank.size(); j++) {
        if(check(bank[j])) {
            total += count(bank[i]) * count(bank[j]);
            j = bank.size();
        }
    }
}
return total;
    }
};