//
//  main.cpp
//  program14
//
//  Created by Macbook on 31/05/2024.
// de cuoi ky 2

#include "/Users/macbook/Desktop/C++/stdc++.h"
using namespace std;
struct dataT{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};
vector<dataT> v;
int total_money=0;
int result = 0;
int maxx=0;
map <string, int> total_from_acc;
void input(){
    string fr_acc,to_acc,time,atm;
    int money;
    do {
        cin>>fr_acc;
        if (fr_acc=="#") break;
        cin>>to_acc>>money>>time>>atm;
        v.push_back({fr_acc,to_acc,money,time,atm});
        total_money+=money;
        total_from_acc[fr_acc]+=money;
    } while(true);
}

void process_chutrinh(string acc,string fr_acc,size_t k,int n,int i){
    if (i<=n){
        for (size_t j=k+1;j<v.size();j++){
            if (v[j].from_account==fr_acc) {
                if (i==n){
                    if (v[j].to_account==acc) result=1;
                }
                else process_chutrinh(acc, v[i].to_account, j, n, i+1);
            }
        }
    }
    
}

int max_money(string time1,string time2){
    for (size_t i=0;i<v.size();i++){
        if (time1<=v[i].time_point&&v[i].time_point<=time2){
            if (maxx<v[i].money) maxx=v[i].money;
        }
    }
    return maxx;
}
int main(int argc, const char * argv[]) {
    input();
//    cout<<total_money;
//    string acc_ct;
//    int n;
//    cin>>acc_ct>>n;
//    process_chutrinh(acc_ct, acc_ct, 0, n, 1);
//    cout<<result;
//    string from_acc;
//    cin>>from_acc;
//    cout<<total_from_acc[from_acc];
    string time1,time2;
    cin>>time1>>time2;
    cout<<max_money(time1, time2);
    
    return 0;
}
