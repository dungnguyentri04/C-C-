//
//  main.cpp
//  program9
//
//  Created by Macbook on 30/05/2024.
// bai 4 de cuoi ky

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n,k;
float maxx=0;
int a[maxT],sum[maxT];

float tbc(int i,int j){
    int tong=sum[j]-sum[i-1];
    return (float) tong / (j-i+1);
}

void process(){
    for (int i=1;i<=n-k+1;i++){
        for (int j=i+k-1;j<=n;j++){
            if (maxx<tbc(i,j)) maxx=tbc(i, j);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    sum[0]=0;
    process();
    printf("%.5f",maxx);
    return 0;
}
