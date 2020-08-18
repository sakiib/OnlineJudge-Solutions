#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> A(200010),B(200010);
    int ans[200010];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    vector<pair<int,int> > V;
    for(int i=0;i<n;i++) {
        cin>>B[i];
        V.push_back({B[i],i});
    }
    sort(A.rbegin(),A.rend());
    sort(V.begin(),V.end());
    int j=0;
    for(int i=0;i<V.size();i++) {
        ans[V[i].second]=A[j++];
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<< " ";
    }
    return 0;
}


