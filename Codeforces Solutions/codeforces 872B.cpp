#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int ara[N];
vector<int> V;
int mx;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        V.push_back(ara[i]);
    }
    sort(V.begin(),V.end());
    mx=V[V.size()-1];
    if(k==1) {
        cout<<V[0]<<endl;
        return 0;
    }
    if(k==2) {
        cout<<max(ara[1],ara[n])<<endl;
        return 0;
    }
    cout<<mx<<endl;
    return 0;
}
