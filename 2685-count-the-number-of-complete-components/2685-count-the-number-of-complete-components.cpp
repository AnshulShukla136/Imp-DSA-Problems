class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<bool>& vis, int node, int &node_count, int &edge_count) {
        vis[node] = true;
        node_count++;
        edge_count += adj[node].size(); // Add the degree of the current node
        
        for(auto &neighbor : adj[node]) {
            if(!vis[neighbor]) {
                dfs(adj, vis, neighbor, node_count, edge_count);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }

        int complete_components = 0;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int node_count = 0;
                int edge_count = 0;
                
                dfs(adj, vis, i, node_count, edge_count);
                
                // In a complete graph, sum of degrees == V * (V - 1)
                if(edge_count == node_count * (node_count - 1)) {
                    complete_components++;
                }
            }
        }
        return complete_components;
    }
};