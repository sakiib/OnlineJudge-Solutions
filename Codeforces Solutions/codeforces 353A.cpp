#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    pair<int,int> P[1000];
    int l=0,r=0;
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
        l+=P[i].first; r+=P[i].second;
    }
    if(l%2==0&&r%2==0) {
        cout<<0<<endl;
        return 0;
    }
    int ans=0;
    if(l%2==1&&r%2==1) {
        for(int i=1;i<=n;i++) {
            if(P[i].first%2==1&&P[i].second%2==0) {
                ans++; break;
            }
            else if(P[i].first%2==0&&P[i].second%2==1) {
                ans++; break;
            }
        }
        if(ans!=0) {
        cout<<ans<<endl;
        return 0;
        }
    }
    //cout<<ans<<endl;
    cout<<-1<<endl;
    return 0;
}
