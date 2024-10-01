//
//  main.cpp
//  program13
//
//  Created by Macbook on 31/05/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"
using namespace std;
int n,m,r,c;
int matrix[1000][1000];
struct toado{
    int x;
    int y;
    int level;
};

void bfs(){
    int result = -1;
    queue<toado> q;
    q.push({r,c,1});
    while (!q.empty()) {
        toado u=q.front();
        int f=u.x,s=u.y;
        if (f==1||f==n||s==1||s==m){
            result = u.level;
            break;
        }
        matrix[f][s]=1;
        q.pop();
        int move[] = {-1,0,0,-1,1,0,0,1};
        for (int i=0;i<8;i+=2){
            int x = f+move[i],y = s+move[i+1];
            if (!matrix[x][y]) q.push({x,y,u.level+1});
        }
    }
    cout<<result;
}
int main(int argc, const char * argv[]) {
    cin>>n>>m>>r>>c;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cin>>matrix[i][j];
    }
    bfs();
    return 0;
}
