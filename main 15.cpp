//
//  main.cpp
//  program5
//
//  Created by Macbook on 30/05/2024.
//Truy tìm kho báu

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n;
long long result[maxT];
struct toado{
    int x;
    int y;
    int value;
};

bool compareByX(toado td1,toado td2){
    if (td1.x!=td2.x)
    return td1.x<td2.x;
    return td1.y<td2.y;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int x,y,value;
    vector<toado> toados;
    for (int i=0;i<n;i++){
        cin>>x>>y>>value;
        toados.push_back({x,y,value});
    }
    sort(toados.begin(), toados.end(), compareByX);
    for (int i=0;i<n;i++){
        result[i] = toados[i].value;
        for (int j=0;j<i;j++){
            if (toados[j].y<=toados[i].y&&result[i]<result[j]+toados[i].value) result[i]=result[j]+toados[i].value;
        }
    }
    long long maxkhobau = 0;
    for (int i=0;i<n;i++) if (result[i]>maxkhobau) maxkhobau = result[i];
    cout<<maxkhobau;
    return 0;
}
