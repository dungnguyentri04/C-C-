//
//  main.cpp
//  make_equal_again
//
//  Created by Macbook on 01/03/2024.
//


//link : https://codeforces.com/problemset/problem/1931/C
#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;

int process(int a[],int n){
    int i=0,j=n-1;
    while (a[i]==a[i+1]) {
        i+=1;
    }
    while (a[j]==a[j-1]) {
        j-=1;
    }
    if (n-i-1>j) return j;
    else return n-i-1;
}

int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    int save[test];
    for (int t=0;t<test;t++){
        int n;cin>>n;
        int a[n],i=0,j=n-1;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        if (a[i]==a[j]){
            int k=a[i];
            while ((a[i]==k||a[j]==k)&&(i<j)) {
                if (a[i]==k) i+=1;
                if (a[j]==k) j-=1;
            }
            if (i==j&&a[i]==k) save[t]=0;
            else save[t]=j-i+1;
        }
        else {
            save[t] = process(a, n);
        }
    }
    for (int x:save) cout<<x<<endl;
    return 0;
}

