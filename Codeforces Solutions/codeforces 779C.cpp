#include<bits/stdc++.h>
using namespace std;

int a[200010],b[200010];
vector<pair<int,pair<int,int>> > V;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++) {
        int dif=a[i]-b[i];
        V.push_back(make_pair(dif,make_pair(a[i],b[i])));
    }
    sort(V.begin(),V.end());
    /*for(int i=0;i<V.size();i++) {
        int f=V[i].first;
        pair<int,int> P=V[i].second;
        cout<<f<<" "<<P.first<<" "<<P.second<<endl;
    }*/
    int ans=0;
    for(int i=0;i<V.size();i++) {
        pair<int,int> P=V[i].second;
        if(i<k) {
            ans+=P.first;
        }
        else ans+=min(P.first,P.second);
    }
    cout<<ans<<endl;
    return 0;
}
