#include<bits/stdc++.h>
using namespace std;

struct compete {
    int prob,pen;

    compete () {}
    compete (int _prob,int _pen) {
        prob=_prob, pen=_pen;
    }
    bool operator<(const compete &q) const {
        if(prob==q.prob) return (pen<q.pen);
        return (prob>q.prob);
    }
};

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    vector<compete> V;
    for(int i=1;i<=n;i++) {
        int s,p;
        cin>>s>>p;
        V.push_back(compete(s,p));
    }
    sort(V.begin(),V.end());
    k--;
    compete X=V[k];
    int ans=0;
    for(int i=0;i<V.size();i++) {
        if(X.prob==V[i].prob&&X.pen==V[i].pen) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

