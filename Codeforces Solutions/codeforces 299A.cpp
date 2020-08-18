#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,ara[100010];
    cin>>n;
    set<int> S;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        S.insert(ara[i]);
    }
    int g=ara[1];
    for(int i=2;i<=n;i++) {
        g=__gcd(g,ara[i]);
    }
    if(S.find(g)!=S.end()) {
        cout<<g<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
