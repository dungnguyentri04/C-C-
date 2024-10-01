//
//  main.cpp
//  program7
//
//  Created by Macbook on 30/05/2024.
// bai 1 chien gui

#include "/Users/macbook/Desktop/C++/stdc++.h"
#define maxT 1000000
using namespace std;
int n,q,countT = 0;
int a[maxT],save[3];
int ck[maxT];

void check(){
    int result = save[0]+save[1]+save[2];
    if (result == q) {
        cout<<save[0]<<" "<<save[1]<<""<<save[2]<<"\n";
        countT += 1;
    }
}
void myFution(int i){
    if (i==3){
        check();
    }
    else{
        for (int j=0;j<n;j++){
            if (!ck[j]){
                ck[j]=1;
                save[i] = a[j];
                myFution(i+1);
                ck[j]=0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>q;
    for (int i=0;i<n;i++) {
        ck[i] = 0;
        cin>>a[i];
    }
    myFution(0);
    cout<<countT;
    return 0;
}
