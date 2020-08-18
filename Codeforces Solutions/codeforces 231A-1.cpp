#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    while(n--){
        int a,b,c,tot=0;
        cin>>a>>b>>c;
        if(a==1) tot++;
        if(b==1) tot++;
        if(c==1) tot++;
        if(tot>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
