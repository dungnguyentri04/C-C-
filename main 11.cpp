//
//  main.cpp
//  program1
//
////  Created by Macbook on 29/05/2024.
////
//Count solution to an integer linear equation

#include "/Users/macbook/Desktop/C++/stdc++.h"
using namespace std;
int a[1000];
int n,m;
int dem=0;

bool check(int i,int f){
    if (i==n){
        if (f==0)dem+=1;
        return false;
    }
    return true;
}

void myFuntion(int i,int f){
    if (check(i, f)){
        for (int j=0;j<=f/a[i];j++){
            myFuntion(i+1,f-a[i]*j);
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    myFuntion(0, m);
    cout<<dem;
    return 0;
}
