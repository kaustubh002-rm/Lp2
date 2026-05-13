#include <bits/stdc++.h>
using namespace std;

vector<int>graph[10];
bool visited[10];

void dfs(int node){
    visited[node] = true;
    cout<<node<<" ";

    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(neighbor);
        }
    }
}

void bfs(int start){
    bool vis[10] = {false};
    queue<int>q;
    
    vis[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int neighbor : graph[node]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    //Undirected Graph
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[3].push_back(4);
    graph[4].push_back(3);

    cout<<"DFS : "<<endl;
    dfs(0);

    
    cout<<endl;

    cout<<"BFS : "<<endl;
    bfs(0);
}