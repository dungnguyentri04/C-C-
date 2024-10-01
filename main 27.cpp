//
//  main.cpp
//  nhap
//
//  Created by Macbook on 09/07/2024.
//CBUS

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 100
using namespace std;
int route = 1e9;
int a[maxT][maxT];
int n,k,q=0;
bool appear[2*maxT+1];
int check(int v){
    if (appear[v]) return 0;
    if (v<=n){
        if (q>=k) return 0;
    }
    if (v>n) return appear[v-n];
    return 1;
}

void process(int last,int t,int distance){
    for (int v=1;v<2*n+1;v++){
        if (check(v)){
            appear[v]=1;
            distance+=a[last][v];
            if (v<=n) q++;else q--;
            if (t==2*n){
                if (distance+a[v][0]<route) route = distance +a[v][0];
            }
            else process(v,t+1,distance);
            appear[v]=0;
            distance-=a[last][v];
            if (v<=n) q--;else q++;
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=0;i<2*n+1;i++){
        for (int j=0;j<2*n+1;j++) cin>>a[i][j];
        appear[i] = false;
        }
    process(0,1,0);
    cout<<route<<endl;
    return 0;
}
