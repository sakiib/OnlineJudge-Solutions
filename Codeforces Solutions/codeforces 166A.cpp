#include<bits/stdc++.h>
using namespace std;

struct compete {
    int prob,pen;
};

bool comp(compete a,compete b) {
    if(a.prob>b.prob) return true;
    else if(a.prob==b.prob) {
        return (a.pen<b.pen);
    }
    else return false;
}

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    vector<compete> V;
    for(int i=1;i<=n;i++) {
        int s,p;
        cin>>s>>p;
        V.push_back({s,p});
    }
    sort(V.begin(),V.end(),comp);
    /*for(int i=0;i<V.size();i++) {
       cout<<V[i].prob<< " " <<V[i].pen<<endl;
    }*/
    k--;
    compete X=V[k];
    //cout<<X.prob<< " " <<X.pen<<endl;
    int ans=0;
    for(int i=0;i<V.size();i++) {
        if(X.prob==V[i].prob&&X.pen==V[i].pen) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
