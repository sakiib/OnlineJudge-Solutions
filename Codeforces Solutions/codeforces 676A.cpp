#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[10001],mx=-1,mn=1000000,choto,boro;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        if(ara[i]>mx){
            mx=ara[i];
            boro=i;
        }
        if(ara[i]<mn){
            mn=ara[i];
            choto=i;
        }
    }
    int a=abs(choto-boro);
    int b=abs(boro-1);
    int c=abs(n-boro);
    int d=abs(choto-1);
    int e=abs(n-choto);
    int ans=max(a,max(b,max(c,max(d,e))));
    cout<<ans<<endl;
    return 0;
}
