class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();
        int dx[] = { 0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int ny = c + dy[i];
                if (nr >=  0 && nr < n && ny >= 0 && ny < m && grid[nr][ny] == '1' && !vis[nr][ny]){
                 vis[nr][ny] = 1;
                 q.push({nr, ny});   
                }
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        // 1, 1, 1, 0, 0
        // 1, 1, 0, 0, 1
        // 0, 0, 1, 0, 1

        // bfs --> no of bfs calls = no of islands

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};