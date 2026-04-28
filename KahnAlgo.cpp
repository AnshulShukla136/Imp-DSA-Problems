//find Indegree of all the nodes
//if 0 indegree of any node then push into queue
//now use while loop bfs and inside it, when we traverse a node we will decrease indegree of that node's child by 1
//again if any node's indegree becomes 1 then push it into queue



#include <bits/stdc++.h>
using namespace std;
vector<int>kahnTopo(int V,vector<vector<int>>&edges){
        //create adj list
    vector<vector<int>>adj(V);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(int neigh:adj[i]){
            indegree[neigh]++;
        }
    }
    vector<int>result;

    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        result.push_back(curr);
        for(int neigh:adj[curr]){
            indegree[neigh]--;                      //decrement indegree of all neighbour by 1
            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }
    return result;
}
int main(){
    int V;
    cin>>V;
    vector<vector<int>>edges;       //give an DAG graph
    edges.push_back({5,0});
    edges.push_back({4,0});
    edges.push_back({5,2});
    edges.push_back({4,1});
    edges.push_back({2,3});
    edges.push_back({3,1});

    vector<int>ans=kahnTopo(V,edges);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}