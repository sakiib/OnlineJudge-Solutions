#include<bits/stdc++.h>
using namespace std;

struct team{
    int p,v,t;
}T[10000];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>T[i].p>>T[i].v>>T[i].t;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tot=0;
        if(T[i].p==1) tot++;
        if(T[i].v==1) tot++;
        if(T[i].t==1) tot++;
        if(tot>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
