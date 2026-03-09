class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
         string temp = "";
         vector<string>arr;
         string res = "/";
        for(int i = 1; i < path.size(); i++) {
            if(path[i] == '/' && i != 0) {
                if( temp != ".."&&temp != "." && temp != ""  ) {
                st.push(temp);
                }
                if(temp == "..") {
                        if(!st.empty()) {
                            st.pop();
                        }
                    }
                    temp = "";
            }else {
                temp += path[i];
            }
        }

 
        if(  temp != ".." && temp != ".") {
         st.push(temp);
        }else {
            if(!st.empty() && temp == "..") {
            st.pop();

            }
        }
        while(!st.empty()) {

            arr.push_back(st.top());
            st.pop();
        }
        for(int i = arr.size()-1; i >= 0; i-- ) {
            res += arr[i];
            if(i != 0 && arr[i] != "") {
                res += "/";
            }
        }
        if(res[res.size()-1] == '/' && res.size() != 1) {
            res.pop_back();
        }
        return res;
    }
};
