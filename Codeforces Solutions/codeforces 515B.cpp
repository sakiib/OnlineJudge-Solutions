#include<bits/stdc++.h>
using namespace std;

int hb[1000]={0},hg[1000]={0};

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    int b,g;
    cin>>b;
    for(int i=1;i<=b;i++) {
        int k;
        cin>>k;
        hb[k]=1;
    }
    cin>>g;
    for(int i=1;i<=g;i++) {
        int k;
        cin>>k;
        hg[k]=1;
    }
    for(int i=0;i<=10000;i++) {
        int a=(i%n);
        int b=(i%m);
        if(hb[a]==1) hg[b]=1;
        if(hg[b]==1) hb[a]=1;
    }
    bool boys=true;
    bool girls=true;
    for(int i=0;i<n;i++) {
        if(hb[i]==0) {boys=false; break;}
    }
    for(int i=0;i<m;i++) {
        if(hg[i]==0) {girls=false; break;}
    }
    if(boys&&girls) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
