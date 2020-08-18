#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > V;
map<int,int> M;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int k=n*(n-1)/2-1;
    for(int i=1;i<=k;i++) {
        int a,b;
        cin>>a>>b;
        M[a]++,M[b]++;
    }
    set<int> S;
    for(auto x:M) {
        if(x.second<(n-1)) {
            S.insert(x.first);
        }
    }
    for(auto x:S) cout<<x<<" ";
    return 0;
}
