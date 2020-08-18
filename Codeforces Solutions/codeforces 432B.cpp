#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int a[100010],b[100010];
    map<int,int> H,W;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        H[a[i]]++; W[b[i]]++;
    }
    /*for(auto&x: H) {
        cout<<x.first<< " " <<x.second<<endl;
    }
    for(auto&y : W) {
        cout<<y.first<< " " <<y.second<<endl;
    }*/
    int tot=(n-1);

    for(int i=1;i<=n;i++) {
        int home=tot; int away=tot;
        home+=H[b[i]];
        away-=H[b[i]];
        //away-=(H[b[i]]-1);
        cout<<home<< " "<<away<<endl;
    }
    return 0;
}
