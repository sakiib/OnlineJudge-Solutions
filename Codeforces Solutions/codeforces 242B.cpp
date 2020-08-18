#include<bits/stdc++.h>
using namespace std;

const int inf=(int)(1e9+5);

int main(int argc,char const *argv[]) {
    int n,x,y;
    cin>>n;
    int mn=inf,mx=-inf;
    vector<pair<int,int> > V[100001];
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        mn=min(mn,x);
        mx=max(mx,y);
        V[i].push_back({x,y});
    }
    vector<pair<int,int> > :: iterator it;
    for(int i=0;i<n;i++) {
        for(it=V[i].begin();it!=V[i].end();it++) {
            if(it->first==mn&&it->second==mx) {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
