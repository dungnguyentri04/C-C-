//
//  main.cpp
//  nhap2
//
//  Created by Macbook on 10/07/2024.
// bài 2đề ck codejav


#include "/Users/macbook/Desktop/C++/stdc++.h"

#define maxT 1000000
using namespace std;
int n,year,sum=0,countT=0,countK=0;
int a[maxT];
int appear[maxT];

int gt(int p){
    int result = 1;
    for (int i=1;i<=p;i++) result=result*i;
    return result;
}

int check(int v){
    return !appear[v];
}
void sollution(){
    if (sum>=year) countK+=1;
}

void process(int t){
    for (int v=1;v<=n;v++){
        if (check(v)){
            appear[v]=1;
            sum+=a[v];
            if (t==1) sollution();
            else process(t-1);
            appear[v]=0;
            sum-=a[v];
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        appear[i]=0;
    }
    cin>>year;
    for (int k=1;k<=n;k++){
        countK=0;
        process(k);
        cout<<countK<<endl;
        countT+=countK/gt(k);
    }
    cout<<countT<<endl;
    return 0;
}
