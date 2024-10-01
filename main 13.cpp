//
//  main.cpp
//  program3
//
//  Created by Macbook on 29/05/2024.
//Disjoint Segments

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;

int n;
int a[maxT],b[maxT],c[maxT];

int main(int argc, const char * argv[]) {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
        c[i]=1;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (b[j]<a[i]&&c[i]<c[j]+1) c[i] = c[j]+1;
        }
    }
    int maxS = 0;
    for (int i=0;i<n;i++) if (c[i]>maxS) maxS = c[i];
    cout<<maxS;
    return 0;
}
