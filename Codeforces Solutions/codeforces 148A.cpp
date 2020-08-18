#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    bool ara[100001];
    memset(ara,false,sizeof(ara));
    for(int i=k;i<=d;i+=k){
        if(!ara[i]){
            ara[i]=true;
        }
    }
    for(int i=l;i<=d;i+=l){
        if(!ara[i]){
            ara[i]=true;
        }
    }
    for(int i=m;i<=d;i+=m){
        if(!ara[i]){
            ara[i]=true;
        }
    }
    for(int i=n;i<=d;i+=n){
        if(!ara[i]){
            ara[i]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=d;i++){
        if(ara[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
