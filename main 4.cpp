//
//  main.cpp
//  bfs
//
//  Created by Macbook on 05/03/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;

const int MaxN = 1 + 1e5;
bool mark[MaxN];
vector<int> adj[MaxN];

void bfs(){
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        mark[u] = 1;
        cout << u <<" ";
        q.pop();
        for (int x:adj[u]){
            if (!mark[x]) q.push(x);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    return 0;
}
