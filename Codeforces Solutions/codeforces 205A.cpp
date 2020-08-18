#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
map<LL,LL> M;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    LL mx=INT_MAX;
    int idx;
    for(int i=1;i<=n;i++) {
        LL num;
        cin>>num;
        M[num]++;
        if(num<mx) {
            mx=num; idx=i;
        }
    }
    if(M[mx]>1) cout<<"Still Rozdil"<<endl;
    else cout<<idx<<endl;
    return 0;
}
