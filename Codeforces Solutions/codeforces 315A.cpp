#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    pair<int,int> P[105];
    map<int,bool> M;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
        if(P[i].first!=P[i].second) M[P[i].second]=true;
    }
    int cnt=0;
    bool done=false;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i!=j&&P[i].first==P[j].second){
                done=true; break;
            }
        }
        if(!done) {
            cnt++;
        }
        done=false;
    }
    cout<<cnt<<endl;
    return 0;
}
