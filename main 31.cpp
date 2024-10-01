//
//  main.cpp
//  nhap4
//
//  Created by Macbook on 11/07/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 100000

using namespace std;
int a[maxT][maxT];
int n,m,result=1e9;
int di[3]={0,1,1};
int dj[3]={1,0,1};
int d[maxT][maxT];

//int check(int i,int j){
//    if (i>n||j>m) return 0;
//    if (a[i][j]==0) return 0;
//    return 1;
//}
//
//void bfs(){
//    queue<pair<int, int>> q;
//    q.push(make_pair(1, 1));
//    d[1][1]=a[1][1];
//    while (!q.empty()) {
//        int i=q.front().first;
//        int j=q.front().second;
//        q.pop();
//        for (int v=0;v<=2;v++){
//            int i1=i+di[v],j1=j+dj[v];
//            if (check(i1,j1)){
//                q.push(make_pair(i1, j1));
//                d[i1][j1]=min(d[i1][j1],d[i][j]+a[i1][j1]);
//            }
//        }
//    }
//}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            d[i][j]=100;
        }
    }
//    bfs();
    cout<<d[n][m]<<endl;
    return 0;
}
