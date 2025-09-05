class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<pair<int, int>> dir = {{-1,1}, {0,1}, {1,1}, {1, 0}, {1, -1}, {0,-1}, {-1, -1}, {-1, 0}};

        queue<vector<int>> q;
        q.push({0, 0, 1});
        vector<vector<bool>> vis(n, vector<bool> (n , false));

        vis[0][0] = true;
        while (!q.empty()){
            vector<int> t = q.front();
            q.pop();

            if (t[0] == n-1 && t[1] == n-1) return t[2];
            for (auto[dx, dy] : dir){
                int nx = t[0] + dx;
                int ny = t[1] + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] ==0){
                    vis[nx][ny] = true;
                    q.push({nx, ny, t[2] + 1});
                }
            }
        }
        return -1;
    }
};