class Solution {
public:
    string frequencySort(string s) {
        map<char,int> arr;
for(int i = 0; i < s.size(); i++) {
    arr[s[i]]++;
}
string result = "";

int maks = INT_MIN;
char temp;
while(!arr.empty()) {
  for(const auto& x : arr) {
    if(x.second > maks) {
      maks = x.second;
      temp = x.first;
    }
  }
    while(maks > 0) {
      result += temp;
      maks--;
    }
    
    arr.erase(temp);

}
    return result;
    }
};