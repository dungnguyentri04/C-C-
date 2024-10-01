//
//  main.cpp
//  program2
//
//  Created by Macbook on 29/05/2024.
// Even Subsequence

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n;
int a[maxT];
int main(int argc, const char * argv[]) {
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    int sum[n];
    sum[0] = a[0];
    int result=0;
    for (int i=1;i<n;i++) {
        if (a[i]%2==0) result = max(result, a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
                if ((sum[i]-sum[j])%2==0) result = max(sum[i]-sum[j],result);
            
        }
    }
    cout<<result;
    return 0;
}
