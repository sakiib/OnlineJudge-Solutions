#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    pair<int,int> P[105];
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        int left=P[i].second-P[i].first;
        if(left>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
