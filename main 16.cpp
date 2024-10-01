//
//  main.cpp
//  program6
//
//  Created by Macbook on 30/05/2024.
//bai 3 đề chiến gửi

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n;
int a[maxT];

int main(int argc, const char * argv[]) {
    vector<int> v;
    int x,m;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>x;
        v.push_back(x);
    }
    cin>>m;
    sort(v.begin(), v.end());
    for (int i=0;i<n;i++){
        a[i] = v[i];
        for (int j=0;j<i;j++) {
            if (a[i]<a[j]+v[i]&&a[j]+v[i]<m) a[i]=a[j]+v[i];
        }
    }
    int maxx = 0;
    for (int i=0;i<n;i++) if (a[i]>maxx) maxx = a[i];
    cout<<m-maxx;
    
    return 0;
}
