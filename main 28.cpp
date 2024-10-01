//
//  main.cpp
//  nhap1
//
//  Created by Macbook on 10/07/2024.
//Given a set of segments X = {(a1, b1), . . . , (an, bn)} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect

#include "/Users/macbook/Desktop/C++/stdc++.h"

#define maxT 1000000
using namespace std;

int n;
int result[maxT];
vector<pair<int , int>> list_pair;

int main(int argc, const char * argv[]) {
    cin>>n;
    int x,y;
    for (int i=0;i<n;i++) {
        cin>>x>>y;
        list_pair.push_back(make_pair(x, y));
        result[i]=1;
    }
    sort(list_pair.begin(), list_pair.end());
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (list_pair[j].second<list_pair[i].first&&result[i]<result[j]+1) result[i] = result[j] +1;
        }
    }
    int maxS = 0;
    for (int i=0;i<n;i++) if (result[i]>maxS) maxS = result[i];
    cout<<maxS;
    return 0;
}
