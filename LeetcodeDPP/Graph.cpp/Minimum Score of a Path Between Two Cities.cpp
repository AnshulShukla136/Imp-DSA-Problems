class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &i:roads){
            int u=i[0];
            int v=i[1];
            int w=i[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        queue<int>q;
        vector<bool>vis(n,false);
        q.push(1);
        vis[1]=true;
        int ans=INT_MAX;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto & neigh:adj[curr]){
                int val=neigh.first;
                int w=neigh.second;
                ans=min(w,ans);
                if(!vis[val]){
                    q.push(val);
                    vis[val]=true;
                }
            }
        }
        return ans;
    }
};