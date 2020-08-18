#include<bits/stdc++.h>
using namespace std;

int ara[100];

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+m+1);
    int mn=1000000;
    for(int i=1;i<=(m-n+1);i++) {
        vector<int> V;
        V.clear();
        for(int j=i;j<=n+i-1;j++) {
            V.push_back(ara[j]);
        }
        int ans=0;
        for(int i=1;i<V.size();i++) {
            ans+=(V[i]-V[i-1]);
            //cout<<V[i]<<" ";
        }
        //cout<<endl;
        mn=min(mn,ans);
    }
    cout<<mn<<endl;
    return 0;
}
