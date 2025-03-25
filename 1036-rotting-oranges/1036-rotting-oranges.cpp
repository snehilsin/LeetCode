class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for ( int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                } else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int min = 0;
        while (!q.empty() && fresh > 0){
            int size = q.size();
            for ( int i = 0; i < size; i++){
                auto[x, y] = q.front(); q.pop();
                for (auto [dx, dy] : dir){
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        --fresh;
                    }
                }
            }
            ++min;
        }
        return fresh == 0 ? min : -1;
    }
};