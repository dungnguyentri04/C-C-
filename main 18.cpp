//
//  main.cpp
//  program8
//
//  Created by Macbook on 30/05/2024.
//Gold Mining

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n,L1,L2;
int a[maxT],save[maxT];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>L1>>L2;
    int maxx=0,i,j;
    for (i=0;i<n;i++) cin>>a[i];
    
    for (i=0;i<L1;i++) save[i]=a[i];
    
    for (i=L1;i<L2;i++){
        maxx = save[0];
        for (j=1;j<=i-L1;j++){
            if (maxx<save[j]) maxx = save[j];
        }
        save[i]=a[i]+maxx;
    }
    
    for (i=L2;i<n;i++){
        maxx = save[i-L2];
        for (j=i-L2+1;j<=i-L1;j++){
            if (maxx<save[j]) maxx=save[j];
        }
        save[i] = a[i]+maxx;
    }
    
    for (i=n-L1;i<n;i++){
        if (maxx<save[i]) maxx = save[i];
    }
    
    cout<<maxx;
    
    return 0;
}
