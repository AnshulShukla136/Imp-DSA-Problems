                                                    //Topological Sort
#include <bits/stdc++.h> 
void topoSort(unordered_map<int,vector<int>>&adj, vector<bool>&vis,int ele,stack<int>&st){
    vis[ele]=true;
    for(int neigh:adj[ele]){
        if(!vis[neigh]){
            topoSort(adj,vis,neigh,st);
        }
    }
    st.push(ele);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    int n=edges.size();
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool>vis(V,false);

    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            topoSort(adj,vis,i,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}                                                     
                                                    
                                                    
                                                    
                                                    //Kahn's Algorithm TopoSort
//find Indegree of all the nodes
//if 0 indegree of any node then push into queue
//now use while loop bfs and inside it, when we traverse a node we will decrease indegree of that node's child by 1
//again if any node's indegree becomes 1 then push it into queue



#include <bits/stdc++.h>
using namespace std;
vector<int>kahnTopo(int V,vector<vector<int>>&edges){
        //create adj list
    vector<vector<int>>adj(V);
        
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

                        //Shortest path in Directed Acyclic Graph(DAG) Better time O(V+E) than dijktra O(V+E)logV.

//step 1.make adj list of int and pair<int,int> where pair shows value and weight
//step 2.make topological sort stack
//make distance array pahle se INT_MAX rakhdo then src ko 0 then check jis node par h ustak aane ki dis+jispar jana h uski dis agar kam h
//uss node pr jane ki distance se then update then last me distance array print krdo INT_MAX ki jagah -1 krdo 

#include <bits/stdc++.h>
void topoSort(unordered_map<int,list<pair<int,int>>>&adj,unordered_map<int,bool>&vis,int ele,stack<int>&st){
    vis[ele]=true;

    for(auto neigh:adj[ele]){
        int val=neigh.first;
        if(!vis[val]){
            topoSort(adj,vis,val,st);
        }
    }
    st.push(ele);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    int k=edges.size();
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<k;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        adj[u].push_back(make_pair(v,w));
    }
    //topological sorting
    unordered_map<int,bool>vis;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(adj,vis,i,st);
        }
    }

    int src=0;          //source node which is 0 for this question
    vector<int>dis(n);

    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }

    dis[src]=0;         //to reach 0 we need 0 distance
    
    while(!st.empty()){             //step 3./

        int top=st.top();
        st.pop();
        if(dis[top]!=INT_MAX){
            for(auto &i:adj[top]){
                int v=i.first;
                int w=i.second;
                if(dis[top]+w < dis[v]){
                    dis[v]=dis[top]+w;
                }
            }
        }
    }
    for(auto &num:dis){
        if(num==INT_MAX){
            num=-1;
        }
    }
    return dis;
}

                                            //Dijkstra Algorithm


#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &edges, int V, int ed, int src) {
    int k=edges.size();
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<k;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dis(V,INT_MAX);

    set<pair<int,int>>st;

    dis[src]=0;
    st.insert({0,src});

    while(!st.empty()){

        auto top = *(st.begin());     //give smallest value

        int topDis=top.first;
        int topNode=top.second;

        st.erase(st.begin());       //remove that top element

        for(auto neigh:adj[topNode]){
            if(topDis+neigh.second < dis[neigh.first]){

                auto record=st.find(make_pair(dis[neigh.first],neigh.first));

                if(record!=st.end()){       //if already exist in set then erase 
                    st.erase(record);
                }
                dis[neigh.first]=topDis+neigh.second;

                st.insert({dis[neigh.first],neigh.first});

            }
        }
    }
    return dis;
}



                                            //Prim's Algorithm
                                https://www.naukri.com/code360/problems/prim-s-mst_1095633
//Minimum Spanning Tree - If we can convert a graph into a tree such that the tree formed has n nodes and n-1 edges with every node is
//reachable to any other node 



                                        //Kruskal algorithm
                                https://www.naukri.com/code360/problems/minimum-spanning-tree_631769
//to find minimum spanning tree using disjoint union set 
//sort edges basis of weight 
//if not connected u and v or we can say no same global parent then join them and count weight so because of this we will 
//connect graph according to lowest weight

#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
int findParent(vector<int>& parent,int node){
    if(parent[node]==node) return node;
    return parent[node] = findParent(parent,parent[node]);      //path compression
}

void unionSet(int u,int v,vector<int>& parent,vector<int>& rankv){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rankv[u] < rankv[v]){
        parent[u] = v;
    }
    else if(rankv[v] < rankv[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rankv[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){

    vector<int> parent(n);
    vector<int> rankv(n,0);

    for(int i=0;i<n;i++) parent[i]=i;

    sort(edges.begin(),edges.end(),cmp);

    int minWeight = 0;

    for(int i=0;i<edges.size();i++){

        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            minWeight += wt;
            unionSet(u,v,parent,rankv);
        }
    }

    return minWeight;
}



                                            //Kosaraju Algoritm 
                        https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
//to find strongly connected components

//we will traverse from the back edge,  which is dependent so use topological sort 
//Transpose graph, means reverse all the edges direction



                                        //Bellman ford Algorithm
                            https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0
    
//To detect negative cycle and to find shortest path when negative weights are there
//when only positive weights then try to use dijkstra because of better TC
//run edge relaxation condition n-1 times to get ans
// after that run it one more time if it gets updated then a negative cycle is present otherwise return ans

