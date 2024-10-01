//
//  main.cpp
//  program4
//
//  Created by Macbook on 29/05/2024.
//

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n;
int countT = 0;
int main(int argc, const char * argv[]) {
    int a[maxT];
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        for (int j=0;j<i;j++){
            if (a[j]>a[i]) countT+=1;
        }
    }
    cout<<countT;

    return 0;
}
