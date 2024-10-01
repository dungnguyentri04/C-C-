//
//  main.cpp
//  program10
//
//  Created by Macbook on 31/05/2024.
// bai 1 de cuoi ki

#include "/Users/macbook/Desktop/C++/stdc++.h"
using namespace std;
vector<int> v1,v2;
int t,countT;
int result[1000];

int main(int argc, const char * argv[]) {
    int x,n=0,m=0;
    cin>>t;
    for (int test=0;test<t;test++){
        countT=0;
        cin>>n;
        for (int j=0;j<n;j++) {
            cin>>x;
            v1.push_back(x);
        }
        cin>>m;
        for (int j=0;j<m;j++) {
            cin>>x;
            v2.push_back(x);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int i=0,j=0;
        for (;;){
            if (i==n||j==m) break;
            if (v1[i]<v2[j]) i+=1;
            else if (v1[i]>v2[j]) j+=1;
            else {
                countT+=1;
                i+=1;
                j+=1;
            }
        }
        result[test]=countT;
    }
    for (int test=0;test<t;test++) cout<<result[test];
    return 0;
}
