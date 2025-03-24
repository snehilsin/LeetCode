class Solution {
public:
    /*void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis){
        vis[node] = 1;
        for (int nbr = 0; nbr < isConnected.size(); nbr++){
            if (isConnected[node][nbr] == 1 && !vis[nbr]){
                dfs(nbr, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // DFS

        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                dfs(i, isConnected, vis);
                provinces++;
            }
        }
        return provinces;
    }*/
    void bfs(int start, vector<vector<int>> &isConnected, vector<int> &vis){
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (int i = 0; i < isConnected.size(); i++){
                if (isConnected[node][i] == 1 && !vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected){
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                bfs(i, isConnected, vis);
                provinces++;
            }
        }
        return provinces;
    }
};