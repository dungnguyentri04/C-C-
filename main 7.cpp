

#include "/Users/macbook/Desktop/C++/stdc++.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int n,test;
    cin>>n;
    int a[n];
    map< pair<int, int>,int> mp;
    long long sum = 0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        mp[make_pair(i, i)] = a[i];
    }
    cin>>test;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++) mp[make_pair(i, j)] = min(mp[make_pair(i, j-1)],a[j]);
    }
    for (int i=0;i<test;i++){
        int x,y;
        cin>>x>>y;
        sum += mp[make_pair(x, y)];
    }
    cout<<sum<<endl;
    return 0;
}
