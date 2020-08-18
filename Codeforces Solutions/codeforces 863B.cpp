#include<bits/stdc++.h>
using namespace std;

const int INF=100000000;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    n*=2;
    int ara[100];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+n+1);
    int ans=INF;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            vector<int> V;
            V.clear();
            int tot=0;
            for(int k=1;k<=n;k++) {
                if(k==i||k==j) continue;
                V.push_back(ara[k]);
                cout<<ara[k]<<" ";
            }
            cout<<endl;
            for(int i=1;i<V.size();i+=2) {
               tot+=(V[i]-V[i-1]);
            }
            ans=min(ans,tot);
        }
    }
    cout<<ans<<endl;
    return 0;
}
