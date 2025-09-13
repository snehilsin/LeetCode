class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if ( i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);
        if (x_par != y_par){
            if (rank[x_par] > rank[y_par]){
                parent[y_par] = x_par;
            } else if (rank[y_par] > rank[x_par]){
                parent[x_par] = y_par;
            } else {
                parent[x_par] = y_par;
                rank[y_par]++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for (auto &edge : connections){
            Union(edge[0], edge[1]);
        }

        int comp = 0;
        for (int i = 0; i < n; i++){
            if (find(i) == i) comp++;
        }
        return comp -1;
    }
};