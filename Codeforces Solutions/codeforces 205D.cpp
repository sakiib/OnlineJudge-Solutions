#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

struct col {
    LL f,b;
    col () {}
    col(LL _f,LL _b) {
        f=_f, b=_b;
    }
} card[100010];

map<LL,LL> fir,sec;
vector<pair<LL,LL> > V;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    bool done=false;
    LL need=ceil(n*1.0/2);
    for(int i=1;i<=n;i++) {
        cin>>card[i].f>>card[i].b;
        fir[card[i].f]++; sec[card[i].b]++;
        if(fir[card[i].f]>=need) done=true;
        if(card[i].f==card[i].b) sec[card[i].b]--;
    }
    if(done) {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) {
        V.push_back({fir[card[i].f],i});
    }

    sort(V.rbegin(),V.rend());
    LL mn=INT_MAX;
    for(auto x: V) {
        LL k=x.first;
        if(k+sec[card[x.second].b]>=need) {
            //cout<<card[x.second].b<<endl;
            //cout<<sec[card[x.second].b]<<endl;
            mn=min(mn,sec[card[x.second].b]);
        }
    }
    if(mn==INT_MAX) cout<<-1<<endl;
    else cout<<mn<<endl;
    return 0;
}
