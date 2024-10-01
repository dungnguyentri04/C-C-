//
//  main.cpp
//  matrix_shortest
//
//  Created by Macbook on 05/03/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;
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
        if ((f == 0|| s == 0 || f == n-1 || s == m-1)){
            result = level;
            break;
        }
        a[f][s] = 1;
        q.pop();
        int move[] = {-1,0,0,-1,1,0,0,1};
        for (int i=0;i<8;i+=2){
            int x = f+move[i],y = s+move[i+1];
            if (!a[x][y]) q.push(make_pair(make_pair(x,y),level+1));
        }
    }
    cout<<result<<endl;
}

int main(int argc, const char * argv[]) {
    cin>>n>>m>>r>>c;
    //input matrix
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cin >> a[i][j];
    }
    bfs();
    
    return 0;
}
