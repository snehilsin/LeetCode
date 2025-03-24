/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // During BFS, when we visit a node, we clone it (if not already cloned) and store the mapping from the original node to its clone. Then, we proceed to clone its neighbors and establish the corresponding links in the cloned graph.

        //Mapping: Use an unordered_map<Node*, Node*> (named vis in the code) to record each original node and its corresponding cloned node.

        if ( node == NULL) return NULL;
        queue<Node*> q;
        q.push(node);

        unordered_map<Node*, Node*> vis;
        Node* curr = new Node(node->val);
        vis[node] = curr;

        while (!q.empty()){
            Node* NODE = q.front(); q.pop();

            for (Node* neigh : NODE->neighbors){
                if (vis.find(neigh) == vis.end()){
                    Node* nc = new Node(neigh->val);
                    q.push(neigh);
                    vis[neigh] = nc;
                }
                vis[NODE]->neighbors.push_back(vis[neigh]);
            }
        }
        return curr;
    }
};