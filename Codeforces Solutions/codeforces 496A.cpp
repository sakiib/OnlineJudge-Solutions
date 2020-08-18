#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    int ind=2;
    vector<int> V;
    int mx,mn=1000000;
    while(ind<n) {
        mx=-1;
        V.clear();
        for(int i=1;i<=n;i++) {
            if(i!=ind) V.push_back(ara[i]);
        }
        for(int i=0;i<V.size()-1;i++) {
            mx=max(V[i+1]-V[i],mx);
        }
        cerr<<mx<<endl;
        mn=min(mx,mn);
        ind++;
    }
    cout<<mn<<endl;
    return 0;
}
