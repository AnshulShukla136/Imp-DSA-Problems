//ADJACENCY MATRIX
#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={0};
    arr[0][1]=1;
    arr[1][2]=1;
    arr[2][0]=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++ ){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}      */

//ADJACENCY LIST

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adj;

    void addEdge(int u,int v,bool direction){
        //direction == 0 --> undirected
        //direction == 1 --> directed

        adj[u].push_back(v);        //create an edje from u to v
        if(direction==0){
            adj[v].push_back(u);                  //u ki value par v ko push karna  hi h par agar undirected h to ulta bhi karna h 
        }
    }
    void printList(){
        for(auto i:adj){
            cout<<i.first<< "-->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

     int m;
    cout<<"Enter number of edges: ";
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printList();
    return 0;
}
//In above graph we can use template to make it generic 


                                            //BFS traversal  also level order
//we can alo use set in place of list if answer is in sorted order
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
void prepareAdjList( unordered_map<int,list<int>>& adjList,vector<pair<int ,int>>& edges){
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first;                   //undirected and disconnected graph
            int v=edges[i].second;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
}
void bfs(unordered_map<int,list<int>>& adjList,unordered_map<int,bool>& visited,vector<int>& ans,int node){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();

            //store frontNode into ans
            ans.push_back(frontNode);

            //traverse all neighbours of frontNode
            for(auto i:adjList[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;

                }
            }

        }
}

vector<int>bfs(int vertex,vector<pair<int ,int>>edges){
    unordered_map<int,list<int>>adjList;                    //we can also make vector in place of list
    vector<int>ans;
    unordered_map<int,bool>visited;
    prepareAdjList(adjList,edges);
    for(int i=0;i<vertex;i++){                      //concept for disconnected graphs 
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}



        //DFS Depth first search

void dfs( int node,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adj,vector<int >& component){
    //ans store
    component.push_back(node);
    //mark visited 
    visited[node]=true;
    //har connected node ke lie recursive call
    for(auto i:adj[node]){
        if(!visited[node]){
            dfs(node,visited,adj,component);
        }
    }
}
vector<vector<int>>depthfirstsearch(int V,vector<vector<int>>& edges){
        //prepare adjList
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>ans;
        unordered_map<int,bool>visited;

        //for all nodes call dfs , if not visited
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>component;
                dfs(i,visited,adj,component);
                ans.push_back(component);   
            }
        }
        return ans;

}

//Cycle detection by bfs undirected graph

//https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?interviewProblemRedirection=true&search=cycle%20dete

#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicBFS(int src,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adj){
    unordered_map<int ,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto i: adj[front]){
            if(visited[i]==true && i != parent[front]){       //main logic if visited is already true and front uska parent nhi h then cycle present
                    return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i]=1;
                parent[i]=front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //to handle disconneced compponents
        unordered_map<int,bool>visited;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                bool ans=isCyclicBFS(i,visited,adj);
                if(ans==1){
                    return "Yes";
                }
            }
        }
        return "No";
}

vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));