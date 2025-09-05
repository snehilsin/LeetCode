class Disjoint{
    vector<int> parent;
    vector<int> rank;
    public:
        Disjoint(int n){
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int find(int i){
            if (i == parent[i]){
                return i;
            }
            return parent[i] = find(parent[i]);
        }

        void Union(int x, int y){
            int x_par = find(x);
            int y_par = find(y);

            if (x_par == y_par){
                return;
            }

            if (rank[x_par] > rank[y_par]){
                parent[y_par] = x_par;
            } else if (rank[x_par] < rank[y_par]){
                parent[x_par] = y_par;
            } else {
                parent[x_par] = y_par;
                rank[y_par]++;
            }
        }

        bool isSameComponent(int u, int v){
            return find(u) == find(v);
        }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Disjoint Ds(26);
        for (auto &e : equations){
            if (e[1] == '='){
                Ds.Union(e[0] - 'a' , e[3] - 'a');
            }
        }

        for (auto &e : equations){
            if (e[1] == '!' && Ds.isSameComponent(e[0]-'a', e[3] -'a')){
                return false;
            }
        }
        return true;
    }
};