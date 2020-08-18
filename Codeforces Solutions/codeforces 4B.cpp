#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int d,tot;
    cin>>d>>tot;
    pair<int,int> P[35];
    int mn=0,mx=0;
    for(int i=1;i<=d;i++) {
        cin>>P[i].first>>P[i].second;
        mn+=P[i].first;
        mx+=P[i].second;
    }
    bool found=false;
    if(mn<=tot&&tot<=mx) {
        found=true;
    }
    if(!found) {
        cout<<"NO"<<endl;
        return 0;
    }
    int ans[100];
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=d;i++) {
        ans[i]+=P[i].first;
    }
    int sum=mn;
    bool done=false;
    while(true) {
        for(int i=1;i<=d;i++) {
            if(P[i].first<P[i].second) {
                ans[i]++;
                P[i].first++;
                mn++;
            }
            if(mn==tot){
                done=true;
                break;
            }
        }
        if(done) break;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=d;i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
