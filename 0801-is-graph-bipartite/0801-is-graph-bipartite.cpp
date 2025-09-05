class Solution {
public:
   bool dfs(int node, vector<int> &color, int currColor, vector<vector<int>> &graph){
    color[node] = currColor;

    for (auto it : graph[node]){
        if (color[it] == -1){
            color[it] = 1- color[node];
            if (dfs(it, color, color[it], graph) == false){
                return false;
            }
        } else if (color[it] == currColor){
            return false;
        }
    }
    return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++){
            if (color[i] == -1){
                if (dfs(i, color, 0,graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};