//
//  main.cpp
//  matrix_shortest
//
//  Created by Macbook on 05/03/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;

bool mark[1001][1001];
vector<pair<int,int>> adj[1001][1001];
int a[1001][1001];
int n,m,r,c,min = 0;
pair<pair<int, int>,int> u;
void bfs(){
    int result = -1;
    queue<pair<pair<int, int>,int>> q;
    q.push(make_pair(make_pair(r-1, c-1),1));
    while (!q.empty()){
        u = q.front();
        int level = u.second;
        int f = u.first.first,s = u.first.second;
//        cout << f << " "<< s << " level: "<<level<<endl;
        mark[f][s] = 1;
        if ((f == 0|| s == 0 || f == n-1 || s == m-1)){
            result = level;
            break;
        }
        q.pop();
        for (pair<int, int> x: adj[f][s]) if (!mark[x.first][x.second]) q.push(make_pair(make_pair(x.first, x.second),level+1));
    }
    cout<<result<<endl;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m>>r>>c;
    //input matrix
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> a[i][j];
            if ( i!=0 && i!=n-1 && j!=0 && j!=m-1){
                adj[i][j].push_back(make_pair(i-1, j));
                adj[i][j].push_back(make_pair(i, j-1));
                adj[i][j].push_back(make_pair(i+1, j));
                adj[i][j].push_back(make_pair(i, j+1));
            }
            mark[i][j] = a[i][j];
        }
    }
    
    bfs();
    
    return 0;
}
