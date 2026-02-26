class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string,int> menu;
        map<int,int> table;
        vector<vector<string>> res;
        vector<string> menu_names;
        menu_names.push_back("Table");
        int total_menu = 0;
        for(int i = 0; i < orders.size(); i++) {
            if(menu[orders[i][2]] == 0) {
                menu[orders[i][2]]++;

            }
            if(table[stoi(orders[i][1])] == 0 ) table[stoi(orders[i][1])]++;
         
        }
        int i =0;
        for(auto x : menu) {
            i++;
            menu[x.first]= i;
            menu_names.push_back(x.first);
        } 
        res.push_back(menu_names);
        for(auto x : table) {
            vector<int> temp(menu_names.size(),0);
            temp[0] = x.first;
            for(int i = 0; i < orders.size(); i++) {
                    if(orders[i][1] == to_string(temp[0])) {
                        temp[menu[orders[i][2]]]++;
                    }
            }
            vector<string> new_temp;
            for(int i = 0; i< temp.size(); i++) {
                new_temp.push_back(to_string(temp[i]));
            }
            res.push_back(new_temp);
        }
   
        
        return res;
        
    }
};