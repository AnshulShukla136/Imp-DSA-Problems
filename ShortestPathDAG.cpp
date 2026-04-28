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

