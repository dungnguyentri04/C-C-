//
//  main.cpp
//  nhap3
//
//  Created by Macbook on 11/07/2024.
// bai 3ck ttud codejav

#include <iostream>
#include <vector>
#include <algorithm>
#define maxT 10000
using namespace std;

int n,m,result=1e9;
int a[maxT][maxT];
int di[3]={1,0,1};
int dj[3]={0,1,1};

int check(int p,int q){
    if (a[p][q]==0) return 0;
    if (p>n||q>m) return 0;
    return 1;
}

void sollution(int money){
    if (money<result) result=money;
}

void dfs(int i,int j,int money){
    if (i==n&&j==m) {
        sollution(money);
        cout<<i<<" "<<j<<" | "<<money<<" | "<<result<<endl;
    }
    else{
        cout<<i<<" "<<j<<" | "<<money<<" | "<<result<<endl;
        for (int v=0;v<=2;v++){
            if (check(i+di[v],j+dj[v])){
                dfs(i+di[v],j+dj[v],money+a[i+di[v]][j+dj[v]]);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) cin>>a[i][j];
    }
    dfs(1,1,a[1][1]);
    cout<<result<<endl;
    return 0;
}
