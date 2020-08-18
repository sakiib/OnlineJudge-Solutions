#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    vector<int> V[5];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=6;j++) {
            int val;
            cin>>val;
            V[i].push_back(val);
        }
    }
    vector<int> ans;
    for(int i=1;i<=999;i++) {
        ans.push_back(i);
    }
    bool done=false;
    for(int i=1;i<=999;i++) {
        int make=0;
        for(int j=1;j<=n;j++) {
            for(int k=0;k<V[j].size();k++) {

            }
        }
    }
    return 0;
}

