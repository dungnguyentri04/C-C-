//
//  main.cpp
//  dfs
//
//  Created by Macbook on 05/03/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;

const int MaxN = 1 + 1e5;
bool mark[MaxN];
vector<int> adj[MaxN];

void dfs(int u){
    cout<< u <<" ";
    mark[u] = 1;
    for (int v:adj[u]){
        if (!mark[v]) dfs(v);
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
    dfs(1);
    return 0;
}
