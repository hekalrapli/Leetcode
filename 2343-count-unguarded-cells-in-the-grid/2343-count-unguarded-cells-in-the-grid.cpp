class Solution {
public:
    void count(vector<vector<int>> &cells, int x, int y, int m, int n, int &total,vector<vector<bool>> &guarded) {

    // right
    for(int j = y+1; j < n; j++) {
        if(cells[x][j] == 1 || cells[x][j] == 2) {
            j = n;
        }else if(guarded[x][j] == 0) {
            total++;
            guarded[x][j] = 1;
        }
    }
    // Left 
        for(int j = y-1; j >= 0; j--) {
        if(cells[x][j] == 1 || cells[x][j] == 2 ) {
            j = -1;
        }else if(guarded[x][j] == 0) {
            total++;
            guarded[x][j] = 1;
        }
    }

    // Up
          for(int i = x-1; i >= 0; i--) {
        if(cells[i][y] == 1 || cells[i][y] == 2) {
            i = -1;
        }else if(guarded[i][y] == 0) {
            total++;
            guarded[i][y] = 1;
        }
    }
    // Down
          for(int i = x+1; i < m; i++) {
        if(cells[i][y] == 1 || cells[i][y] == 2) {
            i = m;
        }else if(guarded[i][y] == 0) {
            total++;
            guarded[i][y] = 1;
        }
    }
    
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> cells(m, vector<int>(n,0));
        vector<vector<bool>> guarded(m, vector<bool>(n,0));
        int w = walls.size();
int g = guards.size();

for(int i = 0; i < walls.size() ; i++) {
    cells[walls[i][0]][walls[i][1]] = 1;
}

for(int i = 0; i < guards.size() ; i++) {
        cells[guards[i][0]][guards[i][1]] = 2;
}

int total = 0;
for(int i = 0; i < guards.size() ; i++) {
    count(cells,guards[i][0],guards[i][1],m,n,total,guarded);
}
    return m * n - total - g - w;
    }
};