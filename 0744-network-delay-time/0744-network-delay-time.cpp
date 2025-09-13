class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adj --> node : neigh, time
        // pq --> time, node

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        vector<pair<int, int>> adj[n+1];

        for (auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }


        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;

            pq.pop();

            for (auto &it : adj[node]){
                int neigh = it.first;
                int t = it.second;

                if (dist[neigh] > t + time){
                    dist[neigh] = t + time;
                    pq.push({t+time, neigh});
                }
            }
        }

        int mx = INT_MIN;
        for (int i = 1; i < dist.size(); i++){
            if (dist[i] == 1e9) return -1;
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};