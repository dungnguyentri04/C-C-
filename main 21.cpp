//
//  main.cpp
//  program11
//
//  Created by Macbook on 31/05/2024.
// bai 2 cuoi ky

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n;
int a[maxT],save[maxT];
int main(int argc, const char * argv[]) {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        save[i]=1;
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (a[j]+1==a[i]&&save[i]<save[j]+1) save[i]=save[j]+1;
        }
    }
    int maxx=save[0];
    for (int i=1;i<n;i++) if (save[i]>maxx) maxx=save[i];
    cout<<maxx;
    return 0;
}
